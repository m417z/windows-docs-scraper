## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_STOP_AP_REASON** enumeration defines the reasons an adapter cannot sustain 802.11 Access Point (AP) functionality on any of the PHYs.

## Constants

### `WDI_STOP_AP_REASON_FREQUENCY_NOT_AVAILABLE:0x0001`

The adapter determined that no valid operating frequency is available.

### `WDI_STOP_AP_REASON_CHANNEL_NOT_AVAILABLE:0x0002`

The adapter determined that no operating channel is available.

### `WDI_STOP_AP_REASON_AP_ACTIVE:0x0003`

The adapter determined that an AP is already active on another 802.11 MAC entity for this physical wireless LAN adapter.

### `WDI_STOP_AP_REASON_IHV_START:0xFF000000`

The start value of possible IHV-specified reasons.

### `WDI_STOP_AP_REASON_IHV_END:0xFFFFFFFF`

The end value of possible IHV-specified reasons.

## Remarks

The **WDI_STOP_AP_REASON** enumeration is a value in the [**WDI_TLV_INDICATION_STOP_AP**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-indication-stop-ap) TLV.

## See also

[**WDI_TLV_INDICATION_STOP_AP**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-indication-stop-ap)