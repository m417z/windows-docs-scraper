## Description

The **WifiPowerOffloadGetActionFrameWakePatternParameters** function gets the parameters for an action frame wake pattern low power protocol offload to a WiFiCx network adapter.

## Parameters

### `WifiPowerOffload` [in]

The WIFIPOWEROFFLOAD object that represents this protocol offload.

### `Parameters` [inout]

A pointer to a driver-allocated and initialized [**WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/ns-wificxpoweroffload-wifi_power_offload_action_frame_wake_pattern_parameters) structure that receives the action frame wake pattern parameter information.

## Remarks

Drivers must call [**WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifi_power_offload_action_frame_wake_pattern_parameters_init) to initialize the [**WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/ns-wificxpoweroffload-wifi_power_offload_action_frame_wake_pattern_parameters) structure before calling this function.

## See also

[**WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/ns-wificxpoweroffload-wifi_power_offload_action_frame_wake_pattern_parameters)

[**WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifi_power_offload_action_frame_wake_pattern_parameters_init)