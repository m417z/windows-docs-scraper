## Description

The **WifiDeviceGetPowerOffloadList** function gets the list of low power protocol offloads to a WiFiCx net adapter.

## Parameters

### `Device`

[_In_] The WDFDEVICE object associated with the WiFiCx net adapter.

### `List`

[_Inout_] A pointer to a driver-allocated and initialized [**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list) structure.

## Remarks

Call [**WIFI_POWER_OFFLOAD_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifi_power_offload_list_init) to initialize the [**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list) structure, then call this function to retrieve the low power protocol offload list.

The client driver must only call **WifiDeviceGetPowerOffloadList** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list)

[**WIFI_POWER_OFFLOAD_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifi_power_offload_list_init)