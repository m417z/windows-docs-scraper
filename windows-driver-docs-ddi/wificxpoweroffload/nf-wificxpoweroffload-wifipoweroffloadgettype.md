## Description

The **WifiPowerOffloadGetType** function gets the Wi-Fi power offload type for a low power protocol offload to a WiFiCx net adapter.

## Parameters

### `WifiPowerOffload`

[_In_] A WIFIPOWEROFFLOAD object that represents this low power protocol offload.

## Return value

Returns a [**WIFI_POWER_OFFLOAD_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/ne-wificxpoweroffload-wifi_power_offload_type) value that specifies the offload type.

## Remarks

The client driver must only call **WifiPowerOffloadGetType** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_POWER_OFFLOAD_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/ne-wificxpoweroffload-wifi_power_offload_type)