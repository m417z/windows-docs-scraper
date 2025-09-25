## Description

The **WifiDeviceGetWakeSourceList** function gets the list of wake sources for a WiFiCx net adapter.

## Parameters

### `Device`

The WDFDEVICE object that is associated with the net adapter (or multiple adapters if the client driver has more than one for this device).

### `List`

A pointer to a driver-allocated and initialized [**WIFI_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/ns-wificxwakesourcelist-wifi_wake_source_list) structure.

## Remarks

Call [**WIFI_WAKE_SOURCE_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifi_wake_source_list_init) to initialize the [**WIFI_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/ns-wificxwakesourcelist-wifi_wake_source_list) structure, then call this function to retrieve the wake source list.

The client driver must only call **WifiDeviceGetWakeSourceList** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/ns-wificxwakesourcelist-wifi_wake_source_list)

[**WIFI_WAKE_SOURCE_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifi_wake_source_list_init)