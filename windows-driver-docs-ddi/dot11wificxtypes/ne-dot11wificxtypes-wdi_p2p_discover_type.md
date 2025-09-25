## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_P2P_DISCOVER_TYPE** enumeration defines the Wi-Fi Direct discovery types.

## Constants

### `WDI_P2P_DISCOVER_TYPE_SCAN_ONLY:1`

Device discovery occurs only during the scan phase. Adapter should scan each channel at least once every 250 milliseconds.

### `WDI_P2P_DISCOVER_TYPE_FIND_ONLY:2`

Device discovery occurs only during the find phase.

### `WDI_P2P_DISCOVER_TYPE_AUTO:3`

Device discovery is determined by the port.

### `WDI_P2P_DISCOVER_TYPE_SCAN_SOCIAL_CHANNELS:4`

Port must perform device discovery by scanning only Wi-Fi Direct social channels. In this setting, the adapter should scan each social channel at least once every 250 milliseconds.

### `WDI_P2P_DISCOVER_TYPE_MAX_VALUE:0xFFFFFFFF`

The maximum value for this type.

## Remarks

The **WDI_P2P_DISCOVER_TYPE** enum is a value in the [**WDI_TLV_P2P_DISCOVER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-discover-mode) and [**WDI_TLV_P2P_BACKGROUND_DISCOVER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-background-discover-mode) TLVs.

## See also

[**WDI_TLV_P2P_DISCOVER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-discover-mode)

[**WDI_TLV_P2P_BACKGROUND_DISCOVER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-background-discover-mode)