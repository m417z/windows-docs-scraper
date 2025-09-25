# _WDI_INTERCONNECT_TYPE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_INTERCONNECT_TYPE enumeration defines the interconnect types.

## Constants

### `WDI_INTERCONNECT_MEMORY_MAPPED`

Target can access system memory (for example, PCI-based interconnect).

### `WDI_INTERCONNECT_MESSAGE_BASED`

Message based interconnect (for example, USB or SDIO).

### `WDI_INTERCONNECT_UNKNOWN`

Unspecified interconnect type.