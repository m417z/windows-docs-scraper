## Description

The **WIFI_STATION_CAPABILITIES** structure describes the station capabilities for a WiFiCx device.

## Members

### `Size`

The sum (in bytes) of the sizes of all contained elements.

### `ScanSSIDListSize`

The scan SSID list size.

### `DesiredSSIDListSize`

The desired SSID list size.

### `PrivacyExemptionListSize`

The privacy exemption list size.

### `KeyMappingTableSize`

The key mapping table size.

### `DefaultKeyTableSize`

The default key table size.

### `WEPKeyValueMaxLength`

The maximum length of the WEP key value.

### `MaxNumPerSTA`

The maximum number of per STA default key tables.

### `SupportedQOSFlags`

Specifies whether WMM QOS is supported. Valid values are 0 (not supported) and 1 (supported).

### `HostFIPSModeImplemented`

Specifies whether host FIPS mode is supported. Valid values are 0 (not supported) and 1 (supported).

### `MFPCapable`

Specifies whether management frame protection (MFP) is supported. Valid values are 0 (not supported) and 1 (supported).

### `AutoPowerSaveMode`

Specifies whether auto power save is supported. Valid values are 0 (not supported) and 1 (supported).

### `BSSListCachemanagement`

Specifies if the adapter would maintain the station BSS list cache. Valid values are 0 (no) and 1 (yes).

### `ConnectBSSSelectionOverride`

Specifies if on a Station connect the adapter may attempt association to a BSSID that is not specified in the Preferred BSSID list. Valid values are 0 (no) and 1 (yes).

### `MaxNetworkOffloadListSize`

Specifies the supported number of network offload entries.

### `HESSIDConnectionSupported`

Specifies whether the ability to connect to HESSIDs is supported. Valid values are 0 (not supported) and 1 (supported).

### `FTMAsInitiatorSupport`

Specifies whether the FTM procedures as initiator are supported. Valid values are 0 (not supported) and 1 (supported).

### `FTMNumberOfSupportedTargets`

Number of target STAs supported per FTM request task.

### `HostWPA3FIPSModeEnabled`

Specifies whether host-FIPS mode for WPA3 is enabled. Valid values are 0 (disabled) and 1 (enabled).

### `NumSupportedUnicastAlgorithms`

The number of unicast algorithms supported.

### `UnicastAlgorithmsList`

A pointer to an array of unicast cipher algorithms formatted as [**DOT11_AUTH_CIPHER_PAIR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures. The length of this array is specified by the **NumSupportedUnicastAlgorithms** member.

### `NumSupportedMulticastDataAlgorithms`

The number of multicast data cipher algorithms supported.

### `MulticastDataAlgorithmsList`

A pointer to an array of multicast data cipher algorithms formatted as [**DOT11_AUTH_CIPHER_PAIR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures. The length of this array is specified by the **NumSupportedMulticastDataAlgorithms** member.

### `NumSupportedMulticastMgmtAlgorithms`

The number of multicast management algorithms supported.

### `MulticastMgmtAlgorithmsList`

A pointer to an array of multicast management algorithms formatted as [**DOT11_AUTH_CIPHER_PAIR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures. The length of this array is specified by the **NumSupportedMulticastMgmtAlgorithms** member.

### `NumSecondaryStaBandCombinations`

The number of secondary STA band combinations. If this value is **0**, then the Secondary STA capability will not be set.

### `SecondaryStaBandsCombinations`

A pointer to an array of [**WIFI_STA_BANDS_COMBINATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_sta_bands_combination) structures. If this value is **NULL**, then the Secondary STA capability will not be set.

### `MaxMLOLinksSupported`

The maximum number of links that the hardware supports for Multi-Link Operation (MLO) connections.

### `MLOAddressesList`

A pointer to an array of [**WDI_MAC_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxintf/ns-dot11wificxintf-wdi_mac_address) structures that represent MLO MAC addresses with **MaxMLOLinksSupported** elements. The number of entries in **MLOAddressesList** must match **MaxMLOLinksSupported**. This will indicate that the driver is capable of setting up MLO links.

### `NumAkmsSupported`

The max number of authentication and key management (AKM) suites that the driver supports.

### `AkmsList`

A pointer to an array of [**RSNA_AKM_SUITE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-rsna_akm_suite) structures that represent AKM suites, with **NumAkmsSupported** elements. This list should include all the AKM suites that the driver supports and must include the AKM 24 if the OS is expected to support Simultaneous Authentication of Equals (SAE) with a 384-bit Pairwise Master Key (PMK). The number of entries in **MLOAddressesList** must match **NumAkmsSupported**.

### `NumFIPSCertifiedCipherAlgorithms`

Number of cipher algorithms for which the device has received FIPS 140 certification.

### `FIPSCertifiedCipherAlgorithmsList`

A pointer to an array of [**DOT11_CIPHER_ALGORITHM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm) structures for which the device has received FIPS 140 certification, with **NumFIPSCertifiedCipherAlgorithms** elements.

### `MSCSSupported`

A BOOLEAN that indicates whether the driver supports Mirrored Stream Classification Service (MSCS).

### `DSCPToUPMappingSupported`

A BOOLEAN that indicates whether the driver supports QoS Mapping (Differentiated Services Code Point (DSCP) to User Priority (UP) Mapping).

### `MaxNumConfigurableActionFrameWakePatterns`

The maximum number of action frame wake patterns that the device supports. Drivers must set **MaxNumConfigurableActionFrameWakePatterns** to at least:
* **1** to support MSCS.
* **2** to support DSCP-to-UP mapping.

If **MaxNumConfigurableActionFrameWakePatterns** is less than the minimum value required for each feature, the OS will disable the feature.

## Remarks

Call [**WIFI_STATION_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_station_capabilities_init) to initialize this structure and fill in its **Size** field. Then call [**WifiDeviceSetStationCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetstationcapabilities) to report station capabilities to WiFiCx.

## See also

[**WIFI_STATION_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_station_capabilities_init)

[**WifiDeviceSetStationCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetstationcapabilities)