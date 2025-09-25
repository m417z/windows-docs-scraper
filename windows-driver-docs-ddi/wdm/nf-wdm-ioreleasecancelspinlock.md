## Description

The **IoReleaseCancelSpinLock** routine releases the cancel spin lock after the driver has changed the cancelable state of an IRP.

## Parameters

### `Irql`

[in] The IRQL to be restored. The caller obtained this IRQL in the previous call to the [**IoAcquireCancelSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioacquirecancelspinlock) routine.

## Remarks

This routine is a reciprocal to **IoAcquireCancelSpinLock**.

This routine also releases the cancel spin lock from the driver's [*Cancel*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_cancel) routine.

The holder of the cancel spin lock runs at IRQL = DISPATCH\_LEVEL after calling **IoAcquireCancelSpinLock**. **IoReleaseCancelSpinLock** restores the original IRQL of the caller.

## See also

[**IoAcquireCancelSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioacquirecancelspinlock)

[**IoSetCancelRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcancelroutine)