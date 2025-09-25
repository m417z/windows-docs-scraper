# XINPUT_BATTERY_INFORMATION structure

## Description

Contains information on battery type and charge state.

## Members

### `BatteryType`

The type of battery. *BatteryType* will be one of the following values.

| Value | Description |
| --- | --- |
| BATTERY_TYPE_DISCONNECTED | The device is not connected. |
| BATTERY_TYPE_WIRED | The device is a wired device and does not have a battery. |
| BATTERY_TYPE_ALKALINE | The device has an alkaline battery. |
| BATTERY_TYPE_NIMH | The device has a nickel metal hydride battery. |
| BATTERY_TYPE_UNKNOWN | The device has an unknown battery type. |

### `BatteryLevel`

The charge state of the battery. This value is only valid for wireless devices with a known battery type. *BatteryLevel* will be one of the following values.

| Value |
| --- |
| BATTERY_LEVEL_EMPTY |
| BATTERY_LEVEL_LOW |
| BATTERY_LEVEL_MEDIUM |
| BATTERY_LEVEL_FULL |

## See also

[XINPUT_GAMEPAD](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_gamepad)

[XInput Structures](https://learn.microsoft.com/windows/desktop/xinput/structures)

[XInputGetCapabilities](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetcapabilities)

[XInputSetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputsetstate)