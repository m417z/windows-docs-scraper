# HW_STARTIO callback function

## Description

The Storport driver calls the **HwStorStartIo** routine one time for each incoming I/O request.

## Parameters

### `DeviceExtension`

A pointer to the miniport driver's per HBA storage area.

### `Srb`

A pointer to the SCSI request block to be started.

## Return value

**HwStorStartIo** returns **TRUE** if the request was successfully initiated. Otherwise, it returns **FALSE**.

## Remarks

**HwStorStartIo** initiates an I/O operation. StorPort is designed to use a miniport's private data that is prepared in [**HwStorBuildIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_buildio) and stored in either **DeviceExtension** or **Srb->SrbExtension**. Because **HwStorBuildIo** is called without spin locks, the best driver performance is achieved by preparing as much data as possible in **HwStorBuildIo**.

Storport calls **HwStorStartIo** in the following ways:

* For [storage non-virtual miniport drivers](https://learn.microsoft.com/windows-hardware/drivers/storage/overview-of-storage-virtual-miniport-drivers), depending on the value of **SynchronizationModel** set in [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information), Storport always calls **HwStorStartIo** at the same IRQL and uses an internal spin lock to ensure that I/O requests are initiated sequentially. The IRQL is either DISPATCH_LEVEL (full-duplex mode) or DIRQL (half-duplex mode).

 When handling I/O in half-duplex mode, the **HwStorStartIo** routine does not have to acquire its own spin lock. Also, memory allocation using [**StorPortAllocatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatepool) and mutual exclusion via [**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock) are not allowed in the **HwStorStartIo** routine. In full-duplex mode, **StorPortAllocatePool** and **StorPortAcquireSpinLock** may be used in the **HwStorStartIo** routine.

 If a non-virtual miniport supports the concurrent channels optimization (STOR_PERF_CONCURRENT_CHANNELS set by [**StorPortInitializePerfOpts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeperfopts)), multiple calls to **HwStorStartIo** concurrently are possible. In this case, the miniport will need to ensure that any shared resources are protected by a lock. With this performance optimization, Storport will not acquire the StartIo lock prior to calling **HwStorStartIo** and the miniport must provide its own lock if required.

* For [storage virtual miniport drivers](https://learn.microsoft.com/windows-hardware/drivers/storage/overview-of-storage-virtual-miniport-drivers), Storport calls **HwStorStartIo** at any IRQL <= DISPATCH_LEVEL and does not use an internal spin lock. The **HwStorStartIo** routine can acquire its own spin lock by calling [**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock). Also, calls to [**StorPortAllocatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatepool) are allowed in the **HwStorStartIo** routine of a storage virtual miniport driver.

The SRB is expected to be completed when SCSI status is received. When the Storport driver completes the SRB by calling [**StorPortNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification) with a *NotificationType* of **RequestComplete**, an SRB is expected to return one of the following values in the **SrbStatus** field of the Srb:

* SRB_STATUS_SUCCESS
  * Indicates that the Srb was sent and SCSI status (possibly with data) was returned.
  * Storport returns the data and status to the caller.
  * Miniport action is none, except to complete the request by using [**StorPortNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification) for **RequestComplete**, probably from the [**HwStorDpcRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_dpc_routine).

* SRB_STATUS_BUSY
  * Indicates that there is a temporary problem with sending the Srb (for example, adapter registers or buffers are busy).
  * Storport discards the original Srb extension that **Srb->SrbExtension** points to and issues a new one. Storport sends the original Srb with the newly issued Srb extension in subsequent calls to **HwStorBuildIo** and **HwStorStartIo**. All data in the original Srb extension will be lost.
  * The miniport should not update the Srb's **DataTransferLength**.
  * Because a new Srb extension is issued, the miniport must make sure that it never issues SRB_STATUS_BUSY in the middle of a SCSI transaction. After the transaction is started, it must be completed or canceled. Hardware busy states during the transaction must be handled by the miniport driver.

The name **HwStorStartIo** is a placeholder to describe the miniport routine set in the **HwStartIo** member of [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1) structure. This structure is passed in the *HwInitializationData* parameter of [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The actual prototype of this routine is defined in Storport.h as follows:

```cpp
typedef
BOOLEAN
(*PHW_STARTIO) (
  _In_ PVOID  DeviceExtension,
  _In_ PSCSI_REQUEST_BLOCK  Srb
  );
```

Starting in Windows 8, the *Srb* parameter can point to either [**SCSI_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) or [**STORAGE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block). If the function identifier in the **Function** field of *Srb* is **SRB_FUNCTION_STORAGE_REQUEST_BLOCK**, the SRB is a **STORAGE_REQUEST_BLOCK** request structure.

### Examples

To define a **HwStorStartIo** callback routine, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as shown in the following code example:

To define an **HwStorStartIo** callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

 For example, to define a **HwStorStartIo** callback routine that is named *MyHwStartIo*, use the **HW_STARTIO** type and implement your callback routine as follows:

``` c
HW_STARTIO MyHwStartIo

BOOLEAN
MyHwStartIo (
  _In_ PVOID  DeviceExtension,
  _In_ PSCSI_REQUEST_BLOCK  Srb
  );
  {
      ...
  }
```

The **HW_STARTIO** function type is defined in the **Storport.h** header file. To more accurately identify errors when you run the code analysis tools, be sure to add the ```_Use_decl_annotations_ annotation``` to your function definition. The ```_Use_decl_annotations_ annotation``` ensures that the annotations applied to the **HW_STARTIO** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions Using Function Role Types for Storport Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-storport-drivers). For information about ```_Use_decl_annotations_```, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**HwStorBuildIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_buildio)

[**SCSI_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[**STORAGE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)

[**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize)