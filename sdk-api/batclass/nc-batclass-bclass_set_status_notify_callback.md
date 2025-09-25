# BCLASS_SET_STATUS_NOTIFY_CALLBACK callback function

## Description

*BatteryMiniSetStatusNotify* sets the battery capacity and power state levels at which the class driver requires notification.

## Parameters

### `Context` [in]

A pointer to the context area allocated by the miniclass driver for the battery device.

### `BatteryTag` [in]

A battery tag value previously returned by *BatteryMiniQueryTag*.

### `BatteryNotify` [in]

A pointer to a [BATTERY_NOTIFY](https://learn.microsoft.com/windows/desktop/api/batclass/ns-batclass-battery_notify) structure.

## Return value

*BatteryMiniSetStatusNotify* returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | A battery is currently installed. |
| **STATUS_NO_SUCH_DEVICE** | No battery is present or the given battery tag is invalid. |
| **STATUS_NOT_SUPPORTED** | The miniclass driver cannot distinguish the target condition. |

## Remarks

The battery class driver calls a miniclass driver's *BatteryMiniSetStatusNotify* routine to set criteria for an acceptable range of battery conditions. When the battery's capacity or power state deviates from these criteria, the miniclass driver must call [BatteryClassStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassstatusnotify) to notify the class driver.

In the **PowerState** member of the [BATTERY_NOTIFY](https://learn.microsoft.com/windows/desktop/api/batclass/ns-batclass-battery_notify) structure, the class driver specifies one or more battery power states. Any time the battery enters a power state that is not in **PowerState**, the miniclass driver must notify the class driver.

In the **LowCapacity** and **HighCapacity** members of BATTERY_NOTIFY, the class driver specifies a range of capacity. When the capacity falls above or below this range, the miniclass driver must notify the class driver.

Some batteries might be unable to distinguish the precise capacities requested by the battery class driver. When possible, miniclass drivers for these batteries should attempt to correct for the error so that the user can be informed when the battery approaches a critical state. Otherwise, such drivers should return STATUS_NOT_SUPPORTED.

## See also

[BatteryClassStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassstatusnotify)

[BatteryMiniDisableStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_disable_status_notify_callback)