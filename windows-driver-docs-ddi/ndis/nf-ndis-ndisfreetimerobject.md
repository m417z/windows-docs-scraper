# NdisFreeTimerObject function

## Description

The
**NdisFreeTimerObject** function frees a timer object that was allocated with the
[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject) function.

## Parameters

### `TimerObject` [in]

A handle to a timer object that NDIS provides when a driver calls the
[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject) function.

## Remarks

To use timer services, an NDIS driver first calls the
[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject) function
to initialize a timer object. Typically,
**NdisAllocateTimerObject** is called when a driver initializes. The driver must call
**NdisFreeTimerObject** to free the timer object when the timer is no longer required.

To cancel a timer, call the
[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject) function.
**NdisCancelTimerObject** dequeues the timer object if it is currently queued.

## See also

[NDIS_TIMER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_timer_characteristics)

[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject)

[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject)