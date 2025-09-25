## Description

The **WifiDeviceSetWiFiDirectCapabilities** function sets the Wi-Fi Direct capabilities for a WiFiCx device.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `WiFiDirectCapabilities`

A pointer to a client driver-allocated and initialized [**WIFI_WIFIDIRECT_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_wifidirect_capabilities) structure.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

Client drivers need to call **WifiDeviceSetWiFiDirectCapabilities** in the set device capabilities phase. Typically this is within [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware).

Call [**WIFI_WIFIDIRECT_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_wifidirect_capabilities_init) to initialize the **WIFI_WIFIDIRECT_CAPABILITIES** structure and fill in its **Size** field. Then call **WifiDeviceSetWiFiDirectCapabilities** to report band capabilities to WiFiCx.

For an example showing how to set Wi-Fi Direct capabilities, see [Wi-Fi Direct support](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#wi-fi-direct-device-capabilities).

## See also

[**WIFI_WIFIDIRECT_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_wifidirect_capabilities)

[**WIFI_WIFIDIRECT_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_wifidirect_capabilities_init)

[Wi-Fi Direct support](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#wi-fi-direct-device-capabilities)