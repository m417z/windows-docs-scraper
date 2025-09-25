# _DOT11_RECEIVED_INVITATION_RESPONSE_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The parameters for a received invitation response are specified in a **DOT11_RECEIVED_INVITATION_RESPONSE_PARAMETERS** structure. This structure is sent with an [NDIS_STATUS_DOT11_WFD_RECEIVED_INVITATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-invitation-response) indication.

## Members

### `Header`

Specifies the type, revision and size of the **DOT11_RECEIVED_INVITATION_RESPONSE_PARAMETERS** structure. The required settings for the members of **Header** are the following:

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_RECEIVED_INVITATION_RESPONSE_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_RECEIVED_INVITATION_RESPONSE_PARAMETERS_REVISION_1 |

### `TransmitterDeviceAddress`

The address of the device that transmitted the invitation response packet.

### `BSSID`

The BSSID in the received invitation response packet.

### `DialogToken`

The dialog token received in invitation response packet.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) received in the invitation response packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_RECEIVED_INVITATION_RESPONSE_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  TransmitterDeviceAddress;
  DOT11_MAC_ADDRESS  BSSID;
  DOT11_DIALOG_TOKEN DialogToken;
  ULONG              uIEsOffset;
  ULONG              uIEsLength;
} DOT11_RECEIVED_INVITATION_RESPONSE_PARAMETERS, *PDOT11_RECEIVED_INVITATION_RESPONSE_PARAMETERS;
```

## See also

[NDIS_STATUS_DOT11_WFD_RECEIVED_INVITATION_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-wfd-received-invitation-response)