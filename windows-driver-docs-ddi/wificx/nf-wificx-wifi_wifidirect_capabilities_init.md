## Description

The **WIFI_WIFIDIRECT_CAPABILITIES_INIT** function initializes a [**WIFI_WIFIDIRECT_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_wifidirect_capabilities) structure.

## Parameters

### `Capabilities`

[_Out_] A pointer to a client driver-allocated **WIFI_WIFIDIRECT_CAPABILITIES** structure.

## Remarks

This function zeroes out the memory of the **WIFI_WIFIDIRECT_CAPABILITIES** structure, then fills in the **Size** member. Client drivers must then call [**WifiDeviceSetWifiDirectCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetwifidirectcapabilities) to report WiFi Direct capabilities to WiFiCx.

## See also

[**WIFI_WIFIDIRECT_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_wifidirect_capabilities)

[**WifiDeviceSetWifiDirectCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetwifidirectcapabilities)