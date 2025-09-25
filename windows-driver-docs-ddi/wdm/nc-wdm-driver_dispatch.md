# DRIVER_DISPATCH callback function

## Description

The callback routine services various IRPs. For a list of function codes, see Remarks.

## Parameters

### `DeviceObject` [in, out]

Caller-supplied pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This is the device object for the target device, previously created by the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

### `Irp` [in, out]

Caller-supplied pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure that describes the requested I/O operation.

## Return value

If the routine succeeds, it must return STATUS_SUCCESS. Otherwise, it must return one of the error status values defined in Ntstatus.h.

## Remarks

Input parameters for all *Dispatch* routines are supplied in the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure pointed to by *Irp*. Additional parameters are supplied in the driver's associated I/O stack location, which is described by the [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure and can be obtained by calling [IoGetCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentirpstacklocation).

Generally, all *Dispatch* routines execute in an arbitrary thread context at IRQL = PASSIVE_LEVEL, but there are exceptions. For more information, see [Dispatch Routines and IRQLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/dispatch-routines-and-irqls).

For more information about dispatch routines, see [Writing Dispatch Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-dispatch-routines). For more information about IRPs, see [Handling IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-irps).

| IRP | About implementing the callback |
|--|--|
| [IRP_MJ_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-cleanup) | A driver's *DispatchCleanup* routine should be named *Xxx*DispatchCleanup, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchCleanup* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_CLEANUP]. |
| [IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close) | A driver's *DispatchClose* routine should be named ***Xxx*DispatchClose**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchClose* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_CLOSE]. |
| [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) | A driver's *DispatchCreate* routine should be named *Xxx*DispatchCreate, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchCreate* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_CREATE]. |
| [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) or [IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close) | A driver can provide a single *DispatchCreateClose* routine instead of separate *DispatchCreate* and [DispatchClose]() routines.<br><br>A driver's *DispatchCreateClose* routine should be named ***Xxx*DispatchCreateClose**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchCreateClose* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_CREATE] and in *DriverObject*->**MajorFunction**[IRP_MJ_CLOSE]. |
| [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control) | A driver's *DispatchDeviceControl* routine should be named ***Xxx*DispatchDeviceControl**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchDeviceControl* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_DEVICE_CONTROL].<br><br>The system uses the FILE_*XXX* flags in the I/O control code to determine whether the IRP sender has the privileges to send the IRP to the device object. Drivers for Windows Server 2003 and later versions of Windows can use the [IoValidateDeviceIoControlAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iovalidatedeviceiocontrolaccess) routine to perform stricter access checks within *DispatchDeviceControl*. |
| [IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers) | A driver's *DispatchFlushBuffers* routine should be named *Xxx*DispatchFlushBuffers, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchFlushBuffers* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_FLUSH_BUFFERS]. |
| [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control) | A driver's *DispatchInternalDeviceControl* routine should be named ***Xxx*DispatchInternalDeviceControl**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchInternalDeviceControl* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_INTERNAL_DEVICE_CONTROL]. |
| [IRP_MJ_PNP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-pnp) | A driver's *DispatchPnP* routine should be named *Xxx*DispatchPnP, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchPnP* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_PNP]. |
| [IRP_MJ_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-power) | A driver's *DispatchPower* routine should be named ***Xxx*DispatchPower**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchPower* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_POWER]. |
| [IRP_MJ_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-information) | A driver's *DispatchQueryInformation* routine should be named ***Xxx*DispatchQueryInformation**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchQueryInformation* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_QUERY_INFORMATION]. |
| [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) | A driver's *DispatchRead* routine should be named ***Xxx*DispatchRead**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchRead* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_READ]. |
| [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) or [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write) | A driver can provide a single *DispatchReadWrite* routine instead of separate [DispatchRead]() and [DispatchWrite]() routines.<br><br>A driver's *DispatchReadWrite* routine should be named ***Xxx*DispatchReadWrite**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchReadWrite* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_READ] and in *DriverObject*->**MajorFunction**[IRP_MJ_WRITE]. |
| [IRP_MJ_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-information) | A driver's *DispatchSetInformation* routine should be named ***Xxx*DispatchSetInformation**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchSetInformation* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_SET_INFORMATION]. |
| [IRP_MJ_SHUTDOWN](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-shutdown) | A driver's *DispatchShutdown* routine should be named ***Xxx*DispatchShutdown**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchShutdown* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_SHUTDOWN].<br><br>Additionally, in order to receive **IRP_MJ_SHUTDOWN** requests, a driver must call [IoRegisterShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistershutdownnotification) or [IoRegisterLastChanceShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterlastchanceshutdownnotification) to register its *DispatchShutdown* routine with the system. |
| [IRP_MJ_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-system-control) | A driver's *DispatchSystemControl* routine should be named ***Xxx*DispatchSystemControl**, where ***Xxx*** is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchSystemControl* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_SYSTEM_CONTROL]. |
| [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write) | A driver's *DispatchWrite* routine should be named ***Xxx*DispatchWrite**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *DispatchWrite* routine's address in *DriverObject*->**MajorFunction**[IRP_MJ_WRITE]. |

### Examples

To define a callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *DispatchCleanup* callback routine that is named `MyDispatchCleanup`, use the DRIVER_DISPATCH type as shown in this code example:

```cpp
DRIVER_DISPATCH MyDispatchCleanup;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyDispatchCleanup(
    struct _DEVICE_OBJECT  *DeviceObject,
    struct _IRP  *Irp
    )
  {
      // Function body
  }
```

The DRIVER_DISPATCH function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the_Use_decl_annotations_annotation to your function definition. The_Use_decl_annotations_annotation ensures that the annotations that are applied to the DRIVER_DISPATCH function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).