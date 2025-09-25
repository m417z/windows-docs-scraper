# WdfTimerStop function

## Description

[Applies to KMDF and UMDF]

The **WdfTimerStop** method stops a timer's clock.

## Parameters

### `Timer` [in]

A handle to a framework timer object that was obtained by calling [WdfTimerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimercreate).

### `Wait` [in]

**KMDF** A Boolean value that, if **TRUE**, specifies that the framework does not return until all queued calls to the driver's deferred procedure calls (DPCs), including the driver's [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback functions, have executed.

**UMDF** A Boolean value that, if **TRUE**, specifies that the framework does not return until all queued calls to the timer's [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function have executed.

## Return value

**WdfTimerStop** returns **TRUE** if the timer object was in the system's timer queue. Otherwise, this method returns **FALSE**. For more information, see the following Remarks section.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

When a driver calls [WdfTimerStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimerstart), its timer object is added to the system's queue of timer objects. If the timer is not a periodic timer, the system removes the timer object from the queue after the timer's "due time" has elapsed. If the timer is a periodic timer, the timer object remains in the queue until the driver calls **WdfTimerStop**.

For more information about framework timer objects, see [Using Timers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-timers).

**WdfTimerStop** must be called at IRQL = PASSIVE_LEVEL if the *Wait* parameter is **TRUE**. Otherwise, this method must be called at IRQL <= DISPATCH_LEVEL.

Do not call **WdfTimerStop** from inside [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) with the *Wait* parameter set to **TRUE**. Doing so may result in deadlock.

> [!CAUTION]
>Concurrent calls to **WdfTimerStop** on the same timer object will break into the debugger if Verifier is enabled. For more info, see [Using KMDF Verifier](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kmdf-verifier).

#### Examples

The following code example stops a specified timer and waits for all of the driver's queued DPCs to execute.

```cpp
WdfTimerStop(
             timerHandle,
             TRUE
             );
```

## See also

[EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer)

[WdfTimerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimercreate)

[WdfTimerStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimerstart)