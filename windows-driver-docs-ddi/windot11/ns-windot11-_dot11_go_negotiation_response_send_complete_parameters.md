# _DOT11_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The completion parameters for a Group Owner (GO) negotiation response are specified in a **DOT11_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE_PARAMETERS** structure. This structure is sent with an [NDIS_STATUS_DOT11_WFD_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-go-negotiation-response-send-complete) request to the miniport.

## Members

### `Header`

The type, revision, and size of the **DOT11_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE_PARAMETERS_REVISION_1 |

### `PeerDeviceAddress`

The device address of the Peer-to-Peer (P2P) Wi-Fi Direct (WFD) device that the GO negotiation response was sent to.

### `DialogToken`

The dialog token from the GO negotiation response packet. This must match the dialog token sent with the [OID_DOT11_WFD_SEND_GO_NEGOTIATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-go-negotiation-response) request.

### `Status`

The status of the send attempt. Set to **NDIS_STATUS_SUCCESS** if the packet was successfully transmitted.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) that were included in the GO negotiation response packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  PeerDeviceAddress;
  DOT11_DIALOG_TOKEN DialogToken;
  NDIS_STATUS        Status;
  ULONG              uIEsOffset;
  ULONG              uIEsLength;
} DOT11_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE_PARAMETERS, *PDOT11_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE_PARAMETERS;
```

## See also

[NDIS_STATUS_DOT11_WFD_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-go-negotiation-response-send-complete)

[OID_DOT11_WFD_SEND_GO_NEGOTIATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-go-negotiation-response)