## Description

The **WifiDeviceSetBandCapabilities** function sets the band capabilities for a WiFiCx device.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `BandCapabilities`

A pointer to a client driver-allocated and initialized [**WIFI_BAND_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_band_capabilities) structure.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

Client drivers typically call **WifiDeviceSetBandCapabilities** within [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware).

Call [**WIFI_BAND_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_band_capabilities_init) to initialize the **WIFI_BAND_CAPABILITIES** structure and fill in its **Size** field. Then call **WifiDeviceSetBandCapabilities** to report band capabilities to WiFiCx.

For more information see [Default (station) adapter creation flow](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#default-(station)-adapter-creation-flow).

## See also

[**WIFI_BAND_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_band_capabilities)

[**WIFI_BAND_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_band_capabilities_init)

[Default (station) adapter creation flow](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#default-(station)-adapter-creation-flow)