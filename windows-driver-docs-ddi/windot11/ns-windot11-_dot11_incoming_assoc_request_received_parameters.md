# _DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS structure specifies the results of the
acceptance procedure of the 802.11 station after it receives an incoming association request, or
re-association request, from a peer station on an infrastructure BSS.

## Members

### `Header`

The type, revision, and size of the DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS structure.
This member is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS_REVISION_1.

#### Size

This member must be set to
**sizeof**(DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `PeerMacAddr`

The media access control (MAC) address of the peer station that sent an association
request.

### `bReAssocReq`

For nonzero values of
**uStatus**,
**bReAssocReq** is **TRUE** if the request from the peer station is a re-association request.

### `uAssocReqOffset`

For nonzero values of
**uStatus**, this member specifies the offset of the request frame that is used in the association
operation. The frame includes information elements (IEs) but does not include the 802.11 MAC
header.

### `uAssocReqSize`

For nonzero values of
**uStatus**, this member specifies the length, in bytes, of the request frame that is used in the
association operation. The frame includes information elements (IEs) but does not include the 802.11 MAC
header.

## Syntax

```cpp
typedef struct _DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  PeerMacAddr;
  BOOLEAN            bReAssocReq;
  ULONG              uAssocReqOffset;
  ULONG              uAssocReqSize;
} DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS, *PDOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS;
```

## Remarks

The Native 802.11 miniport driver includes a DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS
structure when the driver makes an
[NDIS_STATUS_DOT11_INCOMING_ASSOC_REQUEST_RECEIVED](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-incoming-assoc-request-received) status indication.

## See also

[NDIS_STATUS_DOT11_INCOMING_ASSOC_REQUEST_RECEIVED](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-incoming-assoc-request-received)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)