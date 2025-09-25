## Description

The **WIFI_WIFIDIRECT_CAPABILITIES** structure describes the Wi-Fi Direct capabilities for a WiFiCx device.

## Members

### `Size`

The sum (in bytes) of the sizes of all contained elements.

### `WFDRoleCount`

Number of supported Wi-Fi Direct Role Ports

### `ConcurrentGOCount`

Specifies the concurrent Group Owner count.

### `ConcurrentClientCount`

Specifies the concurrent Client count.

### `ServiceDiscoverySupported`

Specifies whether Service discovery is supported.
Valid values are 0 (not supported) and 1 (supported).

### `ServiceNameDiscoverySupported`

Wi-Fi Direct Service Names Discovery support. Specifies whether, when given a list of service name hashes, the adapter can probe for service hashes and indicate the responses as they arrive.
Valid values are 0 (not supported) and 1 (supported).

### `ServiceInformationDiscoverySupported`

Wi-Fi Direct Service Information Discovery support. Specifies whether, when given a list of service name hashes, the adapter can perform probes and ANQP queries to get full service information.
Valid values are 0 (not supported) and 1 (supported).

### `ServiceNameAdvertisementsMaxBytesSupported`

Specifies the maximum supported number of Service Name Advertisements bytes (to be sent in the beacon and probe responses). This sets a hard limit on the number of services that can be advertised.

### `ServiceInformationAdvertisementsMaxBytesSupported`

Specifies the maximum supported number of Service Information Advertisement bytes the adapter can respond to using the GAS protocol. This is only valid if the device supports responding to Service Advertisement queries. This value is for firmware optimization so that the firmware does not wake up the host to respond to every query. The operating system does not limit the number of service advertisements if the firmware has a limitation because there is a fallback in the operating system. If the firmware cannot handle the ANQP query response, it should pass up the request and the operating system handles it.

### `BackgroundDiscoverySupported`

Background discovery of Wi-Fi Direct devices and services. Specifies whether the adapter can periodically query for Wi-Fi Direct devices and service names so any new devices show up within 5 minutes of becoming visible.
Valid values are 0 (not supported) and 1 (supported).

### `ClientDiscoverabilitySupported`

Specifies whether Client Discoverability is supported.
Valid values are 0 (not supported) and 1 (supported).

### `InfrastructureManagementSupported`

Specifies whether infrastructure management is supported.
Valid values are 0 (not supported) and 1 (supported).

### `DeviceAddress[6]`

The device address in network byte order.

### `DiscoveryFilterListSize`

The discovery filter list size.

### `GOClientTableSize`

The GO client table size.

### `MaxVendorSpecificExtensionIESize`

The maximum size, in bytes, of vendor specific extension IEs that can be added to WFD management frames.

### `PassiveAvailabilityListenStateSupported`

Specifies whether the ability to listen for P2P Services in the background is supported. Valid values are 0 (not supported) and 1 (supported).

### `OperatingChannelUpdatesSupported`

Specifies whether the adapter supports indicating updates to the GO operating channel(s).
Valid values are 0 (not supported) and 1 (supported).

### `GOon5GHzBandSupported`

Specifies whether the adapter supports operating a GO on the 5GHz band.
Valid values are 0 (not supported) and 1 (supported).

### `ScanSSIDListSize`

The scan SSID list size.

### `DesiredSSIDListSize`

The desired SSID list size.

### `PrivacyExemptionListSize`

The privacy exemption list size.

### `AssociationTableSize`

The association table size.

### `DefaultKeyTableSize`

The default key table size.

### `WEPKeyValueMaxLength`

The maximum length of the WEP key value.

### `NumSupportedUnicastAlgorithms`

The number of unicast algorithms supported.

### `UnicastAlgorithms`

A pointer to an array of unicast cipher algorithms formatted as [**DOT11_AUTH_CIPHER_PAIR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures. The length of this array is specified by the **NumSupportedUnicastAlgorithms** member.

### `NumSupportedMulticastDataAlgorithms`

The number of multicast data cipher algorithms supported.

### `MulticastDataAlgorithms`

A pointer to an array of multicast data cipher algorithms formatted as [**DOT11_AUTH_CIPHER_PAIR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures. The length of this array is specified by the **NumSupportedMulticastDataAlgorithms** member.

### `NumInterfaceAddresses`

The number of interface addresses supported.

### `InterfaceAddressList`

A pointer to an array of interface addresses formatted as [**WDI_MAC_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxintf/ns-dot11wificxintf-wdi_mac_address) structures. The length of this array is specified by the **NumInterfaceAddresses** member.

### `GOon6GHzBandSupported`

A BOOLEAN value that specifies whether the adapter supports operating a GO on 6GHz band. Valid values are 0 (not supported) and 1 (supported).

## Remarks

Call [**WIFI_WIFIDIRECT_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_wifidirect_capabilities_init) to initialize this structure and fill in its **Size** field. Then call [**WifiDeviceSetWiFiDirectCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetwifidirectcapabilities) to report Wi-Fi Direct capabilities to WiFiCx.

## See also

[**WIFI_WIFIDIRECT_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_wifidirect_capabilities_init)

[**WifiDeviceSetWiFiDirectCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidevicesetwifidirectcapabilities)