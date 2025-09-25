## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_ROAM_TRIGGER** enumeration defines roam triggers.

## Constants

### `WDI_ROAM_TRIGGER_OTHER:0x00000000`

None.

### `WDI_ROAM_TRIGGER_CRITICAL_BSS_TRANSITION_REQUEST:0x00000001`

This value is for roams due to a BSS Transition Request by the AP with the Disassociation Imminent bit set.

## Remarks

## See also