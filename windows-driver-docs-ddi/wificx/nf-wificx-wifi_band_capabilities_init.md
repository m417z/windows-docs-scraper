## Description

The **WIFI_BAND_CAPABILITIES_INIT** function initializes a [**WIFI_BAND_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_band_capabilities) structure.

## Parameters

### `Capabilities`

[_Out_] A pointer to a client driver-allocated **WIFI_BAND_CAPABILITIES** structure.

## Remarks

This function zeroes out the memory of the **WIFI_BAND_CAPABILITIES** structure, then fills in the **Size** member. Client drivers must then call [**WifiDeviceSetBandCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetbandcapabilities) to report band capabilities to WiFiCx.

## See also

[**WIFI_BAND_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_band_capabilities)

[**WifiDeviceSetBandCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetbandcapabilities)