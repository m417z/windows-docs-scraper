# _WDI_TX_COMPLETE_DATA structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_TX_COMPLETE_DATA structure defines TX completion data.

## Members

### `SeqCtl`

The value of the sequence control field from the frame transmission.

### `PnLength`

The MPDU PN length for the transmitted frame.

### `RetryCount`

The number of attempts to transmit the frame.

### `wPad`

This member is reserved.

### `MpduPN`

The MPDU PN.

### `ReplayIHVReserved0`

Reserved for IHV use.

### `ReplayIHVReserved1`

Reserved for IHV use.