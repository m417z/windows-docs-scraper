# _DOT11_RECEIVED_INVITATION_REQUEST_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The parameters for a received invitation response are specified in a **DOT11_RECEIVED_INVITATION_REQUEST_PARAMETERS** structure. This structure is sent with an [NDIS_STATUS_DOT11_WFD_RECEIVED_INVITATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-invitation-request) indication.

## Members

### `Header`

The type, revision, and size of the **DOT11_RECEIVED_INVITATION_REQUEST_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_RECEIVED_INVITATION_REQUEST_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_RECEIVED_INVITATION_REQUEST_PARAMETERS_REVISION_1 |

### `TransmitterDeviceAddress`

The address of the device that transmitted the invitation request packet.

### `BSSID`

The BSSID in the received invitation request packet.

### `DialogToken`

The dialog token received in the invitation request packet.

### `RequestContext`

The context data from the miniport driver. The system sends this context with the [OID_DOT11_WFD_SEND_INVITATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-invitation-response) request.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) received in the invitation request packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_RECEIVED_INVITATION_REQUEST_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  TransmitterDeviceAddress;
  DOT11_MAC_ADDRESS  BSSID;
  DOT11_DIALOG_TOKEN DialogToken;
  PVOID              RequestContext;
  ULONG              uIEsOffset;
  ULONG              uIEsLength;
} DOT11_RECEIVED_INVITATION_REQUEST_PARAMETERS, *PDOT11_RECEIVED_INVITATION_REQUEST_PARAMETERS;
```

## See also

[OID_DOT11_WFD_SEND_INVITATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-invitation-response)

[NDIS_STATUS_DOT11_WFD_RECEIVED_INVITATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-invitation-request)