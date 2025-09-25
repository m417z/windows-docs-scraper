## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_CHANNEL_MAPPING_ENTRY** structure defines a channel mapping entry.

## Members

### `ChannelNumber`

Specifies the logical channel number.

### `ChannelCenterFrequency`

Specifies the center frequency for the channel in MHz.

## Remarks

The **WDI_CHANNEL_MAPPING_ENTRY** struct is a value in the [**WDI_TLV_CHANNEL_LIST**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-channel-list) TLV.

## See also

[**WDI_TLV_CHANNEL_LIST**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-channel-list)