# _WDI_CIPHER_KEY_DIRECTION enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_CIPHER_KEY_DIRECTION enumeration defines the traffic directions decrypted by a cipher key.

## Constants

### `WDI_CIPHER_KEY_DIRECTION_INBOUND`

The cipher key decrypts packets received from a peer.

### `WDI_CIPHER_KEY_DIRECTION_OUTBOUND`

The cipher key decrypts packets transmitted to a peer.

### `WDI_CIPHER_KEY_DIRECTION_BOTH`

The cipher key decrypts packets received from or transmitted to a peer.