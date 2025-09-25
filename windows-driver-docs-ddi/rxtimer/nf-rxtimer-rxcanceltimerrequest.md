# RxCancelTimerRequest function

## Description

**RxCancelTimerRequest** cancels a recurrent timer request. The request to be canceled is identified by the worker thread routine and associated context.

## Parameters

### `pDeviceObject` [in]

A pointer to the device object that initialized the timer. This parameter was passed to the **RxPostRecurrentTimerRequest** routine when this recurrent timer was initialized.

### `Routine` [in]

A pointer to the worker thread routine to call when this timer expires. This parameter was passed to the **RxPostRecurrentTimerRequest** routine when this recurrent timer was initialized.

### `pContext` [in]

A pointer to the context parameter that was passed to the **RxPostRecurrentTimerRequest** routine when this timer was initialized.

## Return value

**RxCancelTimerRequest** returns STATUS_SUCCESS on success.

## Remarks

A recurrent timer is initialized by calling [RxPostRecurrentTimerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxtimer/nf-rxtimer-rxpostrecurrenttimerrequest).

If the recurrent timer is not found, this routine will return STATUS_NOT_FOUND.

## See also

[RxPostOneShotTimerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxtimer/nf-rxtimer-rxpostoneshottimerrequest)

[RxPostRecurrentTimerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxtimer/nf-rxtimer-rxpostrecurrenttimerrequest)