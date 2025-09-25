# _DOT11_SEND_PROVISION_DISCOVERY_RESPONSE_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The parameters for a response to a provision discovery request are specified in a **DOT11_SEND_PROVISION_DISCOVERY_RESPONSE_PARAMETERS** structure. This structure is sent with an [OID_DOT11_WFD_SEND_PROVISION_DISCOVERY_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-provision-discovery-response) request to the miniport.

## Members

### `Header`

The type, revision, and size of the **DOT11_SEND_PROVISION_DISCOVERY_RESPONSE_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_SEND_PROVISION_DISCOVERY_RESPONSE_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_SEND_PROVISION_DISCOVERY_RESPONSE_PARAMETERS_REVISION_1 |

### `ReceiverDeviceAddress`

The address of the device that transmitted the provision discovery request packet.

### `DialogToken`

The dialog token received from the provision discovery request packet. This token must be used in the provision discovery response packet.

### `RequestContext`

The context data given initially by the [NDIS_STATUS_DOT11_WFD_RECEIVED_PROVISION_DISCOVERY_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-provision-discovery-request) indication.

### `uSendTimeout`

The maximum time, in milliseconds, allowed to send the provision discovery response. If the time-out expires before the miniport has successfully transmitted the provision discovery response, it should indicate the [NDIS_STATUS_DOT11_WFD_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-provision-discovery-response-send-complete) with a failure status.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) the Wi-Fi Direct (WFD) port must add to the provision discovery response packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_SEND_PROVISION_DISCOVERY_RESPONSE_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  ReceiverDeviceAddress;
  DOT11_DIALOG_TOKEN DialogToken;
  PVOID              RequestContext;
  ULONG              uSendTimeout;
  ULONG              uIEsOffset;
  ULONG              uIEsLength;
} DOT11_SEND_PROVISION_DISCOVERY_RESPONSE_PARAMETERS, *PDOT11_SEND_PROVISION_DISCOVERY_RESPONSE_PARAMETERS;
```

## See also

[OID_DOT11_WFD_SEND_PROVISION_DISCOVERY_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-provision-discovery-response)

[NDIS_STATUS_DOT11_WFD_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-provision-discovery-response-send-complete)

[NDIS_STATUS_DOT11_WFD_RECEIVED_PROVISION_DISCOVERY_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-provision-discovery-request)