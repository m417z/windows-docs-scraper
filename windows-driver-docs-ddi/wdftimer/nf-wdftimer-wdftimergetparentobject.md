# WdfTimerGetParentObject function

## Description

[Applies to KMDF and UMDF]

The **WdfTimerGetParentObject** method returns a handle to the parent object of a specified framework timer object.

## Parameters

### `Timer` [in]

A handle to a framework timer object that was obtained by calling [WdfTimerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimercreate).

## Return value

**WdfTimerGetParentObject** returns a handle to the framework object that is the specified timer object's parent object.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about framework timer objects, see [Using Timers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-timers).

#### Examples

The following code example shows now an [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback function can obtain a timer object's parent. In this example, the driver previously specified that the timer object's parent is a queue object.

```cpp
VOID
MyEvtTimerFunc(
    IN WDFTIMER  Timer
    )
{
    WDFQUEUE queue;

    queue = WdfTimerGetParentObject(Timer);
...
}
```

## See also

[WdfTimerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nf-wdftimer-wdftimercreate)