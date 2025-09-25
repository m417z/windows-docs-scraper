## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_P2P_SCAN_TYPE** enumeration defines the Wi-Fi Direct scan types.

## Constants

### `WDI_P2P_SCAN_TYPE_ACTIVE:1`

Use active scanning during device discovery. Even for active scans, the port must follow regulatory restrictions on the channel and must not scan on channels that would need a passive scan.

### `WDI_P2P_SCAN_TYPE_PASSIVE:2`

Use passive scanning during device discovery.

### `WDI_P2P_SCAN_TYPE_AUTO:3`

Adapter determines scan type during device discovery. It should prefer using Active scans when possible. This is the default scan type setting.

### `WDI_P2P_SCAN_TYPE_MAX_VALUE:0xFFFFFFFF`

The maximum value for this type.

## Remarks

The **WDI_P2P_SCAN_TYPE** enumeration is a value in the [**WDI_TLV_P2P_DISCOVER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-discover-mode) TLV.

## See also

[**WDI_TLV_P2P_DISCOVER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-discover-mode)