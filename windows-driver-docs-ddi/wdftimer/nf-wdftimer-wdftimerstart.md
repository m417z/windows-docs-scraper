# WdfTimerStart function

## Description

[Applies to KMDF and UMDF]

The **WdfTimerStart** method starts a timer's clock.

## Parameters

### `Timer` [in]

A handle to a framework timer object that was obtained by calling [WdfTimerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimercreate).

### `DueTime` [in]

A time period, in system time units (100-nanosecond intervals). The framework calls the driver's [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function when the specified time period elapses. The time period value can be negative or positive as follows:

* If the value is negative, the time period is relative to the current system time.
* If the value is positive, the time period specifies an absolute time (which is actually relative to January 1, 1601).

> [!WARNING]
> If you set the **UseHighResolutionTimer** member of [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) to **WdfTrue**, you must call **WdfTimerStart** with the *DueTime* parameter set to a negative value. Otherwise, the call causes the system to crash.

Relative times are not affected by any changes to the system time that might occur within the specified time period. Absolute times do reflect system time changes.

The framework provides [time conversion functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcore/) that convert time values into system time units.

## Return value

**WdfTimerStart** returns **TRUE** if the timer object was in the system's timer queue. Otherwise, this method returns **FALSE**. For more information, see the following Remarks section.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Drivers must always call **WdfTimerStart** to start a timer after creating it, regardless of whether the timer is a periodic timer or not.

After a driver calls **WdfTimerStart**, the framework calls the driver's [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function when the time that is specified for the *DueTime* parameter elapses. After this first call, the framework calls the callback function each time that the time period that is specified by the **Period** member of the driver's [WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config) structure elapses.

The expiration of the timer ultimately depends on the granularity of the system clock. The value specified for *DueTime* guarantees that the framework calls the driver's [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function on or after the given *DueTime*. However, **WdfTimerStart** cannot override the granularity of the system clock, whatever the value specified for *DueTime*.

When a driver calls **WdfTimerStart**, its timer object is added to the system's queue of timer objects. If the timer is not a periodic timer, the system removes the timer object from the queue after the timer's "due time" has elapsed. If the timer is a periodic timer, the timer object remains in the queue until the driver calls [WdfTimerStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimerstop).

A driver might call **WdfTimerStart** from its [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function in order to restart a non-periodic timer after it expires.

**WdfTimerStart** returns **TRUE** if the driver has previously called **WdfTimerStart** and the timer object is still in the system's queue because the time period has not elapsed (or because it is a periodic timer). Before **WdfTimerStart** returns **TRUE**, the operating system resets the time period to the value that the driver specified in the new call to **WdfTimerStart**. The framework calls the [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function only after the new time period elapses.

To stop the timer's clock, the driver can call [WdfTimerStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimerstop).

For more information about framework timer objects, see [Using Timers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-timers).

#### Examples

The following code example starts a timer. The framework will call the timer's [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function after 10 milliseconds.

```cpp
BOOLEAN inTimerQueue;

inTimerQueue = WdfTimerStart(
                             timerHandle,
                             WDF_REL_TIMEOUT_IN_MS(10)
                             );
```

## See also

[EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer)

[WDF_TIMER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/ns-wdftimer-_wdf_timer_config)

[WdfTimerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimercreate)

[WdfTimerStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimerstop)