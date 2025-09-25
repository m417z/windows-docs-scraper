# RxPostOneShotTimerRequest function

## Description

**RxPostOneShotTimerRequest** initializes a one-shot timer entry. The passed-in pointer to a worker thread routine is called once when the timer expires.

## Parameters

### `pDeviceObject` [in]

A pointer to the device object to be associated with this timer.

### `pWorkItem` [in]

A pointer to the worker item.

### `Routine` [in]

A pointer to the worker thread routine to call when this timer expires.

### `pContext` [in]

A pointer to the context parameter associated with this timer.

### `TimeInterval` [in]

The time interval, in 100-nanosecond ticks.

## Return value

**RxPostOneShotTimerRequest**
returns STATUS_SUCCESS on success.

If a **NULL** pointer is passed as the *pWorkItem* parameter, this routine causes the system to ASSERT on checked builds.

## See also

[RxCancelTimerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxtimer/nf-rxtimer-rxcanceltimerrequest)

[RxPostRecurrentTimerRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxtimer/nf-rxtimer-rxpostrecurrenttimerrequest)