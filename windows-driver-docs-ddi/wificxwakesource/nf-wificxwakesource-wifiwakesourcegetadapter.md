## Description

The **WifiWakeSourceGetAdapter** function gets the WiFiCx net adapter for a wake-up source.

## Parameters

### `WakeSource`

[_In_] The WIFIWAKESOURCE object that represents the source of the wake-up event.

## Return value

Returns the NETADAPTER object that represents the Wi-Fi adapter for this wake source.

## Remarks

The client driver must only call **WifiWakeSourceGetAdapter** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

## See also