# EVT_WDF_TIMER callback function

## Description

[Applies to KMDF and UMDF]

The *EvtTimerFunc* event callback function is called when a specified time period has elapsed.

## Parameters

### `Timer` [in]

A handle to a framework timer object that was obtained from a previous call to [WdfTimerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimercreate).

## Remarks

To register an *EvtTimerFunc* callback function and specify the time period that should elapse before the framework calls this function, your driver must call [WdfTimerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimercreate).

In KMDF versions prior to version 1.9, the framework implements *EvtTimerFunc* callback functions as deferred procedure calls (DPCs). Therefore, when a time period elapses, the system adds a call to an *EvtTimerFunc* callback function to a DPC queue. The system calls the *EvtTimerFunc* callback function at IRQL = DISPATCH_LEVEL when it reaches the front of the queue and a CPU that is running at IRQL < DISPATCH_LEVEL is available.

In KMDF versions 1.9 and later, by default the framework implements *EvtTimerFunc* callback functions as DPCs. Alternatively, if the driver sets the timer object's execution level to [WdfExecutionLevelPassive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_execution_level), the framework calls the *EvtTimerFunc* callback function from a [work item](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-work-items) at IRQL = PASSIVE_LEVEL.

> [!NOTE]
> If an *EvtTimerFunc* callback function running at PASSIVE_LEVEL calls [**WdfObjectDelete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete), this results in deadlock. Instead, either wait for the parent to delete the timer automatically when the device is removed - or, if you need to delete early, schedule a work item from the timer callback to delete the timer.

Starting in UMDF version 2.0, a UMDF driver's *EvtTimerFunc* callback functions always run at PASSIVE_LEVEL.

For more information about framework timer objects, see [Using Timers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-timers).

## See also

[WdfTimerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimercreate)