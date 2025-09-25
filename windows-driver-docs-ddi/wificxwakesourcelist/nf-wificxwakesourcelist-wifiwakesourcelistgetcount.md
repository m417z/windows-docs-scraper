## Description

The **WifiWakeSourceListGetCount** function gets the number of wake sources for a WiFiCx net adapter.

## Parameters

### `List`

[_In_] A pointer to a driver-allocated and initialized [**NET_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/ns-netwakesourcelist-_net_wake_source_list) structure.

## Return value

Returns the number of wake sources for this net adapter.

## Remarks

Call [**WIFI_WAKE_SOURCE_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifi_wake_source_list_init) to initialize the [**WIFI_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/ns-wificxwakesourcelist-wifi_wake_source_list) structure, then call [**WifiDeviceGetWakeSourceList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifidevicegetwakesourcelist) to retrieve the wake source list. After getting the list, call this function to determine how many wake sources there are for this net adapter.

The client driver must only call **WifiWakeSourceListGetCount** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**NET_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesourcelist/ns-netwakesourcelist-_net_wake_source_list)