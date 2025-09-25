# WDF_REL_TIMEOUT_IN_MS function

## Description

[Applies to KMDF and UMDF]

The **WDF_REL_TIMEOUT_IN_MS** function converts a specified number of milliseconds to a relative time value.

## Parameters

### `Time` [in]

The number of milliseconds to convert.

## Return value

**WDF_REL_TIMEOUT_IN_MS** returns the relative time value, in system time units (100-nanosecond intervals), that represents the number of milliseconds that *Time* specifies.

## Remarks

A relative time is a time value that is relative to the current system time. For example, if a caller passes a relative time value of five milliseconds to a function that accepts a time-out value, the function will time out five milliseconds after it is called.

#### Examples

The following code example starts a timer. The framework will call the timer's [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function after ten milliseconds.

```cpp
BOOLEAN inTimerQueue;

inTimerQueue = WdfTimerStart(
                             timerHandle,
                             WDF_REL_TIMEOUT_IN_MS(10)
                             );
```

## See also

[WDF_ABS_TIMEOUT_IN_MS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcore/nf-wdfcore-wdf_abs_timeout_in_ms)