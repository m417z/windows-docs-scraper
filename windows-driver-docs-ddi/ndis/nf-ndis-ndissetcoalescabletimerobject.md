# NdisSetCoalescableTimerObject function

## Description

The
**NdisSetCoalescableTimerObject** function sets a timer object that the operating system coordinates with
other timers, typically to reduce power consumption, when the exact expiration of the timer is not
important to driver operation.

## Parameters

### `TimerObject` [in]

A handle to a timer object that NDIS provides when a driver calls the
[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject) function.

### `DueTime` [in]

The absolute or relative time at which the timer will expire. If the value of the
*DueTime* parameter is negative, the expiration time is relative to the current system time.
Otherwise, the expiration time is absolute. The expiration time is expressed in system time units
(100-nanosecond intervals). Absolute expiration times track any changes in the system time; relative
expiration times are not affected by system time changes.

### `MillisecondsPeriod` [in, optional]

The optional periodic time interval, in milliseconds, that elapses between every instance when the
timer fires and the next call to the
*NetTimerCallback* function, unless the timer is canceled. The value of this parameter must be less
than or equal to MAXLONG. This parameter can be set to zero to indicate that the timer is
non-periodic.

### `FunctionContext` [in, optional]

A pointer to a caller-supplied context area that NDIS passes to the associated
*NetTimerCallback* function when a timer fires. If this parameter is **NULL**, NDIS uses the default
value that is specified in the
[NDIS_TIMER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_timer_characteristics) structure.

### `Tolerance` [in, optional]

The tolerance, in milliseconds, between the timer period specified by
*MillisecondsPeriod* and the initial time interval specified by
*DueTime* . A periodic timer will first expire in the time interval between (
*DueTime* -
*Tolerance* ) and (
*DueTime* +
*Tolerance* ). The time interval between two later expirations of a periodic timer will be in the
range of (
*MillisecondsPeriod* -
*Tolerance* ) and (
*MillisecondsPeriod* +
*Tolerance* ).

## Return value

**NdisSetCoalescableTimerObject** returns **TRUE** if the timer object was already in the system timer
queue; otherwise, it returns **FALSE**.

## Remarks

A timer object set by this function operates the same as a timer set by
[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject), with an additional
tolerance value added to the expiration parameter
*DueTime* . The operating system uses this additional tolerance value to adjust the expiration time
of the timer to coincide with the expiration of other software timers. By doing this, the operating
system can reduce power consumption and improve energy efficiency.

**NdisSetTimerObject** operates similarly to
**NdisSetCoalescableTimerObject** when
*Tolerance* is set to zero.

After a driver calls
**NdisSetCoalescableTimerObject**, the timer object is queued until expiration of an interval that is
in the range of (
*DueTime* -
*Tolerance* ) and (
*DueTime* +
*Tolerance* ). After the interval expires, the operating system removes the timer object from the
queue, and the caller-supplied
[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function) function is run one
time at IRQL = DISPATCH_LEVEL as soon as a processor becomes available.

If a nonzero value is specified in the
*MillisecondsPeriod* parameter, the timer object is queued again until an interval in the range of (
*MillisecondsPeriod* -
*Tolerance* ) and (
*MillisecondsPeriod* +
*Tolerance* ) expires. After this interval expires, the timer object is resubmitted to the queue, and
the caller-supplied
*NetTimerCallback* function is run one time at IRQL = DISPATCH_LEVEL as soon as a processor becomes
available.

To use timer coalescing effectively, a caller should specify a
*Tolerance* value of at least 32 milliseconds. This value equals approximately two default system
clock intervals of 15.6 milliseconds. Use a larger
*Tolerance* value if you can do this, such as 100 milliseconds.

We recommend that
*MillisecondsPeriod* and
*Tolerance* be set to multiples of 50 milliseconds. Typical
*MillisecondsPeriod* values are 50, 100, 250, 500, and 1000 milliseconds. Typical
*Tolerance* values are 50, 100, 150, and 250 milliseconds.

Typically, a timer with a large
*MillisecondsPeriod* value can use a proportionally large
*Tolerance* value. For example, a timer with
*MillisecondsPeriod* = 500 milliseconds might use
*Tolerance* = 50 milliseconds. But a timer with
*MillisecondsPeriod* = 10 seconds might use
*Tolerance* = 1 second.

For more information about timer behavior, see
[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex).

To cancel a timer, call the
[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject) function.

## See also

[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex)

[NDIS_TIMER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_timer_characteristics)

[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject)

[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject)

[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject)

[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function)