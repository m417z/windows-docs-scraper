## Description

The **WifiWakeSourceListGetElement** function gets a wake source from the list of wake sources for a WiFiCx net adapter.

## Parameters

### `List`

[_In_] A handle to a driver-allocated and initialized [**WIFI_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/ns-wificxwakesourcelist-wifi_wake_source_list) structure.

### `Index`

[_In_] The zero-based index in the list for the target WIFIWAKESOURCE object. This function must be less than the value returned by [**WifiWakeSourceListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifiwakesourcelistgetcount).

## Return value

Returns the WIFIWAKESOURCE object, which represents the wake source, at the specified index in the list.

## Remarks

Call [**WifiWakeSourceListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifiwakesourcelistgetcount) to get the number of wake sources before calling this function.

The client driver must only call **WifiWakeSourceListGetElement** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/ns-wificxwakesourcelist-wifi_wake_source_list)

[**WifiWakeSourceListGetCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifiwakesourcelistgetcount)