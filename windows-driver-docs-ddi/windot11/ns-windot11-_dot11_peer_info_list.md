# _DOT11_PEER_INFO_LIST structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_PEER_INFO_LIST structure specifies a list of [DOT11_PEER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_peer_info) structures that specify information about all peer stations within an independent basic service set (IBSS) network.

**Note** IBSS (Ad hoc) and SoftAP are deprecated. Starting with Windows 8.1 and Windows Server 2012 R2, use [Wi-Fi Direct](https://learn.microsoft.com/windows-hardware/drivers/partnerapps/wi-fi-direct).

## Members

### `Header`

The type, revision, and size of the DOT11_PEER_INFO_LIST structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of **Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_PEER_INFO_LIST_REVISION_1.

#### Size

This member must be set to
sizeof(DOT11_PEER_INFO_LIST).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uNumOfEntries`

The number of entries in the
**PeerInfo** array.

### `uTotalNumOfEntries`

The maximum number of entries that the
**PeerInfo** array can contain.

### `PeerInfo`

An array that specifies the list of
[DOT11_PEER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_peer_info) structures that specify
information on all peer stations within an IBSS network. Each station is represented by a
DOT11_PEER_INFO structure.

## Syntax

```cpp
typedef struct _DOT11_PEER_INFO_LIST {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumOfEntries;
  ULONG              uTotalNumOfEntries;
  DOT11_PEER_INFO    PeerInfo[1];
} DOT11_PEER_INFO_LIST, *PDOT11_PEER_INFO_LIST;
```

## Remarks

This structure is used with
[OID_DOT11_ENUM_PEER_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-enum-peer-info).

## See also

[OID_DOT11_ENUM_PEER_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-enum-peer-info)

[DOT11_PEER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_peer_info)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)