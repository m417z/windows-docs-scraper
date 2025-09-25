## Description

The **WifiDeviceSetStationCapabilities** function sets the station capabilities for a WiFiCx device.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `StationCapabilities`

A pointer to a client driver-allocated and initialized [**WIFI_STATION_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_station_capabilities) structure.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

Client drivers typically call **WifiDeviceSetStationCapabilities** within [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware). For more information see [Default (station) adapter creation flow](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#default-(station)-adapter-creation-flow).

Call [**WIFI_STATION_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_station_capabilities_init) to initialize the **WIFI_STATION_CAPABILITIES** structure and fill in its **Size** field. Then call **WifiDeviceSetStationCapabilities** to report station capabilities to WiFiCx.

To indicate the ability to maintain [Secondary Sta connectivity](https://learn.microsoft.com/windows-hardware/drivers/netcx/dual-sta-connectivity), the driver must set the **NumSecondaryStaBandCombinations** and **SecondaryStaBandsCombinations** fields of the [**WIFI_STATION_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_station_capabilities) structure to non-zero values. If either value is **0** or **NULL**, then the Secondary Sta capability will not be set.

To indicate support for MLO connections in Wi-Fi 7, the driver must set the **MaxMLOLinksSupported**, **MLOAddressesList**, **NumAkmsSupported**, and **AkmsList** fields of the **WIFI_STATION_CAPABILITIES** structure to non-zero values.

To support SAE connections using AKM 24 or AKM 8 with GCMP-256 cipher, the driver must add the following auth-cipher pairs in the **WIFI_STATION_CAPABILITIES** structure:
- In **UnicastAlgorithmsList**:
{ DOT11_AUTH_ALGO_WPA3_SAE, DOT11_CIPHER_ALGO_GCMP_256 }
- In **MulticastMgmtAlgorithmsList**:
{ DOT11_AUTH_ALGO_WPA3_SAE, DOT11_CIPHER_ALGO_GCMP_256 }
To support OWE connections with GCMP-256 cipher, the driver must add the following auth-cipher pair:
- In **UnicastAlgorithmsList**: { DOT11_AUTH_ALGO_OWE, DOT11_CIPHER_ALGO_GCMP_256 }

## See also

[**WIFI_STATION_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_station_capabilities)

[**WIFI_STATION_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_station_capabilities_init)

[Default (station) adapter creation flow](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#default-(station)-adapter-creation-flow)