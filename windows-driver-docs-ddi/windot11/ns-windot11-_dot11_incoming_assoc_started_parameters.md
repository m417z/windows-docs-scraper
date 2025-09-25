# _DOT11_INCOMING_ASSOC_STARTED_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_INCOMING_ASSOC_STARTED_PARAMETERS structure specifies that the NIC has received the first
valid 802.11 authentication request from a peer station on an infrastructure BSS.

## Members

### `Header`

The type, revision, and size of the DOT11_INCOMING_ASSOC_STARTED_PARAMETERS structure. This member
is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

| Term | Description |
| --- | --- |
| Type | This member must be set to NDIS_OBJECT_TYPE_DEFAULT. |
| Revision | This member must be set to DOT11_INCOMING_ASSOC_STARTED_PARAMETERS_REVISION_1. |
| Size | This member must be set to **sizeof**(DOT11_INCOMING_ASSOC_STARTED_PARAMETERS). |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `PeerMacAddr`

The media access control (MAC) address of the peer station that sent an 802.11 authentication
request.

## Syntax

```cpp
typedef struct _DOT11_INCOMING_ASSOC_STARTED_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  PeerMacAddr;
} DOT11_INCOMING_ASSOC_STARTED_PARAMETERS, *PDOT11_INCOMING_ASSOC_STARTED_PARAMETERS;
```

## Remarks

The Native 802.11 miniport driver includes a DOT11_INCOMING_ASSOC_STARTED_PARAMETERS structure when
the driver makes an
[NDIS_STATUS_DOT11_INCOMING_ASSOC_STARTED](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-incoming-assoc-started) status indication.

## See also

[NDIS_STATUS_DOT11_INCOMING_ASSOC_STARTED](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-incoming-assoc-started)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)