# _DOT11_INCOMING_ASSOC_DECISION_V2 structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

Information for an incoming association request is included in a **DOT11_INCOMING_ASSOC_DECISION_V2** structure. This structure is sent with an [OID_DOT11_INCOMING_ASSOCIATION_DECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_incoming_assoc_decision_v2) request.

## Members

### `Header`

The type, revision, and size of the **DOT11_INCOMING_ASSOC_DECISION_V2** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_ INCOMING_ASSOC_DECISION_REVISION_2 |
| **Size** | DOT11_SIZEOF_INCOMING_ASSOC_DECISION_REVISION_2 |

### `PeerMacAddr`

The address of the peer station for the 802.11 station connect attempt.

### `bAccept`

The incoming association acceptance. If TRUE, the driver accepts the request. Otherwise, the request is rejected.

### `usReasonCode`

If bAccept == TRUE, the reason code is included in the association response.

### `uAssocResponseIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) that the miniport driver must include in the probe response packet. The probe response is sent to the peer station seeking the association. This offset is from the start of the buffer that contains this structure.

### `uAssocResponseIEsLength`

The length, in bytes, of the array of IEs provided at **uAssocResponseIEsOffset**.

### `WFDStatus`

The status code to include in the Peer-to-Peer (P2P) IE of the association response if **bAccept** is FALSE.

## Syntax

```cpp
typedef struct _DOT11_INCOMING_ASSOC_DECISION_V2 {
  NDIS_OBJECT_HEADER       Header;
  DOT11_MAC_ADDRESS        PeerMacAddr;
  BOOLEAN                  bAccept;
  USHORT                   usReasonCode;
  ULONG                    uAssocResponseIEsOffset;
  ULONG                    uAssocResponseIEsLength;
  DOT11_WFD_STATUS_CODE    WFDStatus;
} DOT11_INCOMING_ASSOC_DECISION_V2, *PDOT11_INCOMING_ASSOC_DECISION_V2;
```

## See also

[OID_DOT11_INCOMING_ASSOCIATION_DECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_incoming_assoc_decision_v2)