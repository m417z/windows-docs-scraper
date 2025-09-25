# _DOT11_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The parameters for a provision discovery response are specified in a **DOT11_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE_PARAMETERS** structure. This structure is sent with an [NDIS_STATUS_DOT11_WFD_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-provision-discovery-response-send-complete) indication.

## Members

### `Header`

The type, revision, and size of the **DOT11_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE_PARAMETERS_REVISION_1 |

### `ReceiverDeviceAddress`

The device address of the Wi-Fi Direct (WFD) device that the provision discovery response was sent to.

### `DialogToken`

The dialog token used for the provision discovery response packet. This token must match the token sent with the [OID_DOT11_WFD_SEND_PROVISION_DISCOVERY_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/-oid-dot11-wfd-send-provision-discovery-request) request.

### `Status`

The status for the provision discovery response that was sent.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) that were included in the provision discovery response packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  ReceiverDeviceAddress;
  DOT11_DIALOG_TOKEN DialogToken;
  NDIS_STATUS        Status;
  ULONG              uIEsOffset;
  ULONG              uIEsLength;
} DOT11_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE_PARAMETERS, *PDOT11_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE_PARAMETERS;
```

## See also

[OID_DOT11_WFD_SEND_PROVISION_DISCOVERY_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/-oid-dot11-wfd-send-provision-discovery-request)

[NDIS_STATUS_DOT11_WFD_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-provision-discovery-response-send-complete)