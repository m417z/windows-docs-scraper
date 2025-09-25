# DOT11_EXTSTA_ATTRIBUTES structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_EXTSTA_ATTRIBUTES** structure defines the physical and operating attributes of the miniport
driver and 802.11 station when operating in Extensible Station (ExtSTA) mode. For more information about
this operation mode, see
[Extensible Station Operation
Mode](https://learn.microsoft.com/windows-hardware/drivers/network/extensible-station-operation-mode).

## Members

### `Header`

The type, revision, and size of the **DOT11_EXTSTA_ATTRIBUTES** structure. This member is formatted as
an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values.

#### Type

This member must be set to **NDIS_OBJECT_TYPE_DEFAULT**.

#### Revision

This member must be set to one of the following values according to the operating system that
the driver is intended to run on:

##### DOT11_EXTSTA_ATTRIBUTES_REVISION_1

Windows Vista

##### DOT11_EXTSTA_ATTRIBUTES_REVISION_2

Windows Vista with Service Pack 1 (SP1) or later versions of the Windows operating
systems

##### DOT11_EXTSTA_ATTRIBUTES_REVISION_3

Windows 8 or later versions of the Windows operating
systems

These values determine how the operating system interprets the
**bSafeModeImplemented** member.

#### Size

This member must be set to
**sizeof**(**DOT11_EXTSTA_ATTRIBUTES**).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uScanSSIDListSize`

The maximum number of service set identifiers (SSIDs) supported by the 802.11 station for scan
operations. The 802.11 station must support an SSID list of at least four entries.

The SSID list that the 802.11 station uses for scanning is specified when
[OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request) is
set.

### `uDesiredBSSIDListSize`

The maximum number of entries in the desired list of basic service set identifiers (BSSIDs)
supported by the 802.11 station. The 802.11 station must support a BSSID list with at least one entry.

For more information about the desired BSSID list, see
[OID_DOT11_DESIRED_BSSID_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-bssid-list).

### `uDesiredSSIDListSize`

The maximum number of entries in the desired SSID list supported by the 802.11 station. The 802.11
station must support a desired SSID list with at least one entry.

For more information about the desired SSID list, see
[OID_DOT11_DESIRED_SSID_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-ssid-list).

### `uExcludedMacAddressListSize`

The maximum number of entries in the excluded MAC address list supported by the 802.11 station.
The 802.11 station must support an excluded MAC address list with at least four entries.

For more information about the desired excluded MAC address list, see
[OID_DOT11_EXCLUDED_MAC_ADDRESS_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-excluded-mac-address-list).

### `uPrivacyExemptionListSize`

The maximum number of entries in the privacy exemption list supported by the 802.11 station. The
802.11 station must support a privacy exemption list with at least one entry.

For more information about the privacy exemption list, see
[OID_DOT11_PRIVACY_EXEMPTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-privacy-exemption-list).

### `uKeyMappingTableSize`

The maximum number of cipher key-mapping keys supported by the 802.11 station. It is recommended
that the 802.11 station support at least 32 key-mapping keys.

For more information about key mapping keys, see
[OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key).

### `uDefaultKeyTableSize`

The maximum number of cipher keys the 802.11 station supports for the default key and per-station
default key tables.

For standard 802.11 cipher algorithms, the 802.11 station must support a table size of at least four
cipher keys. For cipher algorithms developed by the independent hardware vendor (IHV), the table size
can be four or greater.

### `uWEPKeyValueMaxLength`

The maximum length, in bytes, of a WEP cipher key supported by the 802.11 station.

The following table lists the minimum and maximum key lengths, in bytes, for the various WEP cipher
values defined through
[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm).

| WEP cipher | Minimum key length | Maximum key length |
| --- | --- | --- |
| **DOT11_CIPHER_ALGO_WEP40** | 5 | 5 |
| **DOT11_CIPHER_ALGO_WEP104** | 13 | 13 |
| **DOT11_CIPHER_ALGO_WEP** | 13 | Any length supported by the 802.11 station |

### `uPMKIDCacheSize`

The maximum number of entries in the pairwise master key identifier (PMKID) cache supported by the
802.11 station.

If the 802.11 station does not support a PMKID cache, the miniport driver must set this member to
zero. Otherwise, the 802.11 station must support a PMKID cache size of at least three entries.

For more information about the PMKID cache, see
[OID_DOT11_PMKID_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-pmkid-list).

### `uMaxNumPerSTADefaultKeyTables`

The maximum number of per-station default cipher key tables supported by the 802.11 station. It is
recommended that the 802.11 station support at least 32 per-station default cipher key tables.

For more information about per-station default cipher key tables, see
[Per-Station Default Keys](https://learn.microsoft.com/windows-hardware/drivers/network/per-station-default-keys).

### `bStrictlyOrderedServiceClassImplemented`

A Boolean value that, if set to **TRUE**, specifies that the 802.11 station supports the IEEE 802.11
StrictlyOrdered service class for media access control (MAC) service data unit (MSDU) packet delivery.

For more information about the StrictlyOrdered service class, refer to Clause 5.1.3 of the IEEE
802.11-2012 standard.

### `ucSupportedQoSProtocolFlags`

A set of flags that specify the quality of service (QoS) protocols that the NIC implements. This
member is either zero or a bitwise OR combination of the following flags:

#### DOT11_QOS_PROTOCOL_FLAG_WMM

The NIC implements the 802.11 WMM QoS protocol.

#### DOT11_QOS_PROTOCOL_FLAG_11E

The NIC implements the 802.11e QoS protocol.

### `bSafeModeImplemented`

The safe mode support capability of the NIC/miniport driver combination. The operating system
interprets this member differently depending on the value of
**Header.Revision**:

#### Revision = DOT11_EXTSTA_ATTRIBUTES_REVISION_1

The operating system interprets the
**bSafeModeImplemented** member as a Boolean value. If this value is **TRUE**, the NIC implements the
802.11 safe mode of operation. Otherwise, the value is **FALSE**.

#### Revision = DOT11_EXTSTA_ATTRIBUTES_REVISION_2 or higher

The operating system interprets the
**bSafeModeImplemented** member as a bit field with the following possible bit values set:

* If the bit field is set to **DOT11_EXTSTA_ATTRIBUTES_SAFEMODE_OID_SUPPORTED** with no other bits set,
  the miniport driver implements the 802.11 safe mode of operation.
* If the bit field is set to **DOT11_EXTSTA_ATTRIBUTES_SAFEMODE_CERTIFIED**, the NIC/miniport
  combination has received a validation certificate from the National Institute of Standards and
  Technology (NIST) under Federal Information Processing Standards (FIPS) Publication 140-2,
  *Security Requirements for Cryptographic Modules*.

This member is used in conjunction with
[OID_DOT11_SAFE_MODE_ENABLED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-safe-mode-enabled).

### `uNumSupportedCountryOrRegionStrings`

The number of country or region strings supported by the 802.11 station. If the 802.11 station
supports multiple regulatory domains as specified by the IEEE 802.11d-2001 standard, each country or
region string identifies a regulatory domain supported by the 802.11 station.

If the 802.11 station does not support the IEEE 802.11d-2001 standard, the miniport driver must set
**uNumSupportedCountryOrRegionStrings** to zero.

### `pSupportedCountryOrRegionStrings`

A pointer to an array of 802.11d country or region strings that are supported by the 802.11
station. Each entry in the array is formatted as a
[DOT11_COUNTRY_OR_REGION_STRING](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-country-or-region-string) structure.

### `uInfraNumSupportedUcastAlgoPairs`

The number of authentication and cipher algorithms supported by the 802.11 station for sending and
receiving unicast packets when configured for operation in an infrastructure basic service set (BSS)
network. The
**uInfraNumSupportedUcastAlgoPairs** member must be the number of
[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures in
the array referenced by the
**pInfraSupportedUcastAlgoPairs** member.

### `pInfraSupportedUcastAlgoPairs`

A pointer to an array of authentication and cipher algorithms supported by the 802.11 station for
sending and receiving unicast packets in an infrastructure BSS network. Each entry in the array is
formatted as a
[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structure.

### `uInfraNumSupportedMcastAlgoPairs`

The number of authentication and cipher algorithms supported by the 802.11 station for sending and
receiving multicast and broadcast packets when configured for operation in an infrastructure basic
service set (BSS) network. The
**uInfraNumSupportedMcastAlgoPairs** member must be the number of
[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures in
the array referenced by the
**pInfraSupportedMcastAlgoPairs** member.

### `pInfraSupportedMcastAlgoPairs`

A pointer to an array of authentication and cipher algorithms supported by the 802.11 station for
sending and receiving multicast and broadcast packets in an infrastructure BSS network. Each entry in
the array is formatted as a
[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structure.

### `uAdhocNumSupportedUcastAlgoPairs`

The number of authentication and cipher algorithms supported by the 802.11 station for sending and
receiving unicast packets when configured for operation in an independent BSS (IBSS) network. The
**uAdhocNumSupportedUcastAlgoPairs** member must be the number of
[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures in
the array referenced by the
**pAdhocSupportedUcastAlgoPairs** member.

### `pAdhocSupportedUcastAlgoPairs`

A pointer to an array of authentication and cipher algorithms supported by the 802.11 station for
sending and receiving unicast packets in an IBSS network. Each entry in the array is formatted as a
[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structure.

### `uAdhocNumSupportedMcastAlgoPairs`

The number of authentication and cipher algorithms supported by the 802.11 station for sending and
receiving multicast and broadcast packets when configured for operation in an IBSS network. The
**uAdhocNumSupportedMcastAlgoPairs** member must be the number of
[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structures in
the array referenced by the
**pAdhocSupportedMcastAlgoPairs** member.

### `pAdhocSupportedMcastAlgoPairs`

A pointer to an array of authentication and cipher algorithms supported by the 802.11 station for
sending and receiving multicast and broadcast packets in an IBSS network. Each entry in the array is
formatted as a
[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structure.

### `bAutoPowerSaveMode`

The support capability of the NIC/miniport driver combination to autonomously manage power well, including detection and negotiation of proper Wi-Fi Power Save Mode (PSM) between the device and the Wi-Fi Access Point. NDIS 6.30 compliant Wi-Fi miniport drivers should set this member to TRUE.

### `uMaxNetworkOffloadListSize`

The maximum number of networks a miniport driver can offload, if it has the ability to support the Network List Offload capability.

### `bMFPCapable`

The support capability of the NIC/miniport driver to combination to support management frame protection between the device and the Wi-Fi Access Point as specified in the 802.11w-2009 specification. Set to TRUE if supported. Otherwise, this member should be set to FALSE.

### `uInfraNumSupportedMcastMgmtAlgoPairs`

The length of the array of authentication and cipher algorithm pairs pointed to in **pInfraSupportedMcastMgmtAlgoPairs**.

### `pInfraSupportedMcastMgmtAlgoPairs`

A pointer to an array of authentication and cipher algorithm pair which the device supports for MFP in Infra mode. The recommended cipher for Windows 8 is BIP with WPA or WPA2 authentication. Each entry in the array is
formatted as a
[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair) structure.

### `bNeighborReportSupported`

### `bAPChannelReportSupported`

### `bActionFramesSupported`

### `bANQPQueryOffloadSupported`

### `bHESSIDConnectionSupported`

## Syntax

```cpp
typedef struct DOT11_EXTSTA_ATTRIBUTES {
  NDIS_OBJECT_HEADER              Header;
  ULONG                           uScanSSIDListSize;
  ULONG                           uDesiredBSSIDListSize;
  ULONG                           uDesiredSSIDListSize;
  ULONG                           uExcludedMacAddressListSize;
  ULONG                           uPrivacyExemptionListSize;
  ULONG                           uKeyMappingTableSize;
  ULONG                           uDefaultKeyTableSize;
  ULONG                           uWEPKeyValueMaxLength;
  ULONG                           uPMKIDCacheSize;
  ULONG                           uMaxNumPerSTADefaultKeyTables;
  BOOLEAN                         bStrictlyOrderedServiceClassImplemented;
  UCHAR                           ucSupportedQoSProtocolFlags;
  BOOLEAN                         bSafeModeImplemented;
  ULONG                           uNumSupportedCountryOrRegionStrings;
  PDOT11_COUNTRY_OR_REGION_STRING pSupportedCountryOrRegionStrings;
  ULONG                           uInfraNumSupportedUcastAlgoPairs;
  PDOT11_AUTH_CIPHER_PAIR         pInfraSupportedUcastAlgoPairs;
  ULONG                           uInfraNumSupportedMcastAlgoPairs;
  PDOT11_AUTH_CIPHER_PAIR         pInfraSupportedMcastAlgoPairs;
  ULONG                           uAdhocNumSupportedUcastAlgoPairs;
  PDOT11_AUTH_CIPHER_PAIR         pAdhocSupportedUcastAlgoPairs;
  ULONG                           uAdhocNumSupportedMcastAlgoPairs;
  PDOT11_AUTH_CIPHER_PAIR         pAdhocSupportedMcastAlgoPairs;
  BOOLEAN                         bAutoPowerSaveMode;
  ULONG                           uMaxNetworkOffloadListSize;
  BOOLEAN                         bMFPCapable;
  ULONG                           uInfraNumSupportedMcastMgmtAlgoPairs;
  PDOT11_AUTH_CIPHER_PAIR         pInfraSupportedMcastMgmtAlgoPairs;
} DOT11_EXTSTA_ATTRIBUTES, *PDOT11_EXTSTA_ATTRIBUTES;
```

## Remarks

The
[NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_native_802_11_attributes) structure contains a member (**pExtSTAAttributes**) that specifies the address of a DOT11_EXTSTA_ATTRIBUTES structure. When the
miniport driver calls
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes),
the driver sets the
*MiniportAttributes* parameter to the address of a driver-allocated block of memory which contains an
NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES structure along with the DOT11_EXTSTA_ATTRIBUTES
structure.

Management Frame Protection Required (MFPR) enforcement on Windows 8 is not supported. Hence miniport drivers should never set this bit in the RSN capabilities of RSN IE during an association request. For policy, the access point may advertise MFPR which will allow MFP-capable STA to associate. Access points not supporting MFP capability will fail association. If MFPR is set by an access point and STA is not MFP capable, Windows 8 will treat the network as mismatched in capability and not send an association request to the miniport.

## See also

[Extensible Station Operation
Mode](https://learn.microsoft.com/windows-hardware/drivers/network/extensible-station-operation-mode)

[OID_DOT11_DESIRED_BSSID_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-bssid-list)

[OID_DOT11_EXCLUDED_MAC_ADDRESS_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-excluded-mac-address-list)

[OID_DOT11_PMKID_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-pmkid-list)

[OID_DOT11_DESIRED_SSID_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-ssid-list)

[DOT11_COUNTRY_OR_REGION_STRING](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-country-or-region-string)

[OID_DOT11_SAFE_MODE_ENABLED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-safe-mode-enabled)

[OID_DOT11_PRIVACY_EXEMPTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-privacy-exemption-list)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_DOT11_CIPHER_KEY_MAPPING_KEY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-cipher-key-mapping-key)

[DOT11_AUTH_CIPHER_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-dot11_auth_cipher_pair)

[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm)

[Per-Station Default Keys](https://learn.microsoft.com/windows-hardware/drivers/network/per-station-default-keys)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_native_802_11_attributes)

[OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request)