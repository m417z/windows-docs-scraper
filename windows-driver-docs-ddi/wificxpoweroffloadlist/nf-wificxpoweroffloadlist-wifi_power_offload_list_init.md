## Description

The **WIFI_POWER_OFFLOAD_LIST_INIT** function initializes a [**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list) structure.

## Parameters

### `List`

[_Out_] A pointer to a driver-allocated [**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list).

## Remarks

This function zeroes out the memory of the [**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list) structure, then fills in the **Size** member. Client drivers must then call [**WifiDeviceGetPowerOffloadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifidevicegetpoweroffloadlist) with the initialized structure to get the list of low power offloads to this WiFiCx net adapter.

The client driver must only call **WIFI_POWER_OFFLOAD_LIST_INIT** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list)

[**WifiDeviceGetPowerOffloadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifidevicegetpoweroffloadlist)