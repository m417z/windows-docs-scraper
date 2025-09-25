# _DOT11_INVITATION_RESPONSE_SEND_COMPLETE_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The parameters for an invitation response send completion are specified in a **DOT11_INVITATION_RESPONSE_SEND_COMPLETE_PARAMETERS** structure. This structure is sent with an [NDIS_STATUS_DOT11_WFD_INVITATION_RESPONSE_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-invitation-response-send-complete) indication.

## Members

### `Header`

The type, revision, and size of the **DOT11_INVITATION_RESPONSE_SEND_COMPLETE_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_INVITATION_RESPONSE_SEND_COMPLETE_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_INVITATION_RESPONSE_SEND_COMPLETE_PARAMETERS_REVISION_1 |

### `ReceiverDeviceAddress`

The address of the device that the invitation response was sent to. This must match the **ReceiverDeviceAddress** member of [DOT11_SEND_INVITATION_RESPONSE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_send_invitation_response_parameters) sent with the [OID_DOT11_WFD_SEND_INVITATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-invitation-response) request.

### `DialogToken`

The dialog token from the invitation response packet. This must match the dialog token sent with the [OID_DOT11_WFD_SEND_INVITATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-invitation-response) request.

### `Status`

The status of the response send attempt. Set to **NDIS_STATUS_SUCCESS** if the packet was successfully transmitted.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) that were included in the invitation response packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_INVITATION_RESPONSE_SEND_COMPLETE_PARAMETERS {
  NDIS_OBJECT_HEADER  Header;
  DOT11_MAC_ADDRESS   ReceiverDeviceAddress;
  DOT11_DIALOG_TOKEN  DialogToken;
  NDIS_STATUS         Status;
  ULONG               uIEsOffset;
  ULONG               uIEsLength;
} DOT11_INVITATION_RESPONSE_SEND_COMPLETE_PARAMETERS, *PDOT11_INVITATION_RESPONSE_SEND_COMPLETE_PARAMETERS;
```

## See also

[OID_DOT11_WFD_SEND_INVITATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-invitation-response)

[NDIS_STATUS_DOT11_WFD_INVITATION_RESPONSE_SEND_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-invitation-response-send-complete)