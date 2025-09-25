## Description

The **WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS_INIT** function initializes a [**WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/ns-wificxpoweroffload-wifi_power_offload_action_frame_wake_pattern_parameters) structure.

## Parameters

### `Parameters`

[_Out_] A pointer to a client driver-allocated [**WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/ns-wificxpoweroffload-wifi_power_offload_action_frame_wake_pattern_parameters) structure.

## Remarks

This function zeroes out the memory of the WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS structure, then fills in the **Size** member. Client drivers must then call [**WifiPowerOffloadGetActionFrameWakePatternParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifipoweroffloadgetactionframewakepatternparameters) to fill in the remaining members of the structure.

The client driver must only call **WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS_INIT** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_POWER_OFFLOAD_ACTION_FRAME_WAKE_PATTERN_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/ns-wificxpoweroffload-wifi_power_offload_action_frame_wake_pattern_parameters)

[**WifiPowerOffloadGetActionFrameWakePatternParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifipoweroffloadgetactionframewakepatternparameters)