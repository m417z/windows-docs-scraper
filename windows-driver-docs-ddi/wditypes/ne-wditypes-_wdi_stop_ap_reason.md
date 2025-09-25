# _WDI_STOP_AP_REASON enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_STOP_AP_REASON enumeration defines the reasons an adapter cannot sustain 802.11 Access Point (AP) functionality on any of the PHYs.

## Constants

### `WDI_STOP_AP_REASON_FREQUENCY_NOT_AVAILABLE`

The adapter determined that no valid operating frequency is available.

### `WDI_STOP_AP_REASON_CHANNEL_NOT_AVAILABLE`

The adapter determined that no operating channel is available.

### `WDI_STOP_AP_REASON_AP_ACTIVE`

The adapter determined that an AP is already active on another 802.11 MAC entity for this physical wireless LAN adapter.

### `WDI_STOP_AP_REASON_IHV_START`

The start value of possible IHV-specified reasons.

### `WDI_STOP_AP_REASON_IHV_END`

The end value of possible IHV-specified reasons.