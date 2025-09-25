## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_CIPHER_KEY_TYPE** enumeration defines the cipher key types.

## Constants

### `WDI_CIPHER_KEY_TYPE_NONE:0`

The key is not valid.

### `WDI_CIPHER_KEY_TYPE_PAIRWISE_KEY:1`

The key is a pairwise key to another station.

### `WDI_CIPHER_KEY_TYPE_GROUP_KEY:2`

The key is a group key.

### `WDI_CIPHER_KEY_TYPE_IGTK:3`

The key is an IGTK.

### `WDI_CIPHER_KEY_TYPE_BIGTK:3`

The key is a Beacon Protection Frame Group key.

## Remarks

The **WDI_CIPHER_KEY_TYPE** enumeration is a value in the [WDI_TLV_CIPHER_KEY_TYPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-cipher-key-type-info) TLV.

## See also

[WDI_TLV_CIPHER_KEY_TYPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-cipher-key-type-info)