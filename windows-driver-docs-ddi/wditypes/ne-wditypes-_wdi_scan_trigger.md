# _WDI_SCAN_TRIGGER enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_SCAN_TRIGGER enumeration defines the scan trigger values.

## Constants

### `WDI_SCAN_TRIGGER_MANUAL`

The scan was initiated due to a user or application trigger. If this is set, the port must perform a complete scan on all supported channels.

### `WDI_SCAN_TRIGGER_BACKGROUND`

The scan was initiated due to some background activity. If this is set, the port can perform a complete scan, a partial scan on a subset of supported channels, or no scan.

### `WDI_SCAN_TRIGGER_ROAM`

The scan was initiated for roaming purposes. If the adapter was doing background scans internally and has recent results, it can perform only a subset or no scan. If it does not have recent results, it should perform an appropriate scan.

### `WDI_SCAN_TRIGGER_CONNECT`

The scan was initiated for connecting. This connect may be a first time connect or a connect after a disconnection. The port must always honor this request to perform a scan.

### `WDI_SCAN_TRIGGER_ANQP_QUERY`

The scan was initiated for performing an ANQP query.

### `WDI_SCAN_TRIGGER_FAST_ROAM`

This scan was initiated for roaming purposes, and the host has additional information (for example, neighbor reports or instant connect last channel) to put in specific values in the scan request (such as SSID, BSSID, or band channel).

### `WDI_SCAN_TRIGGER_FTM`

The scan was initiated to search for FTM enabled STAs and the host has additional information (such as channel, BSSID, etc). The port must always honor this request to perform a scan.