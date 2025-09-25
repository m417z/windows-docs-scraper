# _WDI_ROAM_TRIGGER enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_ROAM_TRIGGER enumeration defines roam triggers.

## Constants

### `WDI_ROAM_TRIGGER_OTHER`

None.

### `WDI_ROAM_TRIGGER_CRITICAL_BSS_TRANSITION_REQUEST`

This value is for roams due to a BSS Transition Request by the AP with the Disassociation Imminent bit set.