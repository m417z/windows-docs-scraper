# _DOT11_SEND_INVITATION_REQUEST_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The request parameters for an invitation request are specified in a **DOT11_SEND_INVITATION_REQUEST_PARAMETERS** structure. This structure is sent with an [OID_DOT11_WFD_SEND_INVITATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-invitation-request) request to the miniport.

## Members

### `Header`

The type, revision, and size of the **DOT11_SEND_INVITATION_REQUEST_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_SEND_INVITATION_REQUEST_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_SEND_INVITATION_REQUEST_PARAMETERS_REVISION_1 |

### `DialogToken`

The dialog token to send in the invitation request packet.

### `PeerDeviceAddress`

The destination address of the WFD device receiving the invitation request packet.

### `uSendTimeout`

The maximum time, in milliseconds, allowed to send the invitation request. If the time-out expires before the miniport has successfully transmitted the invitation request, it should indicate the [NDIS_STATUS_DOT11_WFD_INVITATION_REQUEST_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-invitation-request-send-complete) with a failure status.

### `MinimumConfigTimeout`

The configuration time-out required by the system to change its mode of operation to a Peer-to-Peer (P2P) Group Owner or a P2P Client. The miniport driver can set this with a larger value if necessary.

### `InvitationFlags`

The operation flags for the P2P invitation procedure.

### `GroupBSSID`

The BSSID used by the P2P Group Owner for its P2P Group.

### `bUseGroupBSSID`

If TRUE, the BSSID in **GroupBSSID** is included in the invitation request. Otherwise, **GroupBSSID** is not valid.

### `OperatingChannel`

The channel information to include in the Operating Channel attribute of the invitation request.

### `bUseSpecifiedOperatingChannel`

If TRUE, the operating channel specified in **OperatingChannel** is included in the invitation request. Otherwise, the miniport driver can choose its own operating channel.

### `GroupID`

The P2P group identifier.

### `bLocalGO`

The device with the source address in the group owner.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) the Wi-Fi Direct (WFD) port must add to the invitation request packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_SEND_INVITATION_REQUEST_PARAMETERS {
  NDIS_OBJECT_HEADER              Header;
  DOT11_DIALOG_TOKEN              DialogToken;
  DOT11_MAC_ADDRESS               PeerDeviceAddress;
  ULONG                           uSendTimeout;
  DOT11_WFD_CONFIGURATION_TIMEOUT MinimumConfigTimeout;
  DOT11_WFD_INVITATION_FLAGS      InvitationFlags;
  DOT11_MAC_ADDRESS               GroupBSSID;
  BOOLEAN                         bUseGroupBSSID;
  DOT11_WFD_CHANNEL               OperatingChannel;
  BOOLEAN                         bUseSpecifiedOperatingChannel;
  DOT11_WFD_GROUP_ID              GroupID;
  BOOLEAN                         bLocalGO;
  ULONG                           uIEsOffset;
  ULONG                           uIEsLength;
} DOT11_SEND_INVITATION_REQUEST_PARAMETERS, *PDOT11_SEND_INVITATION_REQUEST_PARAMETERS;
```

## See also

[OID_DOT11_WFD_SEND_INVITATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-invitation-request)

[NDIS_STATUS_DOT11_WFD_INVITATION_REQUEST_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-invitation-request-send-complete)