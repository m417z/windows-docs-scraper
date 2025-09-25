## Description

The **IoAcquireCancelSpinLock** routine synchronizes cancelable-state transitions for IRPs in a multiprocessor-safe way.

## Parameters

### `Irql`

[out] Pointer to a variable in which to save the current IRQL for a subsequent call to [**IoReleaseCancelSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleasecancelspinlock). Usually, the *Irql* is saved on the stack as a local variable.

## Remarks

A driver that uses the I/O manager-supplied device queues in the device object must be holding the cancel spin lock whenever it changes the cancelable state of an IRP with [**IoSetCancelRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcancelroutine).

A driver that manages its own IRP queue does not need to hold the cancel spin lock when calling **IoSetCancelRoutine**.

The holder of the cancel spin lock should release it promptly by calling [**IoReleaseCancelSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleasecancelspinlock).

A driver-supplied *Cancel* routine is called with the cancel spin lock held. It must release the cancel spin lock when it has completed the IRP to be canceled.

## See also

[**IoReleaseCancelSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleasecancelspinlock)

[**IoSetCancelRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcancelroutine)