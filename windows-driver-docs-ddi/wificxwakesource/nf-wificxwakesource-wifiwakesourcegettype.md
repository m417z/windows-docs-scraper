## Description

The **WifiWakeSourceGetType** function gets the type for wake-on-LAN (WoL) source from a WiFiCx net adapter.

## Parameters

### `WakeSource`

The WIFIWAKESOURCE object that represents this wake source.

## Return value

Returns a [**WIFI_WAKE_SOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesource/ne-wificxwakesource-wifi_wake_source_type) value that specifies the wake source type.

## Remarks

The client driver must only call **WifiWakeSourceGetType** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[**WIFI_WAKE_SOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxwakesource/ne-wificxwakesource-wifi_wake_source_type)