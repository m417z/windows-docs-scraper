## Description

The **WIFI_WAKE_SOURCE_LIST** structure represents a list of wake sources for a WiFiCx net adapter.

## Members

### `Size`

The size of this structure, in bytes.

### `Reserved`

Reserved. Client drivers must not read or write to this value directly.

## Remarks

Call [**WIFI_WAKE_SOURCE_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifi_wake_source_list_init) to initialize this structure, then call [**WifiDeviceGetWakeSourceList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifidevicegetwakesourcelist) to get the list of wake sources from this net adapter. After you obtain the list, call [**WifiWakeSourceListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifiwakesourcelistgetcount) with this structure to get the number of WIFIWAKESOURCE objects that represents the wake sources, then loop over the objects and call [**WifiWakeSourceListGetElement**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifiwakesourcelistgetelement) to retrieve each one. Once you have obtained a WIFIWAKESOURCE object, call [**WifiWakeSourceGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesource/nf-wificxwakesource-wifiwakesourcegettype) to get the type of that wake source so you can call the appropriate function to get the wake source's parameters.

The client driver must only call wake source-related functions during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_WAKE_SOURCE_LIST_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifi_wake_source_list_init)

[**WifiDeviceGetWakeSourceList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifidevicegetwakesourcelist)

[**WifiWakeSourceListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifiwakesourcelistgetcount)

[**WifiWakeSourceListGetElement**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifiwakesourcelistgetelement)

[**WifiWakeSourceGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesource/nf-wificxwakesource-wifiwakesourcegettype)