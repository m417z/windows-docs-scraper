## Description

The **WIFI_STATION_CAPABILITIES_INIT** function initializes a [**WIFI_STATION_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_station_capabilities) structure.

## Parameters

### `Capabilities`

[_Out_] A pointer to a client driver-allocated **WIFI_STATION_CAPABILITIES** structure.

## Remarks

This function zeroes out the memory of the **WIFI_STATION_CAPABILITIES** structure, then fills in the **Size** member. Client drivers must then call [**WifiDeviceSetStationCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetstationcapabilities) to report station capabilities to WiFiCx.

## See also

[**WIFI_STATION_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_station_capabilities)

[**WifiDeviceSetStationCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetstationcapabilities)