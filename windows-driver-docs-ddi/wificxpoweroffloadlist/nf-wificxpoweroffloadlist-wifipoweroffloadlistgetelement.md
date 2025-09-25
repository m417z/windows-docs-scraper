## Description

The **WifiPowerOffloadListGetElement** function gets a low power protocol offload from a list of offloads to a WiFiCx net adapter.

## Parameters

### `List`

[_In_] A pointer to a driver-allocated and initialized [**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list) structure.

### `Index`

[_In_] The zero-based index in the list for the target WIFIPOWEROFFLOAD object. This function must be less than the value returned by [**WifiPowerOffloadListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifipoweroffloadlistgetcount).

## Return value

Returns the WIFIPOWEROFFLOAD object, which represents the low power protocol offload, at the specified index in the list.

## Remarks

Call [**WifiPowerOffloadListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifipoweroffloadlistgetcount) to get the number of low power protocol offloads before calling this function.

The client driver must only call **WifiPowerOffloadListGetElement** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/ns-wificxpoweroffloadlist-wifi_power_offload_list)

[**WifiPowerOffloadListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifipoweroffloadlistgetcount)