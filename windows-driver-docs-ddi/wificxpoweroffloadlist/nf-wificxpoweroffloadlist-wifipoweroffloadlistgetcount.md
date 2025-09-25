## Description

The **WifiPowerOffloadListGetCount** function gets the number of low power protocol offloads to a WiFiCx net adapter.

## Parameters

### `List`

[_In_] A pointer to a driver-allocated and initialized [**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list) structure.

## Return value

Returns the number of low power offloads to this WiFiCx net adapter.

## Remarks

Call [**WIFI_POWER_OFFLOAD_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifi_power_offload_list_init) to initialize the [**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list) structure, then call [**WifiDeviceGetPowerOffloadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifidevicegetpoweroffloadlist) to retrieve the low power protocol offload list. After getting the list, call this function to determine how many low power protocol offloads there are to this WiFiCx net adapter.

The client driver must only call **WifiPowerOffloadListGetCount** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list)

[**WIFI_POWER_OFFLOAD_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifi_power_offload_list_init)

[**WifiDeviceGetPowerOffloadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifidevicegetpoweroffloadlist)