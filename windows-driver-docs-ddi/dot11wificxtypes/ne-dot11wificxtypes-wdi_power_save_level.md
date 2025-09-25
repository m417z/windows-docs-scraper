## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_POWER_SAVE_LEVEL** enumeration defines the power save levels.

## Constants

### `WDI_POWER_SAVE_LEVEL_NO_POWER_SAVE:0`

No power saving.

### `WDI_POWER_SAVE_LEVEL_FAST_PSP:8`

Fast PSP.

### `WDI_POWER_SAVE_LEVEL_MAX_PSP:16`

Maximum PSP.

### `WDI_POWER_SAVE_LEVEL_MAXIMUM_LEVEL:24`

Maximum power saving level.

## Remarks

The **WDI_POWER_SAVE_LEVEL** enumeration is a value in the [**WDI_TLV_GET_AUTO_POWER_SAVE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-get-auto-power-save) TLV.

## See also

[**WDI_TLV_GET_AUTO_POWER_SAVE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-get-auto-power-save)