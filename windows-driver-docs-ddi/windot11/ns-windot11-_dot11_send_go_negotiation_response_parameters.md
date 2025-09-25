# _DOT11_SEND_GO_NEGOTIATION_RESPONSE_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The parameters for a response to a Group Owner (GO) negotiation request are specified in a **DOT11_SEND_GO_NEGOTIATION_RESPONSE_PARAMETERS** structure. This structure is sent with an [OID_DOT11_WFD_SEND_INVITATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-invitation-response) request to the miniport.

## Members

### `Header`

The type, revision, and size of the **DOT11_SEND_GO_NEGOTIATION_RESPONSE_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_SEND_GO_NEGOTIATION_RESPONSE_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_SEND_GO_NEGOTIATION_RESPONSE_PARAMETERS_REVISION_1 |

### `PeerDeviceAddress`

The Peer-to-Peer (P2P) address of the Wi-Fi Direct (WFD) device that originated the GO negotiation request.

### `DialogToken`

The dialog token received from the GO negotiation request packet. This dialog token must be included in the GO negotiation response packet.

### `RequestContext`

### `uSendTimeout`

The maximum time, in milliseconds, allowed to send the GO negotiation response. If the time-out expires before the miniport has successfully transmitted the GO negotiation response, it should indicate the [NDIS_STATUS_DOT11_WFD_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-go-negotiation-response-send-complete) with a failure status.

### `Status`

The status information to include in the GO negotiation response.

### `GroupOwnerIntent`

The value for GO intent. This should be included in the Group Owner Intent attribute of the GO negotiation request.

### `MinimumConfigTimeout`

The configuration time-out required by the system to change its mode of operation to a P2P Group Owner or a P2P Client. The miniport driver can set this with a larger value if necessary.

### `IntendedInterfaceAddress`

The P2P interface address that is intended for the P2P group.

### `GroupCapability`

The capability values that are included in the Group Capability bitmask of the P2P Capability Information Element (IE) in the GO negotiation response.

### `GroupID`

The group identifier to include in the Group ID attribute of the GO negotiation response.

### `bUseGroupID`

If TRUE, the value in **GroupID** should be included in the GO negotiation response.

### `uIEsOffset`

The offset, in bytes, of the array of additional IEs that the Wi-Fi Direct (WFD) port must add to the GO negotiation response packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

### `ResponseContext`

Miniport context data included in the [NDIS_STATUS_DOT11_WFD_RECEIVED_GO_NEGOTIATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-go-negotiation-request) indication.

## Syntax

```cpp
typedef struct _DOT11_SEND_GO_NEGOTIATION_RESPONSE_PARAMETERS {
  NDIS_OBJECT_HEADER              Header;
  DOT11_MAC_ADDRESS               PeerDeviceAddress;
  DOT11_DIALOG_TOKEN              DialogToken;
  PVOID                           ResponseContext;
  ULONG                           uSendTimeout;
  DOT11_WFD_STATUS_CODE           Status;
  DOT11_WFD_GO_INTENT             GroupOwnerIntent;
  DOT11_WFD_CONFIGURATION_TIMEOUT MinimumConfigTimeout;
  DOT11_MAC_ADDRESS               IntendedInterfaceAddress;
  DOT11_WFD_GROUP_CAPABILITY      GroupCapability;
  DOT11_WFD_GROUP_ID              GroupID;
  BOOLEAN                         bUseGroupID;
  ULONG                           uIEsOffset;
  ULONG                           uIEsLength;
} DOT11_SEND_GO_NEGOTIATION_RESPONSE_PARAMETERS, *PDOT11_SEND_GO_NEGOTIATION_RESPONSE_PARAMETERS;
```

## See also

[NDIS_STATUS_DOT11_WFD_RECEIVED_GO_NEGOTIATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-go-negotiation-request)

[OID_DOT11_WFD_SEND_INVITATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-invitation-response)