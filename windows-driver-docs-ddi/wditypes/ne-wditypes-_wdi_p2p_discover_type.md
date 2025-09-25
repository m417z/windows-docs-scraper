# _WDI_P2P_DISCOVER_TYPE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_P2P_DISCOVER_TYPE enumeration defines the Wi-Fi Direct discovery types.

## Constants

### `WDI_P2P_DISCOVER_TYPE_SCAN_ONLY`

Device discovery occurs only during the scan phase. Adapter should scan each channel at least once every 250 milliseconds.

### `WDI_P2P_DISCOVER_TYPE_FIND_ONLY`

Device discovery occurs only during the find phase.

### `WDI_P2P_DISCOVER_TYPE_AUTO`

Device discovery is determined by the port.

### `WDI_P2P_DISCOVER_TYPE_SCAN_SOCIAL_CHANNELS`

Port must perform device discovery by scanning only Wi-Fi Direct social channels. In this setting, the adapter should scan each social channel at least once every 250 milliseconds.

### `WDI_P2P_DISCOVER_TYPE_MAX_VALUE`

The maximum value for this type.