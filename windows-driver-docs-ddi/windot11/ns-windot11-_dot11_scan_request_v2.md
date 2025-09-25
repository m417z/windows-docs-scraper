# _DOT11_SCAN_REQUEST_V2 structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_SCAN_REQUEST_V2 structure defines the parameters for the explicit scan operation performed by the 802.11 station. The station performs the explicit scan operation following an OID set request of [OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request).

## Members

### `dot11BSSType`

The type of basic service set (BSS) networks for which the 802.11 station scans. The data type for this member is the [DOT11_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_bss_type) enumeration.

### `dot11BSSID`

The BSS identifier (BSSID) of a BSS network for which the 802.11 station scans. If this member is
set to the wildcard BSSID (0xFFFFFFFFFFFF), the station scans for all BSSIDs.

### `dot11ScanType`

The type of scan that the 802.11 station performs. The data type for this member is the
DOT11_SCAN_TYPE enumeration, which declares the following values:

#### dot11_scan_type_active

The station transmits an 802.11 Probe Request frame on each channel that it scans. It dwells on
the channel long enough to receive 802.11 Probe Response frames for its Probe Request. The station
also receives 802.11 Beacon frames sent on the channel.

#### dot11_scan_type_passive

The station does not transmit an 802.11 Probe Request frame on each channel that it scans.
Instead, it receives 802.11 Beacon or Probe Request frames sent on the channel.

#### dot11_scan_type_auto

The station can perform active or passive scans, or it can use a combination of both scan
types.

Regardless of the value of **dot11ScanType**, the 802.11 station must perform a scan type of **dot11_scan_type_passive** whenever it scans on channels that are not valid in the current regulatory domain. Also, the 802.11 station must perform a scan type of **dot11_scan_type_passive** if it does not have a default regulatory domain. For more information about regulatory domains, see [OID_DOT11_CURRENT_REG_DOMAIN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-current-reg-domain).

If the
**dot11_scan_type_forced** bit is set in the
**dot11ScanType** member, the 802.11 station must perform a complete scan on every supported channel.
If the
**dot11_scan_type_forced** bit is not set, the 802.11 station can perform a complete scan, or it can
perform a partial scan on a subset of the supported channels.

**Note** The
**dot11_scan_type_forced** bit is only supported when the miniport driver is operating in Extensible
Station (ExtSTA) mode. The
**dot11_scan_type_forced** bit must be set through a bitwise OR with a DOT11_SCAN_TYPE
value.

### `bRestrictedScan`

If this member is **TRUE**, the 802.11 station performs a scan restricted to the channel and PHY
configuration used to connect to a BSS network.

The miniport driver must ignore this member if any of the following are true:

* The miniport driver is operating in ExtSTA mode.
* The 802.11 station is not connected to a BSS network.

### `udot11SSIDsOffset`

The offset in the
**ucBuffer** array where the service set identifier (SSID) list begins. Each entry in the SSID list is
formatted as a
[DOT11_SSID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-_dot11_ssid) structure.

The 802.11 station scans for each SSID in the list. For example, if
**dot11ScanType** is set to
**dot11_scan_type_active**, the 802.11 station transmits an 802.11 Probe Request for each SSID in the
list while scanning on a channel.

### `uNumOfdot11SSIDs`

The number of entries in the SSID list.

If
**uNumOfdot11SSIDs** is zero, the miniport driver must use an SSID list containing the wildcard
zero-length SSID.

### `bUseRequestIE`

If this member is **TRUE**, the 802.11 station must include the list of request IDs (defined through
the
**uRequestIDsOffset** and
**uNumOfRequestIDs** members) within the 802.11d request information element (IE) of each Probe
Request frame that it transmits during the active scan.

The miniport driver must ignore this member (along with the
**uRequestIDsOffset** and
**uNumOfRequestIDs** members) if any of the following are true:

* The miniport driver is operating in ExtSTA mode.
* The 802.11
  **dot11MultiDomainCapabilityEnabled** management information base (MIB) object is **FALSE**. For more
  information about the
  **dot11MultiDomainCapabilityEnabled** MIB object, see
  [OID_DOT11_MULTI_DOMAIN_CAPABILITY_ENABLED](https://learn.microsoft.com/previous-versions/windows/embedded/ee486712(v=winembedded.80)).
* The
  **dot11ScanType** member is set to
  **dot11_scan_type_passive**.

### `uRequestIDsOffset`

The offset in the
**ucBuffer** array where the Request IDs list begins. Each entry in the request IDs list is formatted
as a UCHAR data type.

### `uNumOfRequestIDs`

The number of entries in the request IDs list.

### `uPhyTypeInfosOffset`

The offset in the
**ucBuffer** array where the list of PHY types begins. Each entry in the list of PHY types is
formatted as a
[DOT11_PHY_TYPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_phy_type_info) structure.

The 802.11 station must perform the BSS scan by using each of the specified PHY types from this
list.

The miniport driver must ignore this member (along with the
**uNumOfPhyTypeInfos** member) if
**bRestrictedScan** is set to **TRUE**.

### `uNumOfPhyTypeInfos`

The number of entries in the list of PHY types.

If
**uNumOfPhyTypeInfos** is zero, the 802.11 station performs the scan using all of its supported
PHYs.

### `uIEsOffset`

The offset in the
**ucBuffer** array where the list of variable-length information elements (IEs) begins. The 802.11
station must append the list of IEs to the end of each Probe Request frame that it transmits during an
active scan.

The miniport driver must ignore this member (along with the
**uIEsLength** member) if
**dot11ScanType** is set to
**dot11_scan_type_passive**.

### `uIEsLength`

The length, in bytes, of the list of IEs.

### `ucBuffer`

The buffer containing optional data as specified through other members of this structure.

## Syntax

```cpp
typedef struct _DOT11_SCAN_REQUEST_V2 {
  DOT11_BSS_TYPE    dot11BSSType;
  DOT11_MAC_ADDRESS dot11BSSID;
  DOT11_SCAN_TYPE   dot11ScanType;
  BOOLEAN           bRestrictedScan;
  ULONG             udot11SSIDsOffset;
  ULONG             uNumOfdot11SSIDs;
  BOOLEAN           bUseRequestIE;
  ULONG             uRequestIDsOffset;
  ULONG             uNumOfRequestIDs;
  ULONG             uPhyTypeInfosOffset;
  ULONG             uNumOfPhyTypeInfos;
  ULONG             uIEsOffset;
  ULONG             uIEsLength;
  UCHAR             ucBuffer[1];
} DOT11_SCAN_REQUEST_V2, *PDOT11_SCAN_REQUEST_V2;
```

## Remarks

The 802.11 station performs explicit scan operations following the OID set request of
[OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request). The station
performs the scan operation by using the parameters defined through the DOT11_SCAN_REQUEST_V2, which
accompanies the set request.

For more information about the scan operations performed by a Native 802.11 miniport driver, see
[Native 802.11 Scan
Operations](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-scan-operations).

For more information about the ExtSTA operation mode, see
[Extensible Station Operation
Mode](https://learn.microsoft.com/windows-hardware/drivers/network/extensible-station-operation-mode).

## See also

[DOT11_PHY_TYPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_phy_type_info)

[OID_DOT11_SCAN_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-scan-request)