## Description

The **WIFI_BAND_CAPABILITIES** structure describes the band capabilities for a WiFiCx device.

## Members

### `Size`

The sum (in bytes) of the sizes of all contained elements.

### `NumBands`

The number of bands supported.

### `BandInfoList`

A pointer to a list of [**WIFI_BAND_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_band_info) structures.

## Remarks

Call [**WIFI_BAND_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_band_capabilities_init) to initialize this structure and fill in its **Size** field. Then call [**WifiDeviceSetBandCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetbandcapabilities) to report band capabilities to WiFiCx.

## See also

[**WIFI_BAND_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_band_info)

[**WIFI_BAND_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_band_capabilities_init)

[**WifiDeviceSetBandCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetbandcapabilities)