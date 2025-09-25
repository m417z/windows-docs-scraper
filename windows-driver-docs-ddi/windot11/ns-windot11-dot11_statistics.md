# DOT11_STATISTICS structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_STATISTICS structure records statistical counters for the 802.11 interface.

## Members

### `Header`

The type, revision, and size of the DOT11_STATISTICS structure. This member is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_STATISTICS_REVISION_1.

#### Size

This member must be set to `sizeof(DOT11_STATISTICS)`.

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `ullFourWayHandshakeFailures`

The number of four-way handshake failures that the 802.11 station encountered during Wi-Fi
Protected Access (WPA) or Robust Security Network Association (RSNA) authentication.

If the 802.11 station is not performing the WPA or RSNA authentication, it should set this member to
DOT11_STATISTICS_UNKNOWN.

### `ullTKIPCounterMeasuresInvoked`

The number of times that the 802.11 station invoked countermeasures following a message integrity
code (MIC) failure.

If the 802.11 station is not performing TKIP countermeasures, it should set this member to
DOT11_STATISTICS_UNKNOWN.

### `ullReserved`

This member is reserved for use by the operating system. The miniport driver must not write to
this member.

### `MacUcastCounters`

The MAC layer counters based on unicast packets sent or received by the 802.11 station. The data
structure for this member is the
[DOT11_MAC_FRAME_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_mac_frame_statistics) structure.

**Note**

Counters for received unicast packets must only be incremented for those packets with a
destination MAC address in the 802.11 MAC header that matches the 802.11 station's MAC
address.

### `MacMcastCounters`

The MAC layer counters based on multicast or broadcast packets sent or received by the 802.11
station. The data structure for this member is the
[DOT11_MAC_FRAME_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_mac_frame_statistics) structure.

**Note**

Counters for received multicast or broadcast packets must only be incremented for those
packets with a destination MAC address in the 802.11 MAC header that matches an entry in the multicast
address list of the 802.11 station. For more information about the multicast address list, see
[OID_DOT11_MULTICAST_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-multicast-list).

### `PhyCounters`

An array of PHY layer counters. Each entry in this array is formatted as a
[DOT11_PHY_FRAME_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_frame_statistics) structure.

The miniport driver must maintain an entry within the
**PhyCounters** array for each supported PHY. If the 802.11 station supports multiple PHYs of the same
type, the miniport driver must create separate entries for each.

Entries within the
**PhyCounters** array must be in the same order as the list of supported PHYs that the driver returns
when queried by
[OID_DOT11_SUPPORTED_PHY_TYPES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-phy-types).

## Syntax

```cpp
typedef struct DOT11_STATISTICS {
  NDIS_OBJECT_HEADER         Header;
  ULONGLONG                  ullFourWayHandshakeFailures;
  ULONGLONG                  ullTKIPCounterMeasuresInvoked;
  ULONGLONG                  ullReserved;
  DOT11_MAC_FRAME_STATISTICS MacUcastCounters;
  DOT11_MAC_FRAME_STATISTICS MacMcastCounters;
  DOT11_PHY_FRAME_STATISTICS PhyCounters[1];
} DOT11_STATISTICS, *PDOT11_STATISTICS;
```

## Remarks

The miniport driver must unconditionally set all of the counters in the DOT11_STATISTICS structure to
zero, including MAC-layer and PHY-layer counters, when one of the following occurs:

* The driver's
  [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function is
  called.
* The driver's
  [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function is
  called with an OID set request of [OID_DOT11_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-reset-request),
  regardless of the type of reset operation specified in the set request.

For more information about the statistics gathered by a Native 802.11 miniport driver, see
[Native 802.11 Statistics](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-statistics).

## See also

[OID_DOT11_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-statistics)