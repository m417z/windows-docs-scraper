# _DOT11_PEER_INFO structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_PEER_INFO structure specifies information on a peer station within an independent basic
service set (IBSS) network.

**Note** IBSS (Ad hoc) and SoftAP are deprecated. Starting with Windows 8.1 and Windows Server 2012 R2, use [Wi-Fi Direct](https://learn.microsoft.com/windows-hardware/drivers/partnerapps/wi-fi-direct).

## Members

### `MacAddress`

The media access control (MAC) address of the peer station within an independent BSS (IBSS)
network.

### `usCapabilityInformation`

The 802.11 Capability Information field from the beacon or probe response frames that the 802.11
station most recently received from the peer.

### `AuthAlgo`

The authentication algorithm that the 802.11 station resolved with the peer station during the
association operation. For more information about the data type for the
**AuthAlgo** member, see
[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm).

This member is not defined if the peer is not associated.

### `UnicastCipherAlgo`

The unicast cipher algorithm that the 802.11 station resolved with the peer station during the
association operation. For more information about the data type for the
**UnicastCipherAlgo** member, see
[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm).

This member is not defined if the peer is not associated.

### `MulticastCipherAlgo`

The multicast cipher algorithm that the 802.11 station resolved with the peer station during the
association operation. For more information about the data type for the
**MulticastCipherAlgo** member, see
[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm).

This member is not defined if the peer is not associated.

### `bWpsEnabled`

A Boolean value that indicates whether WiFi Protected Setup (WPS) is enabled for the peer station.
If **TRUE**, WPS is enabled, and the authentication and cipher algorithms that are used by the peer might be
different from the algorithms that are enabled on the AP.

This member should not be used if the peer is not associated.

### `usListenInterval`

A USHORT value that defines the 802.11 Listen Interval field that was obtained from the
association request.

This member has a value of zero if the peer is not associated.

### `ucSupportedRates`

A UCHAR value that specifies the data rates supported by the peer station. These rates are based
on the 802.11 Supported Rates IE from the beacon or probe response frames that the 802.11 station most
recently received from the peer.

Each entry in the
**ucPeerSupportedRates** array is the value of an index within the table of data rates returned
through a query of
[OID_DOT11_DATA_RATE_MAPPING_TABLE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-data-rate-mapping-table). The index value must be between 2 and 127.

This member has a value of zero if the peer is not associated.

### `usAssociationID`

A USHORT value that specifies the 802.11 Association ID field from the association or
re-association response frames that the 802.11 station received from the AP.

This member has a value of 0xFFFF if the peer is not associated.

### `AssociationState`

A
[DOT11_ASSOCIATION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_association_state)-type value
that indicates the 802.11 authentication and association state of the peer station. The state can be
either
**dot11_assoc_state_auth_unassoc** or
**dot11_assoc_state_auth_assoc**.

In the
*IEEE 802.11 Standard*, the 802.11 authentication procedure is optional for an independent network.
Therefore, depending upon the IHV implementation, the state represented by the
**dot11_assoc_state_auth_unassoc** enumeration value may not be applicable.

### `PowerMode`

A
[DOT11_POWER_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_power_mode)-type value that describes
the latest power management mode of the peer station.

### `liAssociationUpTime`

A LARGEINTEGER value that specifies the timestamp when the 802.11 association procedure successfully
completed. The miniport driver calls
[NdisGetCurrentSystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetcurrentsystemtime) to get
the timestamp of the association completion.

This member has a value of zero if the peer is not associated.

### `Statistics`

The statistics counters for data traffic, defined by the
[DOT11_PEER_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_peer_statistics) structure.

This member has a value of zero if the peer is not associated.

## Syntax

```cpp
typedef struct _DOT11_PEER_INFO {
  DOT11_MAC_ADDRESS       MacAddress;
  USHORT                  usCapabilityInformation;
  DOT11_AUTH_ALGORITHM    AuthAlgo;
  DOT11_CIPHER_ALGORITHM  UnicastCipherAlgo;
  DOT11_CIPHER_ALGORITHM  MulticastCipherAlgo;
  BOOLEAN                 bWpsEnabled;
  USHORT                  usListenInterval;
  UCHAR                   ucSupportedRates[MAX_NUM_SUPPORTED_RATES_V2];
  USHORT                  usAssociationID;
  DOT11_ASSOCIATION_STATE AssociationState;
  DOT11_POWER_MODE        PowerMode;
  LARGE_INTEGER           liAssociationUpTime;
  DOT11_PEER_STATISTICS   Statistics;
} DOT11_PEER_INFO, *PDOT11_PEER_INFO;
```

## See also

[DOT11_POWER_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_power_mode)

[DOT11_ASSOCIATION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-_dot11_association_state)

[NdisGetCurrentSystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetcurrentsystemtime)

[DOT11_PEER_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_peer_statistics)

[DOT11_PEER_INFO_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_peer_info_list)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)