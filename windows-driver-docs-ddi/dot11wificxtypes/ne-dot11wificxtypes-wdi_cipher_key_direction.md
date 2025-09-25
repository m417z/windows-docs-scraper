## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_CIPHER_KEY_DIRECTION** enumeration defines the traffic directions decrypted by a cipher key.

## Constants

### `WDI_CIPHER_KEY_DIRECTION_INBOUND:1`

The cipher key decrypts packets received from a peer.

### `WDI_CIPHER_KEY_DIRECTION_OUTBOUND:2`

The cipher key decrypts packets transmitted to a peer.

### `WDI_CIPHER_KEY_DIRECTION_BOTH:3`

The cipher key decrypts packets received from or transmitted to a peer.

## Remarks

The **WDI_CIPHER_KEY_DIRECTION** enumeration is a value in the [WDI_TLV_CIPHER_KEY_TYPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-cipher-key-type-info) TLV.

## See also

[WDI_TLV_CIPHER_KEY_TYPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-cipher-key-type-info)