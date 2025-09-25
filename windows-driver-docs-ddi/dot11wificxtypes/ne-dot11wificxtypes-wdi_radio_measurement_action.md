## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_RADIO_MEASUREMENT_ACTION** enumeration defines the radio measurement action frames.

## Constants

### `WDI_RADIO_MEASUREMENT_ACTION_RADIO_MEASUREMENT_REQUEST:0`

The message is a radio measurement request action frame sent by the client to the AP.

### `WDI_RADIO_MEASUREMENT_ACTION_RADIO_MEASUREMENT_REPORT:1`

The message is a radio measurement report action frame from the AP.

### `WDI_RADIO_MEASUREMENT_ACTION_LINK_MEASUREMENT_REQUEST:2`

The message is a link measurement request action frame sent by the client to the AP.

### `WDI_RADIO_MEASUREMENT_ACTION_LINK_MEASUREMENT_RESPONSE:3`

The message is a link measurement response action frame from the AP.

### `WDI_RADIO_MEASUREMENT_ACTION_NEIGHBOR_REPORT_REQUEST:4`

The message is a neighbor report request action frame sent by the client to the AP.

### `WDI_RADIO_MEASUREMENT_ACTION_NEIGHBOR_REPORT_RESPONSE:5`

The message is a neighbor report response action frame from the AP.

## Remarks

## See also

[**WDI_ACTION_FRAME_CATEGORY_RADIO_MEASUREMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ne-dot11wificxtypes-wdi_action_frame_category)