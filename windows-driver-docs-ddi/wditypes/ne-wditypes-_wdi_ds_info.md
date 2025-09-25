# _WDI_DS_INFO enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_DS_INFO enumeration defines values that specify whether the port is connected to the same DS that it was previously associated to.

## Constants

### `WDI_DS_CHANGED`

New DS.

### `WDI_DS_UNCHANGED`

Same DS as previously associated.

### `WDI_DS_UNKNOWN`

Unable to determine if the DS has changed.

### `WDI_DS_MAX`