# _WDI_CHANNEL_MAPPING_ENTRY structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
WDI_CHANNEL_MAPPING_ENTRY structure defines a channel mapping entry.

## Members

### `ChannelNumber`

Specifies the logical channel number.

### `ChannelCenterFrequency`

Specifies the center frequency for the channel in MHz.