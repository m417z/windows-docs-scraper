# WDF_REL_TIMEOUT_IN_US function

## Description

[Applies to KMDF and UMDF]

The **WDF_REL_TIMEOUT_IN_US** function converts a specified number of microseconds to a relative time value.

## Parameters

### `Time` [in]

The number of microseconds to convert.

## Return value

**WDF_REL_TIMEOUT_IN_US** returns the relative time value, in system time units (100-nanosecond intervals), that represents the number of microseconds that *Time* specifies.

## Remarks

A relative time is a time value that is relative to the current system time. For example, if a caller passes a relative time value of five microseconds to a function that accepts a time-out value, the function will time out five microseconds after it is called.

#### Examples

The following code example starts a timer. The framework will call the timer's [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function after one hundred microseconds.

```cpp
BOOLEAN inTimerQueue;

inTimerQueue = WdfTimerStart(
                             timerHandle,
                             WDF_REL_TIMEOUT_IN_US(100)
                             );
```

## See also

[WDF_ABS_TIMEOUT_IN_US](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcore/nf-wdfcore-wdf_abs_timeout_in_us)