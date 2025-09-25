# HW_BUILDIO callback function

## Description

The **HwStorBuildIo** routine processes the SRB with unsynchronized access to shared system data structures before passing it to [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio).

## Parameters

### `DeviceExtension`

A pointer to the miniport driver's per HBA storage area.

### `Srb`

A pointer to the SCSI request block (SRB) to be processed.

## Return value

**HwStorBuildIo** returns **TRUE** to inform the caller that StorPort should call the [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) routine if StorPort considers the LUN ready to receive I/O. **HwStorBuildIo** returns **FALSE** to inform the caller that the SRB should not be passed to **HwStorStartIo**. In such cases, the miniport driver must complete the SRB by calling [**StorPortNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification) with a notification type of **RequestComplete**. This can be done in **HwStorBuildIo** or elsewhere in the miniport driver, as long as the SRB is completed before the timeout that is specified in the **TimeOutValue** field of the SRB structure.

## Remarks

The name **HwStorBuildIo** is just a placeholder for the miniport function that is pointed to by the **HwBuildIo** member in the [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1) structure. The actual prototype of this routine is defined in *Storport.h* as follows:

```c
typedef
BOOLEAN
HW_BUILDIO (
  _In_ PVOID DeviceExtension,
  _In_ PSCSI_REQUEST_BLOCK  Srb
  );
```

The port driver calls the **HwStorBuildIo** routine at DISPATCH IRQL without holding any spin locks. Because of this, memory allocation using [**StorPortAllocatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatepool) and mutual exclusion via [**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock) are allowed in **HwStorBuildIo**. In a multiprocessor environment, more than one **HwStorBuildIo** can be active at a time, so the miniport driver is required to synchronize access to system resources, which may be in contention if more than one instance of **HwStorBuildIo** is active at any given time.

By completed time-consuming I/O setup activities in **HwStorBuildIo** instead of in [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio), the miniport driver enables greater I/O concurrency and therefore improves I/O throughput. For highest performance, miniport drivers are expected to do as much preprocessing as possible in **HwStorBuildIo** so that it can send requests to the HBA via **HwStorStartIo** in as short amount of time as possible. Preprocessed data and state can be stored in either the *DeviceExtension* or *SrbExtension* structures. Only modifications to unique portions of the *DeviceExtension* must occur since no locks are held. **HwStorBuildIo** and **HwStorStartIo** receive the following Srb function types:

* SRB_FUNCTION_EXECUTE_SCSI: Sends a CDB to the specified bus/target/lun.
  * Srb->DataTransferLength is valid for all Cdbs.
  * Srb->DataBuffer is **NULL** for read and write requests. To access the associated data, either use [**StorPortGetScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetscattergatherlist) (for Dma transfers) or [**StorPortGetSystemAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetsystemaddress) (for program controlled I/O ) to get the Scatter Gather list or the virtual address of the buffer. For other requests, Srb->Databuffer points to the data that is associated with the Srb.
  * Srb->PathId is valid and represents the pathid given to Storport in [**StorPortNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification) (BusChange). Writers of miniport drivers need to use pathid as an index into a table of busses within the miniport.
  * Srb->TargetId and Srb->Lun are valid.

* SRB_FUNCTION_IO_CONTROL: Miniport defined.
  * Srb->DataTransferLength and Srb->DataBuffer are valid if set by the requester.
  * Srb->PathId, Srb->TargetId, and Srb->Lun are all valid.

* SRB_FUNCTION_RESET_LOGICAL_UNIT: Reset the specified logical unit (if the device is capable).
  * Srb->DataTransferLength and Srb->DataBuffer are invalid.
  * Srb->PathId, Srb->TargetId, and Srb->Lun are all valid.

* SRB_FUNCTION_RESET_DEVICE: Reset the specified Scsi Target.
  * Srb->DataTransferLength and Srb->DataBuffer, Srb->Lun are invalid.
  * Srb->PathId and Srb->TargetId are valid.

* SRB_FUNCTION_RESET_BUS: Reset all of the targets on the specified SCSI bus.
  * Only Srb->PathId is valid.

* SRB_FUNCTION_FLUSH: Instructs the miniport driver to flush all cached data.
  * Only performed by the miniport driver if it sets **CachesData** == **TRUE** in the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure.
  * Srb->PathId, Srb->TargetId, and Srb->Lun are all valid.

* SRB_FUNCTION_SHUTDOWN: Instructs the miniport driver to flush all cached data preparatory to shut down.
  * Only performed by the miniport driver if it sets **CachesData** == **TRUE** in the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure.
  * Srb->PathId, Srb->TargetId, and Srb->Lun are all valid.

* SRB_FUNCTION_DUMP_POINTERS: Supplies information needed for the miniport driver to support crash dump and hibernation.
  * This request is sent to a Storport virtual miniport driver that is used to control the disk that holds the crash dump data. Starting with Windows 8, non-virtual miniport drivers can optionally receive this request.
  * Srb->PathId, Srb->TargetId, and Srb->Lun are all valid.

* SRB_FUNCTION_FREE_DUMP_POINTERS: Starting with Windows 8, this request is sent to the miniport to free resources allocated during the SRB_FUNCTION_DUMP_POINTERS request.
  * Srb->PathId, Srb->TargetId, and Srb->Lun are all valid.

Starting in Windows 8, the *Srb* parameter may point to either [**SCSI_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) or [**STORAGE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block). If the function identifier in the **Function** field of *Srb* is **SRB_FUNCTION_STORAGE_REQUEST_BLOCK**, the SRB is a **STORAGE_REQUEST_BLOCK** request structure.

For more information about what you can and cannot do safely in this miniport driver routine, see [Unsynchronized HwStorBuildIo Routine](https://learn.microsoft.com/windows-hardware/drivers/storage/unsynchronized-hwstorbuildio-routine).

### Examples

To define a **HwStorBuildIo** callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

 For example, to define a **HwStorBuildIo** callback routine that is named *MyHwBuildIo*, use the **HW_BUILDIO** type as shown in this code example:

```c
HW_BUILDIO MyHwBuildIo;
```

Then, implement your callback routine as follows:

```c
_Use_decl_annotations_
BOOLEAN
MyHwBuildIo (
  _In_ PVOID  DeviceExtension,
  _In_ PSCSI_REQUEST_BLOCK  Srb
  );
  {
      ...
  }
```

The **HW_BUILDIO** function type is defined in the Storport.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **HW_BUILDIO** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions Using Function Role Types for Storport Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-storport-drivers). For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/cpp/code-quality/annotating-function-behavior).

## See also

[**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio)

[**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information)

[**SCSI_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[**STORAGE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)

[**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock)

[**StorPortAllocatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatepool)

[**StorPortNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification)