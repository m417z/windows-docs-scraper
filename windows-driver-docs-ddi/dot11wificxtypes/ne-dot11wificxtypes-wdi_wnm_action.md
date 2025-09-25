## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_WNM_ACTION** enumeration defines the message type for 802.11v BSS Transition Management action frames.

## Constants

### `WDI_WNM_ACTION_EVENT_REQUEST:0`

The message is an event request frame. This is sent by the AP to the client.

### `WDI_WNM_ACTION_EVENT_RESPONSE:1`

The message is an event response frame. This is a response to the above request frame from the AP.

### `WDI_WNM_ACTION_DIAGNOSTIC_REQUEST:2`

The message is a diagnostic request frame. This is sent by the AP to the client.

### `WDI_WNM_ACTION_DIAGNOSTIC_RESPONSE:3`

The message is a diagnostic response frame. This is a response to the above request frame from the AP.

### `WDI_WNM_ACTION_LOCATION_CONFIGURATION_REQUEST:4`

The message is a location configuration request frame. This is sent by the AP to the client.

### `WDI_WNM_ACTION_LOCATION_CONFIGURATION_RESPONSE:5`

The message is a location configuration response frame. This is a response to the above request frame from the AP.

### `WDI_WNM_ACTION_BSS_TRANSITION_MANAGEMENT_QUERY:6`

The message is a BSS Transition Management query frame.

### `WDI_WNM_ACTION_BSS_TRANSITION_MANAGEMENT_REQUEST:7`

The message is a BSS Transition Management request frame. This is sent by the AP to the client.

### `WDI_WNM_ACTION_BSS_TRANSITION_MANAGEMENT_RESPONSE:8`

The message is a BSS Transition Management response frame. This is a response to the above request frame from the AP.

## Remarks

## See also