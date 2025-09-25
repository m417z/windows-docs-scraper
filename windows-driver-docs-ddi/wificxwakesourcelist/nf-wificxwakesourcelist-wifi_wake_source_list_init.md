## Description

The **WIFI_WAKE_SOURCE_LIST_INIT** function initializes a [**WIFI_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/ns-wificxwakesourcelist-wifi_wake_source_list) structure.

## Parameters

### `List`

[_Out_] A pointer to a driver-allocated [**WIFI_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/ns-wificxwakesourcelist-wifi_wake_source_list) structure.

## Remarks

This function zeroes out the memory for the **WIFI_WAKE_SOURCE_LIST** structure, then fills in the **Size** member. After calling this function, call [**WifiDeviceGetWakeSourceList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifidevicegetwakesourcelist) with the initialized structure to get the list of wake sources for this Wi-Fi adapter.

The client driver must only call **WIFI_WAKE_SOURCE_LIST_INIT** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_WAKE_SOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/ns-wificxwakesourcelist-wifi_wake_source_list)

[**WifiDeviceGetWakeSourceList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesourcelist/nf-wificxwakesourcelist-wifidevicegetwakesourcelist)