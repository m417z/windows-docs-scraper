## Description

The **WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS** structure contains parameters for an action frame wake pattern low power protocol offload to a WiFiCx network adapter.

## Members

### `Size`

The size of the **WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS** structure in bytes.

### `FilterOnFrameAction`

**FilterOnFrameAction** can have the following values:
* **0**: The IHV driver should indicate all incoming action frames that match **ActionFrameCategory**.
* **1**: The IHV driver should indicate all incoming action frames that match both **ActionFrameCategory** and **ActionFrameAction**.

### `ActionFrameCategory`

A UINT8 representing the Action Frame Category.

### `ActionFrameAction`

A UINT8 representing the Action Frame Action. The driver ignores **ActionFrameAction** if it isn't filtering by action type.

## Remarks

The IHV driver must call [**WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifi_power_offload_action_frame_wake_pattern_parameters_init) to initialize this structure and fill in its **Size** field. Then the driver must call [**WifiPowerOffloadGetActionFrameWakePatternParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifipoweroffloadgetactionframewakepatternparameters) to fill in the remaining members of the structure.

## See also

[**WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifi_power_offload_action_frame_wake_pattern_parameters_init)

[**WifiPowerOffloadGetActionFrameWakePatternParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifipoweroffloadgetactionframewakepatternparameters)