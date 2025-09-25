# _DOT11_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The confirmation parameters for a Group Owner (GO) negotiation response indication are specified in a **DOT11_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS** structure. This structure is sent with an [OID_DOT11_WFD_SEND_GO_NEGOTIATION_CONFIRMATION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-go-negotiation-confirmation) request to the miniport.

## Members

### `Header`

Specifies the type, revision and size of the **DOT11_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS** structure. The required settings for the members of **Header** are the following:

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS_REVISION_1 |

### `PeerDeviceAddress`

The Peer-to-Peer (P2P) address of the Wi-Fi Direct (WFD) device that the GO negotiation confirmation is sent to.

### `DialogToken`

The dialog token received from the GO negotiation response packet. This dialog token must be included in the GO negotiation confirmation packet.

### `ResponseContext`

Miniport context data included in the [NDIS_STATUS_DOT11_WFD_RECEIVED_GO_NEGOTIATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-go-negotiation-response) indication.

### `uSendTimeout`

The maximum time, in milliseconds, allowed to send the GO negotiation response. If the timeout expires before the miniport has successfully transmitted the GO negotiation confirmation, it should indicate the [NDIS_STATUS_DOT11_WFD_GO_NEGOTIATION_CONFIRMATION_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-go-negotiation-confirmation-send-complete) with a failure status.

### `Status`

Status information to include in the GO negotiation confirmation.

### `GroupCapability`

The capability values that are included in the Group Capability bitmask of the Peer-to-Peer (P2P) Capability Information Element (IE) in a GO negotiation confirmation.

### `GroupID`

The group identifier to include in the Group ID attribute of the GO negotiation confirmation.

### `bUseGroupID`

If TRUE, the value in **GroupID** should be included in the GO negotiation confirmation.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) the Wi-Fi Direct (WFD) port must add to the GO negotiation confirmation packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS {
  NDIS_OBJECT_HEADER         Header;
  DOT11_MAC_ADDRESS          PeerDeviceAddress;
  DOT11_DIALOG_TOKEN         DialogToken;
  PVOID                      ResponseContext;
  ULONG                      uSendTimeout;
  DOT11_WFD_STATUS_CODE      Status;
  DOT11_WFD_GROUP_CAPABILITY GroupCapability;
  DOT11_WFD_GROUP_ID         GroupID;
  BOOLEAN                    bUseGroupID;
  ULONG                      uIEsOffset;
  ULONG                      uIEsLength;
} DOT11_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS, *PDOT11_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS;
```

## See also

[NDIS_STATUS_DOT11_WFD_RECEIVED_GO_NEGOTIATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-go-negotiation-response)

[OID_DOT11_WFD_SEND_GO_NEGOTIATION_CONFIRMATION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-go-negotiation-confirmation)

[NDIS_STATUS_DOT11_WFD_GO_NEGOTIATION_CONFIRMATION_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-go-negotiation-confirmation-send-complete)