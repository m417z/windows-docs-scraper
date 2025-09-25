# _NDIS_TIMER_CHARACTERISTICS structure

## Description

The NDIS_TIMER_CHARACTERISTICS structure defines characteristics of a one-shot or periodic
timer.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_TIMER_CHARACTERISTICS structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_TIMER_CHARACTERISTICS, the
**Revision** member to NDIS_TIMER_CHARACTERISTICS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_TIMER_CHARACTERISTICS_REVISION_1.

### `AllocationTag`

A string that is delimited by single quotation marks and contains up to four characters, usually
specified in reversed order. You must provide this tag. NDIS uses this tag when it allocates memory for
the timer.

### `TimerFunction`

A pointer to an entry point for a
[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function) function. NDIS calls
this function when a timer fires.

### `FunctionContext`

A pointer to a driver-allocated context area. NDIS passes this pointer to the
*NetTimerCallback* function when a timer fires.

## Remarks

To allocate and initialize a timer object, NDIS drivers call the
[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject) function
and provide an NDIS_TIMER_CHARACTERISTICS structure. The timer does not start until the driver calls the
[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject) function.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject)

[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject)

[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function)