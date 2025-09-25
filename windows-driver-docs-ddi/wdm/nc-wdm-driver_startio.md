## Description

The *StartIo* routine starts the I/O operation described by an IRP.

## Parameters

### `DeviceObject` [in, out]

Caller-supplied pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This is the device object for the target device, previously created by the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

### `Irp` [in, out]

Caller-supplied pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure that describes the requested I/O operation.

## Remarks

A driver's *StartIo* routine executes in an arbitrary thread context at IRQL = DISPATCH_LEVEL.

The *StartIo* routine is optional. A driver's *StartIo* routine, if supplied, should be named *Xxx***StartIo**, where *Xxx* is a driver-specific prefix. The driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must store the *StartIo* routine's address in **DriverObject->DriverStartIo**. (If no routine is supplied, this pointer must be **NULL**.)

A driver can use [IoSetStartIoAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iosetstartioattributes) to set attributes on when its *StartIo* routine is called.

For detailed information about implementing a driver's *StartIo* routine, see [Writing a StartIo Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-startio-routine).

### Examples

To define a *StartIo* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *StartIo* callback routine that is named `MyStartIo`, use the DRIVER_STARTIO type as shown in this code example:

```cpp
DRIVER_STARTIO MyStartIo;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyStartIo(
    struct _DEVICE_OBJECT  *DeviceObject,
    struct _IRP  *Irp
    )
  {
      // Function body
  }
```

The DRIVER_STARTIO function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the DRIVER_STARTIO function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).