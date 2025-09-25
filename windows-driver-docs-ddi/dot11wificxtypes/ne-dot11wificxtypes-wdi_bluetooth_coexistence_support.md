## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The WDI_BLUETOOTH_COEXISTENCE_SUPPORT enumeration defines Bluetooth coexistence support values.

## Constants

### `WDI_BLUETOOTH_COEXISTENCE_UNKNOWN:0`

Unknown.

### `WDI_BLUETOOTH_COEXISTENCE_PERFORMANCE_MAINTAINED:1`

Wi-Fi and Bluetooth work at the same performance level during coexistence.

### `WDI_BLUETOOTH_COEXISTENCE_WIFI_DEGRADED_TO_1x1:2`

Wi-Fi centered. On a 2X2 device, Wi-Fi and Bluetooth coexists. Wi-Fi performance is reduced to 1X1 level.

### `WDI_BLUETOOTH_COEXISTENCE_WIFI_THROUGHPUT_DEGRADED:3`

Bluetooth centered. When coexisting, Bluetooth has priority and restricts Wi-Fi performance.

### `WDI_BLUETOOTH_COEXISTENCE_MUTUALLY_EXCLUSIVE:4`

Wi-Fi and Bluetooth are mutually exclusive. One of the two stops working.

### `WDI_BLUETOOTH_COEXISTENCE_MAX:5`

## Remarks

## See also