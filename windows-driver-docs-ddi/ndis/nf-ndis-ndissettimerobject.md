# NdisSetTimerObject function

## Description

The
**NdisSetTimerObject** function sets a timer object to fire after a specified interval or
periodically.

## Parameters

### `TimerObject` [in]

A handle to a timer object that NDIS provides when a driver calls the
[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject) function.

### `DueTime` [in]

The absolute or relative time at which the timer is to expire. If the value of the
*DueTime* parameter is negative, the expiration time is relative to the current system time.
Otherwise, the expiration time is absolute. The expiration time is expressed in system time units
(100-nanosecond intervals). Absolute expiration times track any changes in the system time; relative
expiration times are not affected by system time changes.

### `MillisecondsPeriod` [in, optional]

The periodic time interval, in milliseconds, that elapses between each time the timer fires and
the next call to the
*NetTimerCallback* function, unless the timer is canceled. The value of this parameter must be less
than or equal to MAXLONG.

### `FunctionContext` [in, optional]

A pointer to a caller-supplied context area that NDIS passes to the associated
*NetTimerCallback* function when a timer fires. If this parameter is **NULL**, NDIS uses the default
value that is specified in the
[NDIS_TIMER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_timer_characteristics) structure.

## Return value

**NdisSetTimerObject** returns **TRUE** if the timer object was already in the system timer queue;
otherwise, it returns **FALSE**.

## Remarks

After a driver calls
**NdisSetTimerObject**, the timer object is queued until the interval that is specified in the
*DueTime* parameter expires. After the interval expires, the timer object is dequeued and the
caller-supplied
[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function) function is run once
at IRQL = DISPATCH_LEVEL as soon as a processor becomes available.

If a nonzero value is specified in the
*MillisecondsPeriod* parameter, the timer object is queued again until the interval that is specified
in
*MillisecondsPeriod* expires. After this interval expires, the timer object is requeued and the
caller-supplied
*NetTimerCallback* function is run once at IRQL = DISPATCH_LEVEL as soon as a processor becomes
available.

**Note** Starting with Windows 7, you can reduce power consumption by calling
[NdisSetCoalescableTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetcoalescabletimerobject) instead of
**NdisSetTimerObject** if exact timer precision is not required.

For more information about timer behavior, see
[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex).

To cancel a timer, call the
[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject) function.

## See also

[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex)

[NDIS_TIMER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_timer_characteristics)

[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject)

[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject)

[NdisSetCoalescableTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetcoalescabletimerobject)

[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function)