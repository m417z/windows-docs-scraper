## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_SCAN_TYPE** enumeration defines scan types.

## Constants

### `WDI_SCAN_TYPE_ACTIVE_ONLY:1`

The port should transmit a probe request on the channels that it scans. Even for active scans, the port must follow regulatory restrictions on the channel and must not scan on channels that would need a passive scan.

### `WDI_SCAN_TYPE_PASSIVE_ONLY:2`

The port should not transmit a probe request on the channels that it scans.

### `WDI_SCAN_TYPE_AUTO:3`

The port can perform an active or passive can or can use a combination of both scan types. It should prefer using Active scans when possible. This is the default scan type setting.

### `WDI_SCAN_TYPE_MAX_VALUE:0xFFFF`

The maximum value for this type.

## Remarks

The **WDI_SCAN_TYPE** enum is a value in the [**WDI_TLV_SCAN_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-scan-mode) and [**WDI_TLV_ADAPTER_NLO_SCAN_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-adapter-nlo-scan-mode) TLVs.

## See also

[**WDI_TLV_SCAN_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-scan-mode)

[**WDI_TLV_ADAPTER_NLO_SCAN_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-adapter-nlo-scan-mode)