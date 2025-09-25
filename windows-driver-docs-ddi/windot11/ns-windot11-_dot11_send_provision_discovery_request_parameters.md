# _DOT11_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The request parameters for a provision discovery request are specified in a **DOT11_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS** structure. This structure is sent with an [OID_DOT11_WFD_SEND_PROVISION_DISCOVERY_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/-oid-dot11-wfd-send-provision-discovery-request) request to the miniport.

## Members

### `Header`

The type, revision, and size of the **DOT11_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS_REVISION_1 |

### `DialogToken`

The dialog token to send in the provision discovery request packet.

### `PeerDeviceAddress`

The destination address of the WFD device receiving the provision discovery packet.

### `uSendTimeout`

The maximum time, in milliseconds, allowed to send the provision discovery request. If the time-out expires before the miniport has successfully transmitted the provision discovery response, it should indicate the [NDIS_STATUS_DOT11_WFD_PROVISION_DISCOVERY_REQUEST_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-provision-discovery-request-send-complete) with a failure status.

### `GroupCapability`

The capability values that are included in the Group Capability bitmask of the Peer-to-Peer (P2P) Capability Information Element (IE) in a provision discovery request.

### `GroupID`

The group identifier to include in the provision discovery request.

### `bUseGroupID`

If TRUE, the value in **GroupID** should be included in the provision discovery request.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) the Wi-Fi Direct (WFD) port must add to the provision discovery request packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS {
  NDIS_OBJECT_HEADER         Header;
  DOT11_DIALOG_TOKEN         DialogToken;
  DOT11_MAC_ADDRESS          PeerDeviceAddress;
  ULONG                      uSendTimeout;
  DOT11_WFD_GROUP_CAPABILITY GroupCapability;
  DOT11_WFD_GROUP_ID         GroupID;
  BOOLEAN                    bUseGroupID;
  ULONG                      uIEsOffset;
  ULONG                      uIEsLength;
} DOT11_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS, *PDOT11_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS;
```

## See also

[OID_DOT11_WFD_SEND_PROVISION_DISCOVERY_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/-oid-dot11-wfd-send-provision-discovery-request)

[NDIS_STATUS_DOT11_WFD_PROVISION_DISCOVERY_REQUEST_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-provision-discovery-request-send-complete)