# NdisAllocateTimerObject function

## Description

The
**NdisAllocateTimerObject** function allocates and initializes a timer object for use with subsequent
**Ndis*Xxx*** timer functions.

## Parameters

### `NdisHandle` [in]

An NDIS handle that was obtained during caller initialization. For more information about
obtaining NDIS handles, see
[Obtaining Pool Handles](https://learn.microsoft.com/windows-hardware/drivers/network/obtaining-pool-handles).

### `TimerCharacteristics` [in]

A pointer to a caller-supplied
[NDIS_TIMER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_timer_characteristics) structure that specifies the characteristics of the allocated timer
object.

### `pTimerObject` [out]

A pointer to an NDIS timer object handle that NDIS provides to identify the timer object in
subsequent calls to
**Ndis*Xxx*** timer functions.

## Return value

**NdisAllocateTimerObject** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The timer object was allocated successfully. |
| **NDIS_STATUS_RESOURCES** | The allocation failed because of insufficient resources. |
| **NDIS_STATUS_BAD_CHARACTERISTICS** | The allocation failed because the information in the NDIS_TIMER_CHARACTERISTICS structure is invalid. |
| **NDIS_STATUS_FAILURE** | None of the preceding status values apply. |

## Remarks

To use timer services, an NDIS driver first calls the
**NdisAllocateTimerObject** function to initialize a timer object. Typically,
**NdisAllocateTimerObject** is called during driver initialization.

To start a timer, call the
[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject) function. Calls to
**NdisSetTimerObject** insert the timer object in the system timer queue. Only one instance of a
particular timer object can be queued at any given moment.

To cancel a timer, call the
[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject) function.
**NdisCancelTimerObject** dequeues the timer object if it is currently queued.

To free a timer object, you must call the
[NdisFreeTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetimerobject) function.

## See also

[NDIS_TIMER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_timer_characteristics)

[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject)

[NdisFreeTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetimerobject)

[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject)