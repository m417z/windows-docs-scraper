# _DOT11_INCOMING_ASSOC_DECISION structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_INCOMING_ASSOC_DECISION structure specifies the miniport driver's decision whether to
accept an incoming association request from a peer station on an infrastructure BSS.

## Members

### `Header`

The type, revision, and size of the DOT11_INCOMING_ASSOC_DECISION structure. This member is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

| Value | Meaning |
| --- | --- |
| **Type** | This member must be set to NDIS_OBJECT_TYPE_DEFAULT. |
| **Revision** | This member must be set to DOT11_INCOMING_ASSOC_DECISION_REVISION_1. |
| **Size** | This member must be set to `sizeof(DOT11_INCOMING_ASSOC_DECISION)`. |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `PeerMacAddr`

The media access control (MAC) address of the peer station that the 802.11 station attempted to
connect to.

### `bAccept`

A Boolean value that indicates whether the miniport driver accepts the incoming association
request. If **TRUE**, the driver instructs the NIC to accept the association request. Otherwise, the NIC
should reject the request.

### `usReasonCode`

A USHORT value that represents a reason code to include in the NIC's association response if
**bAccept** is **FALSE**.

### `uAssocResponseIEsOffset`

The offset of the additional information elements (IEs), in bytes, which the NIC must add to the
association response frame that it sends to the peer station that seeks association. This offset is relative
to the start of the buffer that contains the DOT11_INCOMING_ASSOC_DECISION structure. The default value
is zero.

### `uAssocResponseIEsLength`

The length of the additional information elements (IEs), in bytes, which the NIC must add to the
probe response frame that it sends to the peer station that seeks association. The default value is
zero.

## Syntax

```cpp
typedef struct _DOT11_INCOMING_ASSOC_DECISION {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  PeerMacAddr;
  BOOLEAN            bAccept;
  USHORT             usReasonCode;
  ULONG              uAssocResponseIEsOffset;
  ULONG              uAssocResponseIEsLength;
} DOT11_INCOMING_ASSOC_DECISION, *PDOT11_INCOMING_ASSOC_DECISION;
```

## Remarks

This structure is used with
[OID_DOT11_INCOMING_ASSOCIATION_DECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_incoming_assoc_decision_v2).

## See also

[OID_DOT11_INCOMING_ASSOCIATION_DECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_incoming_assoc_decision_v2)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)