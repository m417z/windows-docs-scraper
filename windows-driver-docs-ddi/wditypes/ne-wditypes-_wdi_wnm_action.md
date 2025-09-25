# _WDI_WNM_ACTION enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_WNM_ACTION enumeration defines the message type for 802.11v BSS Transition Management action frames.

## Constants

### `WDI_WNM_ACTION_BSS_TRANSITION_MANAGEMENT_QUERY`

The message is a BSS Transition Management query frame.

### `WDI_WNM_ACTION_BSS_TRANSITION_MANAGEMENT_REQUEST`

The message is a BSS Transition Management request frame. This is sent by the AP to the client.

### `WDI_WNM_ACTION_BSS_TRANSITION_MANAGEMENT_RESPONSE`

The message is a BSS Transition Management response frame. This is a response to the above request frame from the AP.