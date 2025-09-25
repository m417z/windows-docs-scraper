# BATTERY_NOTIFY structure

## Description

A battery miniclass driver receives a BATTERY_NOTIFY structure when its [BatteryMiniSetStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_status_notify_callback) routine is called.

## Members

### `PowerState`

Contains one or more of the following flags to specify a battery power state: BATTERY_POWER_ON_LINE, BATTERY_DISCHARGING, BATTERY_CHARGING, BATTERY_CRITICAL.

### `LowCapacity`

Specifies a ULONG value indicating the battery capacity below which the class driver requires notification.

### `HighCapacity`

Specifies a ULONG value indicating the battery capacity above which the class driver requires notification.

## See also

[BatteryMiniSetStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_status_notify_callback)