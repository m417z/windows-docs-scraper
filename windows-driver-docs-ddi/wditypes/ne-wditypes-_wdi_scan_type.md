# _WDI_SCAN_TYPE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_SCAN_TYPE enumeration defines the scan types.

## Constants

### `WDI_SCAN_TYPE_ACTIVE_ONLY`

The port should transmit a probe request on the channels that it scans. Even for active scans, the port must follow regulatory restrictions on the channel and must not scan on channels that would need a passive scan.

### `WDI_SCAN_TYPE_PASSIVE_ONLY`

The port should not transmit a probe request on the channels that it scans.

### `WDI_SCAN_TYPE_AUTO`

The port can perform an active or passive can or can use a combination of both scan types. It should prefer using Active scans when possible. This is the default scan type setting.

### `WDI_SCAN_TYPE_MAX_VALUE`

The maximum value for this type.