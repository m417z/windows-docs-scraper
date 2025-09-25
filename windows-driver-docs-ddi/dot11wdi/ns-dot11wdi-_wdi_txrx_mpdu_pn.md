# _WDI_TXRX_MPDU_PN structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
WDI_TXRX_MPDU_PN union defines the parameters that are passed down to the TXRX component.

## Members

### `Pn24`

WEP: 24-bit PN

### `Pn48`

TKIP or CCMP: 48-bit PN

### `Pn128`

WAPI: 128-bit PN