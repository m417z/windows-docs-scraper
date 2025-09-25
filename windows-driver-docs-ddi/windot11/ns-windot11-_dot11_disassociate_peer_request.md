# _DOT11_DISASSOCIATE_PEER_REQUEST structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_DISASSOCIATE_PEER_REQUEST structure specifies a disassociation operation in which the NIC
disassociates from a peer station.

## Members

### `Header`

The type, revision, and size of the DOT11_DISASSOCIATE_PEER_REQUEST structure. This member is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_DISASSOCIATE_PEER_REQUEST_REVISION_1.

#### Size

This member must be set to
**sizeof**(DOT11_DISASSOCIATE_PEER_REQUEST).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `PeerMacAddr`

The media access control (MAC) address of the peer station that the 802.11 station is to
disassociate from. If
**PeerMacAddr** has a value of 0xFF, the 802.11 station must disassociate from all
associated stations. When
**PeerMacAddr** is a unicast address, the 802.11 station must disassociate from a
specific station.

### `usReason`

A USHORT value that specifies the reason code field in the disassociation frame that is sent by
the 802.11 miniport driver.

## Syntax

```cpp
typedef struct _DOT11_DISASSOCIATE_PEER_REQUEST {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  PeerMacAddr;
  USHORT             usReason;
} DOT11_DISASSOCIATE_PEER_REQUEST, *PDOT11_DISASSOCIATE_PEER_REQUEST;
```

## Remarks

This structure is used with
[OID_DOT11_DISASSOCIATE_PEER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-disassociate-peer-request).

## See also

[OID_DOT11_DISASSOCIATE_PEER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-disassociate-peer-request)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)