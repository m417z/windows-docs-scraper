# _WDI_RADIO_MEASUREMENT_ACTION enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_RADIO_MEASUREMENT_ACTION enumeration defines the radio measurement actions.

## Constants

### `WDI_RADIO_MEASUREMENT_ACTION_RADIO_MEASUREMENT_REQUEST:0`

### `WDI_RADIO_MEASUREMENT_ACTION_RADIO_MEASUREMENT_REPORT:1`

### `WDI_RADIO_MEASUREMENT_ACTION_NEIGHBOR_REPORT_REQUEST:4`

This refers to the neighbor report request action frame sent by the client to the AP.

### `WDI_RADIO_MEASUREMENT_ACTION_NEIGHBOR_REPORT_RESPONSE:5`

This refers to the neighbor report response action frame from the AP.