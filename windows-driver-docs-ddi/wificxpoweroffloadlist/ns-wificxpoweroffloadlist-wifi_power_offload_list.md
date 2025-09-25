## Description

The **WIFI_POWER_OFFLOAD_LIST** structure represents a list of low power protocol offloads to a WiFiCx net adapter.

## Members

### `Size`

The size of this structure, in bytes.

### `Reserved`

Reserved. Client drivers must not read or write to this value directly.

## Remarks

Call [**WIFI_POWER_OFFLOAD_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifi_power_offload_list_init) to initialize this structure, then call [**WifiDeviceGetPowerOffloadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifidevicegetpoweroffloadlist) to get the list of low power offloads to this WiFiCx net adapter. After you obtain the list, call [**WifiPowerOffloadListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifipoweroffloadlistgetcount) with this structure to get the number of WIFIPOWEROFFLOAD objects that represents the offloads, then loop over the objects and call [**WifiPowerOffloadListGetElement**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifipoweroffloadlistgetelement) to retrieve each one. Once you have obtained a WIFIPOWEROFFLOAD object, call [**WifiPowerOffloadGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifipoweroffloadgettype) to get the type of that offload so you can call the appropriate function to get the offload's parameters.

The client driver must only call power offload-related functions during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_POWER_OFFLOAD_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifi_power_offload_list_init)

[**WifiDeviceGetPowerOffloadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifidevicegetpoweroffloadlist)

[**WifiPowerOffloadListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifipoweroffloadlistgetcount)

[**WifiPowerOffloadListGetElement**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffloadlist/nf-wificxpoweroffloadlist-wifipoweroffloadlistgetelement)

[**WifiPowerOffloadGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifipoweroffloadgettype)