# _DOT11_RECEIVED_PROVISION_DISCOVERY_RESPONSE_PARAMETERS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The response parameters for a provision discovery response are specified in a **DOT11_RECEIVED_PROVISION_DISCOVERY_RESPONSE_PARAMETERS** structure. This structure is sent with an [OID_DOT11_WFD_SEND_PROVISION_DISCOVERY_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-provision-discovery-response) request to the miniport.

## Members

### `Header`

The type, revision, and size of the **DOT11_RECEIVED_PROVISION_DISCOVERY_RESPONSE_PARAMETERS** structure. The required settings for the members of **Header** are the following.

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_RECEIVED_PROVISION_DISCOVERY_RESPONSE_PARAMETERS_REVISION_1 |
| **Size** | DOT11_SIZEOF_RECEIVED_PROVISION_DISCOVERY_RESPONSE_PARAMETERS_REVISION_1 |

### `TransmitterDeviceAddress`

The address of the device that transmitted the provision discovery response packet.

### `BSSID`

The BSSID from the received provision discovery response packet.

### `DialogToken`

The dialog token from the received provision discovery response packet.

### `uIEsOffset`

The offset, in bytes, of the array of additional information elements (IEs) received in the provision discovery response packet. This offset is from the start of the buffer that contains this structure.

### `uIEsLength`

The length, in bytes, of the array of IEs provided at **uIEsOffset**.

## Syntax

```cpp
typedef struct _DOT11_RECEIVED_PROVISION_DISCOVERY_RESPONSE_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  TransmitterDeviceAddress;
  DOT11_MAC_ADDRESS  BSSID;
  DOT11_DIALOG_TOKEN DialogToken;
  ULONG              uIEsOffset;
  ULONG              uIEsLength;
} DOT11_RECEIVED_PROVISION_DISCOVERY_RESPONSE_PARAMETERS, *PDOT11_RECEIVED_PROVISION_DISCOVERY_RESPONSE_PARAMETERS;
```

## See also

[OID_DOT11_WFD_SEND_PROVISION_DISCOVERY_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-send-provision-discovery-response)