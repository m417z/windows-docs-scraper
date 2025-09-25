# _DOT11_RECEIVED_GO_NEGOTIATION_REQUEST_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The parameters for a received Group Owner (GO) negotiation request are specified in a **DOT11_RECEIVED_GO_NEGOTIATION_REQUEST_PARAMETERS** structure. This structure is sent with an [NDIS_STATUS_DOT11_WFD_RECEIVED_GO_NEGOTIATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-go-negotiation-request) indication.

## Members

### `Header`

The type, revision, and size of the **DOT11_RECEIVED_GO_NEGOTIATION_REQUEST_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_RECEIVED_GO_NEGOTIATION_REQUEST_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_RECEIVED_GO_NEGOTIATION_REQUEST_PARAMETERS_REVISION_1 |

### `PeerDeviceAddress`

The Peer-to-Peer (P2P) device address of the Wi-Fi Direct (WFD) device that sent the GO negotiation request.

### `DialogToken`

The dialog token received in the GO negotiation request packet.

### `RequestContext`

The context data from the miniport driver. The system sends this context with the [OID_DOT11_WFD_SEND_GO_NEGOTIATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-go-negotiation-response) request.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) received in the GO negotiation request packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_RECEIVED_GO_NEGOTIATION_REQUEST_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  PeerDeviceAddress;
  DOT11_DIALOG_TOKEN DialogToken;
  PVOID              RequestContext;
  ULONG              uIEsOffset;
  ULONG              uIEsLength;
} DOT11_RECEIVED_GO_NEGOTIATION_REQUEST_PARAMETERS, *PDOT11_RECEIVED_GO_NEGOTIATION_REQUEST_PARAMETERS;
```

## Remarks

If **RequestContext** is a pointer, the data pointed to must remain valid until the call to [NdisMIndicateStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatestatusex) returns.

## See also

[NDIS_STATUS_DOT11_WFD_RECEIVED_GO_NEGOTIATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-go-negotiation-request)

[OID_DOT11_WFD_SEND_GO_NEGOTIATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-go-negotiation-response)