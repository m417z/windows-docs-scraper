## Description

The **WifiAdapterSetWakeCapabilities** method sets the wake capabilities for a WiFiCx device.

## Parameters

### `Adapter`

[_In_] A handle to a NETADAPTER object that the client driver obtained from a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Capabilities`

[_In_] A pointer to a driver-allocated and initialized [**WIFI_ADAPTER_WAKE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_wake_capabilities) structure.

## Remarks

The client driver typically calls this function from within [*EVT_DEVICE_PREPARE_HARDWARE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware).

## See also

[**WIFI_ADAPTER_WAKE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_wake_capabilities)