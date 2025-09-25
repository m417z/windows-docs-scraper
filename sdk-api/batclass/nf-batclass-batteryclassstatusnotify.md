# BatteryClassStatusNotify function

## Description

**BatteryClassStatusNotify** notifies the battery class driver of changes in battery status.

## Parameters

### `ClassData` [in]

Pointer to a battery class handle previously returned by [BatteryClassInitializeDevice](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassinitializedevice).

## Return value

**BatteryClassStatusNotify** returns STATUS_SUCCESS.

## Remarks

Battery miniclass drivers must call **BatteryClassStatusNotify** whenever any of the following occur:

* The battery goes online or offline.
* The battery's capacity becomes critically low.
* The battery's power state changes; that is, the battery starts or stops charging or discharging.
* The battery's capacity or power state deviates from the criteria set by a previous call to [BatteryMiniSetStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_status_notify_callback).

The battery class driver queues status requests internally. If any such requests are pending when the miniclass driver calls **BatteryClassStatusNotify**, the class driver immediately calls the miniclass driver's [BatteryMiniQueryStatus](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_query_status_callback) routine.

## See also

[BatteryMiniQueryStatus](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_query_status_callback)

[BatteryMiniSetStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_status_notify_callback)