# RxPostRecurrentTimerRequest function

## Description

**RxPostRecurrentTimerRequest** initializes a recurrent timer request. The passed in pointer to a worker thread routine is called at regular intervals when the recurrent timer fires based on the input parameters to this routine.

## Parameters

### `pDeviceObject` [in]

A pointer to the device object to be associated with this timer.

### `Routine` [in]

A pointer to the worker thread routine to call when this timer expires.

### `pContext` [in]

A pointer to the context parameter to be associated with this timer.

### `TimeInterval` [in]

The time interval, in 100-nanosecond ticks.

## Return value

**RxPostRecurrentTimerRequest** returns STATUS_SUCCESS on success or one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of non-paged pool memory required by this routine failed. |

## Remarks

A recurrent timer can be canceled by calling **RxCancelTimerRequest**.

## See also

[RxCancelTimerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxtimer/nf-rxtimer-rxcanceltimerrequest)

[RxPostOneShotTimerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxtimer/nf-rxtimer-rxpostoneshottimerrequest)