# _DOT11_SEND_INVITATION_RESPONSE_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The parameters for a response to an invitation request are specified in a **DOT11_SEND_INVITATION_RESPONSE_PARAMETERS** structure. This structure is sent with an [OID_DOT11_WFD_SEND_INVITATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-invitation-response) request to the miniport.

## Members

### `Header`

Specifies the type, revision and size of the **DOT11_SEND_INVITATION_RESPONSE_PARAMETERS** structure. The required settings for the members of **Header** are the following:

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_SEND_INVITATION_RESPONSE_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_SEND_INVITATION_RESPONSE_PARAMETERS_REVISION_1 |

### `ReceiverDeviceAddress`

The sender address received from the invitation request packet. This is the device address where the invitation response will be sent.

### `DialogToken`

The dialog token received from the invitation request packet. This dialog token will be used in the invitation response packet.

### `RequestContext`

Miniport context data included in the [NDIS_STATUS_DOT11_WFD_RECEIVED_INVITATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-invitation-request) indication.

### `uSendTimeout`

The maximum time, in milliseconds, allowed to send the invitation response. If the timeout expires before the miniport has successfully transmitted the provision discovery response, it should indicate the [NDIS_STATUS_DOT11_WFD_INVITATION_RESPONSE_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-invitation-response-send-complete) with a failure status.

### `Status`

Status information to include in the invitation response.

### `MinimumConfigTimeout`

The configuration timeout required by the system to change its mode of operation to a Peer-to-Peer (P2P) Group Owner or a P2P Client. The miniport driver can set this with a larger value if necessary.

### `GroupBSSID`

The BSSID used by the P2P Group Owner for its P2P Group.

### `bUseGroupBSSID`

If TRUE, the BSSID in **GroupBSSID** is included in the invitation response. Otherwise, **GroupBSSID** is not valid.

### `OperatingChannel`

The channel information to include in the Operating Channel attribute of the invitation response.

### `bUseSpecifiedOperatingChannel`

If TRUE, the operation channel specified in **OperatingChannel** is included in the invitation response. Otherwise, the miniport driver may choose its own operating channel if **Status** == **DOT11_WFD_STATUS_SUCCESS**. If **Status** != **DOT11_WFD_STATUS_SUCCESS**, the miniport must not include the operating channel attribute in the invitation response.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) the Wi-Fi Direct (WFD) port must add to the invitation response packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_SEND_INVITATION_RESPONSE_PARAMETERS {
  NDIS_OBJECT_HEADER              Header;
  DOT11_MAC_ADDRESS               ReceiverDeviceAddress;
  DOT11_DIALOG_TOKEN              DialogToken;
  PVOID                           RequestContext;
  ULONG                           uSendTimeout;
  DOT11_WFD_STATUS_CODE           Status;
  DOT11_WFD_CONFIGURATION_TIMEOUT MinimumConfigTimeout;
  DOT11_MAC_ADDRESS               GroupBSSID;
  BOOLEAN                         bUseGroupBSSID;
  DOT11_WFD_CHANNEL               OperatingChannel;
  BOOLEAN                         bUseSpecifiedOperatingChannel;
  ULONG                           uIEsOffset;
  ULONG                           uIEsLength;
} DOT11_SEND_INVITATION_RESPONSE_PARAMETERS, *PDOT11_SEND_INVITATION_RESPONSE_PARAMETERS;
```

## See also

[OID_DOT11_WFD_SEND_INVITATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-invitation-response)

[NDIS_STATUS_DOT11_WFD_RECEIVED_INVITATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-invitation-request)

[NDIS_STATUS_DOT11_WFD_INVITATION_RESPONSE_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-invitation-response-send-complete)