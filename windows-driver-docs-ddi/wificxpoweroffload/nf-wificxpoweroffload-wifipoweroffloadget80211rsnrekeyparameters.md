## Description

The **WifiPowerOffloadGet80211RSNRekeyParameters** function gets parameters for an 802.11 RSN rekey low power protocol offload to a WiFiCx net adapter.

## Parameters

### `WifiPowerOffload`

The WIFIPOWEROFFLOAD object that represents this protocol offload.

### `Parameters`

A pointer to a driver-allocated and initialized [**WIFI_POWER_OFFLOAD_80211RSNREKEY_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/ns-wificxpoweroffload-wifi_power_offload_80211rsnrekey_parameters) structure that receives the ARP parameter information.

## Remarks

Call [**WIFI_POWER_OFFLOAD_80211RSNREKEY_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifi_power_offload_80211rsnrekey_parameters_init) to initialize the [**WIFI_POWER_OFFLOAD_80211RSNREKEY_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/ns-wificxpoweroffload-wifi_power_offload_80211rsnrekey_parameters) structure before calling this function.

The client driver must only call **WifiPowerOffloadGet80211RSNRekeyParameters** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_POWER_OFFLOAD_80211RSNREKEY_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/ns-wificxpoweroffload-wifi_power_offload_80211rsnrekey_parameters)

[**WIFI_POWER_OFFLOAD_80211RSNREKEY_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifi_power_offload_80211rsnrekey_parameters_init)