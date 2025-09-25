# WLAN_POWER_SETTING enumeration

## Description

The **WLAN_POWER_SETTING** enumerated type specifies the power setting of an interface.

## Constants

### `wlan_power_setting_no_saving:0`

Specifies no power-saving activity performed by the 802.11 station.

### `wlan_power_setting_low_saving`

Specifies a power save polling (PSP) mode that uses the fastest power-saving mode. This power mode must provide the best combination of network performance and power usage.

### `wlan_power_setting_medium_saving`

Specifies a PSP mode that uses the maximum (MAX) power saving capabilities. The MAX power save mode results in the greatest power savings for the radio on the 802.11 station.

### `wlan_power_setting_maximum_saving`

Specifies a proprietary PSP mode implemented by the independent hardware vendor (IHV) that exceeds the wlan_power_setting_medium_saving power-saving level.

### `wlan_power_setting_invalid`

The supplied power setting is invalid.

## Remarks

## See also

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))