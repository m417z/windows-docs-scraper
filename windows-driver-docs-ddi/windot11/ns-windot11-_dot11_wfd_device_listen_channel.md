# _DOT11_WFD_DEVICE_LISTEN_CHANNEL structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_DEVICE_LISTEN_CHANNEL** structure describes the Wi-Fi Direct device's listen channel when responding to a [OID_DOT11_WFD_DEVICE_LISTEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-device-listen-channel) set or query request.

## Members

### `Header`

Specifies the type, revision and size of the **DOT11_WFD_DEVICE_LISTEN_CHANNEL** structure. The required settings for the members of **Header** are the following:

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | DOT11_WFD_DEVICE_LISTEN_CHANNEL_REVISION_1 |
| **Size** | DOT11_SIZEOF_WFD_DEVICE_LISTEN_CHANNEL_REVISION_1 |

### `ChannelNumber`

The device listen channel. Windows may use [OID_DOT11_WFD_DEVICE_LISTEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-device-listen-channel) to specify a listen channel (for example 1, 6, or 11). Wi-Fi Direct devices may treat this value as a hint to the device, which may adopt the specified channel, or continue to use the default listen channel. The Wi-Fi Direct device may also change the listen channel at any time.

## Syntax

```cpp
typedef struct _DOT11_WFD_DEVICE_LISTEN_CHANNEL {
  NDIS_OBJECT_HEADER Header;
  UCHAR              ChannelNumber;
} DOT11_WFD_DEVICE_LISTEN_CHANNEL, *PDOT11_WFD_DEVICE_LISTEN_CHANNEL;
```

## See also

[OID_DOT11_WFD_DEVICE_LISTEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-wfd-device-listen-channel)