# _DOT11_EXTAP_ATTRIBUTES structure

## Description

> [!IMPORTANT]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_EXTAP_ATTRIBUTES structure defines the physical and operating attributes of the miniport driver and 802.11 station when it operates in Extensible Access Point (ExtAP) mode.

## Members

### `Header`

The type, revision, and size of the DOT11_EXTAP_ATTRIBUTES structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of **Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_EXTAP_ATTRIBUTES_REVISION_1.

#### Size

This member must be set to **sizeof**(DOT11_EXTAP_ATTRIBUTES).

For more information about these members, see [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uScanSSIDListSize`

The maximum number of service set identifiers (SSIDs) supported by the 802.11 station for scan operations. The 802.11 station must support an SSID list of at least four entries.

The SSID list that the 802.11 station uses for scanning is specified when [OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request) is set.

### `uDesiredSSIDListSize`

The maximum number of entries in the desired list of basic service set identifiers (BSSIDs)supported by the 802.11 station. The 802.11 station must support a BSSID list with at least one entry.

For more information about the desired BSSID list, see [OID_DOT11_DESIRED_BSSID_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-bssid-list).

### `uPrivacyExemptionListSize`

The maximum number of entries in the privacy exemption list supported by the 802.11 station. The
802.11 station must support a privacy exemption list with at least one entry.

For more information about the privacy exemption list, see [OID_DOT11_PRIVACY_EXEMPTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-privacy-exemption-list).

### `uAssociationTableSize`

The maximum number of associations that the 802.11 station can support simultaneously. The 802.11 station must support an association list that has at least one entry. A NIC should typically be able to support at least 32 associations simultaneously.

If the NIC supports any authentication and cipher algorithms that require [key-Mapping keys](https://learn.microsoft.com/windows-hardware/drivers/network/key-mapping-keys), it must support at least the number of entries in its key-mapping key table.

### `uDefaultKeyTableSize`

The maximum number of cipher keys the 802.11 station supports for the default key and per-station
default key tables.

For standard 802.11 cipher algorithms, the 802.11 station must support a table size of at least four cipher keys. For cipher algorithms developed by the independent hardware vendor (IHV), the table size can be four or greater.

### `uWEPKeyValueMaxLength`

The maximum length, in bytes, of a WEP cipher key supported by the 802.11 station.

The following table lists the minimum and maximum key lengths, in bytes, for the various WEP cipher values defined through DOT11_CIPHER_ALGORITHM(..\wlantypes\ne-wlantypes-_dot11_cipher_algorithm.md).

|WEP cipher|Minimum key length|Maximum key length|
|--- |--- |--- |
|**DOT11_CIPHER_ALGO_WEP40**|5|5|
|**DOT11_CIPHER_ALGO_WEP104**|13|13|
|**DOT11_CIPHER_ALGO_WEP**|13|Any length supported by the 802.11 station|

### `bStrictlyOrderedServiceClassImplemented`

A Boolean value that, if set to **TRUE**, specifies that the 802.11 station supports the IEEE 802.11 StrictlyOrdered service class for media access control (MAC) service data unit (MSDU) packet delivery.

For more information about the StrictlyOrdered service class, refer to Clause 5.1.3 of the IEEE 802.11-2012 standard.

### `uNumSupportedCountryOrRegionStrings`

The number of country or region strings supported by the 802.11 station. If the 802.11 station supports multiple regulatory domains as specified by the IEEE 802.11d-2001 standard, each country or region string identifies a regulatory domain supported by the 802.11 station.

If the 802.11 station does not support the IEEE 802.11d-2001 standard, the miniport driver must set **uNumSupportedCountryOrRegionStrings** to zero.

### `pSupportedCountryOrRegionStrings`

A pointer to an array of 802.11d country or region strings that are supported by the 802.11
station. Each entry in the array is formatted as a [DOT11_COUNTRY_OR_REGION_STRING](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-country-or-region-string) structure.

### `uInfraNumSupportedUcastAlgoPairs`

The number of authentication and cipher algorithms supported by the 802.11 station for sending and receiving unicast packets when configured for operation in an infrastructure basic service set (BSS) network. The **uInfraNumSupportedUcastAlgoPairs** member must be the number of [DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures in the array referenced by the **pInfraSupportedUcastAlgoPairs** member.

### `pInfraSupportedUcastAlgoPairs`

A pointer to an array of authentication and cipher algorithms supported by the 802.11 station for sending and receiving unicast packets in an infrastructure BSS network. Each entry in the array is formatted as a [DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structure.

### `uInfraNumSupportedMcastAlgoPairs`

The number of authentication and cipher algorithms supported by the 802.11 station for sending and receiving multicast and broadcast packets when configured for operation in an infrastructure basic service set (BSS) network. The **uInfraNumSupportedMcastAlgoPairs** member must be the number of [DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures in the array referenced by the **pInfraSupportedMcastAlgoPairs** member.

### `pInfraSupportedMcastAlgoPairs`

A pointer to an array of authentication and cipher algorithms supported by the 802.11 station for sending and receiving multicast and broadcast packets in an infrastructure BSS network. Each entry in the array is formatted as a [DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structure.

## Syntax

```cpp
typedef struct _DOT11_EXTAP_ATTRIBUTES {
  NDIS_OBJECT_HEADER              Header;
  ULONG                           uScanSSIDListSize;
  ULONG                           uDesiredSSIDListSize;
  ULONG                           uPrivacyExemptionListSize;
  ULONG                           uAssociationTableSize;
  ULONG                           uDefaultKeyTableSize;
  ULONG                           uWEPKeyValueMaxLength;
  BOOLEAN                         bStrictlyOrderedServiceClassImplemented;
  ULONG                           uNumSupportedCountryOrRegionStrings;
  PDOT11_COUNTRY_OR_REGION_STRING pSupportedCountryOrRegionStrings;
  ULONG                           uInfraNumSupportedUcastAlgoPairs;
  PDOT11_AUTH_CIPHER_PAIR         pInfraSupportedUcastAlgoPairs;
  ULONG                           uInfraNumSupportedMcastAlgoPairs;
  PDOT11_AUTH_CIPHER_PAIR         pInfraSupportedMcastAlgoPairs;
} DOT11_EXTAP_ATTRIBUTES, *PDOT11_EXTAP_ATTRIBUTES;
```

## See also

[OID_DOT11_DESIRED_BSSID_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-bssid-list)

[DOT11_COUNTRY_OR_REGION_STRING](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-country-or-region-string)

[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair)

[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm)

[OID_DOT11_PRIVACY_EXEMPTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-privacy-exemption-list)

[OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)