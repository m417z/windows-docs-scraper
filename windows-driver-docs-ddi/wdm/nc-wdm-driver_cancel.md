## Description

The *Cancel* routine cancels an I/O operation.

## Parameters

### `DeviceObject` [in, out]

Caller-supplied pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This is the device object for the target device, previously created by the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

### `Irp` [in, out]

Caller-supplied pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure that describes the I/O operation to be canceled.

## Remarks

When a driver or other system component calls [IoCancelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocancelirp), the I/O manager calls the IRP's *Cancel* routine, if one has been registered for the IRP.

To register a *Cancel* routine for an IRP, a driver can use either of the following two methods:

1. A driver that provides a [StartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine and uses the I/O manager-supplied device queue can specify a *Cancel* routine when calling [IoStartPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartpacket).

1. A driver that creates and manages supplemental device queues can register a *Cancel* routine by calling [IoSetCancelRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcancelroutine).

Only one *Cancel* routine can be registered for an IRP at one time.

The I/O manager calls [IoAcquireCancelSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff548196(v=vs.85)) before calling a driver's *Cancel* routine, so the *Cancel* routine must call [IoReleaseCancelSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549550(v=vs.85)) at some point. The routine should not hold the spin lock longer than necessary.

The *Cancel* routine executes in an arbitrary thread context at IRQL = DISPATCH_LEVEL until it calls **IoReleaseCancelSpinLock**, which changes the IRQL to a caller-supplied value. The driver should specify **Irp->CancelIrql** for this value.

The *Cancel* routine must set the I/O status block's **Status** member to STATUS_CANCELLED, and set its **Information** member to zero. The routine must then complete the specified IRP by calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest).

For detailed information about implementing a driver's *Cancel* routine, see [Canceling IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/canceling-irps).

### Examples

To define a *Cancel* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *Cancel* callback routine that is named `MyCancel`, use the DRIVER_CANCEL type as shown in this code example:

```cpp
DRIVER_CANCEL MyCancel;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyCancel(
    struct _DEVICE_OBJECT  *DeviceObject,
    struct _IRP  *Irp
    )
  {
      // Function body
  }
```

The DRIVER_CANCEL function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the DRIVER_CANCEL function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).