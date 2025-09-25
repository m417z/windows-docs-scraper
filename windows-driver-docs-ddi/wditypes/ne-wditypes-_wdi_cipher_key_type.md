# _WDI_CIPHER_KEY_TYPE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_CIPHER_KEY_TYPE enumeration defines the cipher key types.

## Constants

### `WDI_CIPHER_KEY_TYPE_PAIRWISE_KEY:1`

The key is a pairwise key to another station.

### `WDI_CIPHER_KEY_TYPE_GROUP_KEY:2`

The key is a group key.

### `WDI_CIPHER_KEY_TYPE_IGTK:3`

The key is an IGTK.

### `WDI_CIPHER_KEY_TYPE_BIGTK:4`

The key is a Beacon Protection Frame Group key.