# BCLASS_QUERY_STATUS_CALLBACK callback function

## Description

*BatteryMiniQueryStatus* returns status information about the given battery device.

## Parameters

### `Context` [in]

A pointer to the context area allocated by the miniclass driver for the battery device.

### `BatteryTag` [in]

A battery tag value previously returned by *BatteryMiniQueryTag*.

### `BatteryStatus` [out]

A pointer to a [BATTERY_STATUS](https://learn.microsoft.com/previous-versions/ff536290(v=vs.85)) structure in which the miniclass driver returns information.

## Return value

*BatteryMiniQueryStatus* returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The battery designated by *BatteryTag* is currently installed. |
| **STATUS_NO_SUCH_DEVICE** | The battery designated by *BatteryTag* is not present. |

## Remarks

The battery class driver calls *BatteryMiniQueryStatus* to get status information about the battery. The status information includes the battery's power state, capacity, voltage, and the amount of current flowing at the time of the request.

If the miniclass driver does not supply fully functional [BatteryMiniSetStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_status_notify_callback) and [BatteryMiniDisableStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_disable_status_notify_callback) routines, the battery class driver calls *BatteryMiniQueryStatus* at regular but infrequent intervals to poll the battery's status. Otherwise, the class driver calls this routine after the miniclass driver has notified it of a change in battery status.

Before reporting a critically low, discharging battery (BATTERY_DISCHARGING and BATTERY_CRITICAL), the miniclass driver should ensure that the problem is legitimate (rather than a transitory state) and if so, should attempt to solve the problem. Possible solutions might include switching to AC power or to another battery. When the miniclass driver reports that a battery is critical and discharging, the system assumes that battery failure is imminent and prepares to shut down.

## See also

[BatteryClassStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassstatusnotify)

[BatteryMiniDisableStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_disable_status_notify_callback)

[BatteryMiniSetStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_status_notify_callback)