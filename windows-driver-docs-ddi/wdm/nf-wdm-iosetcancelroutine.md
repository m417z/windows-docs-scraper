## Description

The **IoSetCancelRoutine** routine sets up a driver-supplied [Cancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_cancel) routine to be called if a given IRP is canceled.

## Parameters

### `Irp` [in]

Pointer to the IRP being put into or removed from a cancelable state.

### `CancelRoutine` [in]

Specifies the entry point of the caller-supplied [Cancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_cancel) routine to be called if the specified IRP is canceled or is **NULL** if the given IRP is being removed from the cancelable state. This routine is declared as follows:

```cpp
VOID
(*PDRIVER_CANCEL)(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    );
```

## Return value

**IoSetCancelRoutine** returns the previous value of *Irp*->**CancelRoutine**. If no *Cancel* routine was previously set, or if IRP cancellation is already in progress, **IoSetCancelRoutine** returns **NULL**.

## Remarks

This routine can disable the *Cancel* routine currently set in an IRP.

A driver must hold the system cancel spin lock when calling this routine if the driver uses the I/O manager-supplied device queue in the device object. The driver runs at IRQL = DISPATCH_LEVEL after calling [IoAcquireCancelSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff548196(v=vs.85)) until it releases the cancel spin lock with [IoReleaseCancelSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549550(v=vs.85)).

If the driver manages its own queues of IRPs, then the driver need not hold the cancel spin lock when calling this routine. **IoSetCancelRoutine** uses an interlocked exchange intrinsic to set the address of the *Cancel* routine as an atomic operation. Reduced usage of the cancel spin lock can improve driver performance and overall system performance.

Driver *Cancel* routines are called at IRQL = DISPATCH_LEVEL with the cancel spin lock held. The *Cancel* routine must release the cancel spin lock before it returns control.

## See also

[IoAcquireCancelSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff548196(v=vs.85))

[IoReleaseCancelSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549550(v=vs.85))