# DOT11_BSS_ENTRY structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_BSS_ENTRY structure defines an IEEE 802.11 Beacon or Response Frame that the 802.11 station
received during its last scan operation.

## Members

### `uPhyId`

The identifier (ID) of the PHY that the 802.11 station used to detect the BSS network. The PHY ID
is the index within the list of supported PHYs returned by the driver through a query of
[OID_DOT11_SUPPORTED_PHY_TYPES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-phy-types).

This ID must not be DOT11_PHY_ID_ANY.

### `PhySpecificInfo`

The attributes of the PHY referenced by the
**uPhyId** member.
**PhySpecificInfo** is formatted as a
[DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_bss_entry_phy_specific_info) union.

### `dot11BSSID`

The media access control (MAC) address of the access point (AP) (for infrastructure BSS networks)
or peer station (for independent BSS networks) that sent the 802.11 Beacon or Probe Response frame
received by the 802.11 station while scanning. The data type for this member is the
[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address) structure.

### `dot11BSSType`

The BSS network type.

The data type for this member is the
[DOT11_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_bss_type) enumeration. The miniport
driver must not set this member to the
**dot11_BSS_type_any** value.

### `lRSSI`

The received signal strength indicator (RSSI) value, in units of decibels referenced to 1.0
milliwatts (dBm), as detected by the 802.11 station for the AP or peer station.

### `uLinkQuality`

The link quality value ranging from 0 through 100. A value of 100 specifies the highest link
quality. For more information about determining the link quality, see
[Link Quality Operations](https://learn.microsoft.com/windows-hardware/drivers/network/link-quality-operations).

### `bInRegDomain`

This member specifies whether the AP or peer station is operating within the regulatory domain as
identified by the input country string. To set this member, the miniport driver must use the following
guidelines:

* If the 802.11 station does not support multiple regulatory domains, set the member to **TRUE**. For
  more information about multiple regulatory domains, see
  [OID_DOT11_MULTI_DOMAIN_CAPABILITY_IMPLEMENTED](https://learn.microsoft.com/previous-versions/ms893670(v=msdn.10)).
* If the input country string is all zeros, set the member to **TRUE**.
* If the AP or peer station is not operating on a channel that is valid for the regulatory domain
  specified by the input country string, set the member to **FALSE**.
* If the 802.11 Beacon or Probe Response frame, which was received from the AP or peer station,
  doesn't include a Country information element (IE), set the member to **TRUE**.

  For more information about the Country IE, refer to Clause 7.3.2.12 of the IEEE 802.11d-2001
  standard.
* If the 802.11 Beacon or Probe Response frame, which was received from the AP or peer station, does
  include a Country IE, set the member to **FALSE** if the value of the Country String subfield does not
  equal the input country string.
* Set the member to **TRUE** in all other cases.

### `usBeaconPeriod`

The value of the Beacon Interval field from the 802.11 Beacon or Probe Response frame.

### `ullTimestamp`

The value of the Timestamp field from the 802.11 Beacon or Probe Response frame.

### `ullHostTimestamp`

The timestamp, resolved through a call to
[NdisGetCurrentSystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetcurrentsystemtime), which
records when the 802.11 station received the 802.11 Beacon or Probe Response frame.

### `usCapabilityInformation`

The value of the Capability Information field from the 802.11 Beacon or Probe Response
frame.

### `uBufferLength`

The length, in bytes, of the
**ucBuffer** array in the DOT11_BSS_ENTRY structure.
**ulBufferLength** must be the exact length of the data in the
**ucBuffer** array and must not contain any padding for alignment.

### `ucBuffer`

The variable-length information elements (IEs) from the 802.11 Beacon or Probe Response frames.
For each BSS, the IEs must be from the last Beacon or Probe Response frame received from that BSS
network. If an IE is available in only one frame, the miniport driver must merge the IE with the other
IEs from the last received Beacon or Probe Response frame.

When the NIC is in the Extensible Access Point (ExtAP) OP mode, the BSS list should contain an entry
for the BSS that the NIC created.

For more information about the fields within IEEE 802.11 Beacon or Probe Response frames, refer to
Clause 8.4 of the IEEE 802.11-2012 standard.

## Syntax

```cpp
typedef struct DOT11_BSS_ENTRY {
  ULONG                             uPhyId;
  DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO PhySpecificInfo;
  DOT11_MAC_ADDRESS                 dot11BSSID;
  DOT11_BSS_TYPE                    dot11BSSType;
  LONG                              lRSSI;
  ULONG                             uLinkQuality;
  BOOLEAN                           bInRegDomain;
  USHORT                            usBeaconPeriod;
  ULONGLONG                         ullTimestamp;
  ULONGLONG                         ullHostTimestamp;
  USHORT                            usCapabilityInformation;
  ULONG                             uBufferLength;
  UCHAR                             ucBuffer[1];
} DOT11_BSS_ENTRY, *PDOT11_BSS_ENTRY;
```

## Remarks

When the 802.11 station performs a scan operation, the Native 802.11 miniport driver caches the
received 802.11 Beacon and Probe Response frames. For more information about the scan operation, see
[Native 802.11 Scan
Operations](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-scan-operations).

After the 802.11 station completes the scan operation, the miniport driver returns the list of the
cached Beacon and Probe Response frames when queried by
[OID_DOT11_ENUM_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-enum-bss-list). A separate
DOT11_BSS_ENTRY structure is formatted for each Beacon and Probe Response frame.

## See also

[DOT11_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_bss_type)

[DOT11_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_bss_list)

[OID_DOT11_SUPPORTED_PHY_TYPES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-phy-types)

[OID_DOT11_MULTI_DOMAIN_CAPABILITY_IMPLEMENTED](https://learn.microsoft.com/previous-versions/ms893670(v=msdn.10))

[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address)

[DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_bss_entry_phy_specific_info)

[NdisGetCurrentSystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetcurrentsystemtime)

[OID_DOT11_ENUM_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-enum-bss-list)