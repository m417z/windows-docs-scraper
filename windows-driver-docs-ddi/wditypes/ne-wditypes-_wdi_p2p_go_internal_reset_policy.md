# _WDI_P2P_GO_INTERNAL_RESET_POLICY enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_P2P_GO_INTERNAL_RESET_POLICY enumeration defines the Wi-Fi Direct Group Owner internal reset policies.

## Constants

### `WDI_P2P_GO_INTERNAL_RESET_POLICY_USE_LAST_CHANNEL`

If an internal-to-firmware Group Owner reset is performed, post-reset Group Owner must operate on the same operating channel as before the internal reset operation.

### `WDI_P2P_GO_INTERNAL_RESET_POLICY_ALLOW_CHANNEL_OPTIMIZATION`

If an internal-to-firmware Group Owner reset is performed, firmware may freely decide its new operating channel. For example, firmware may choose to minimize channel switching by adopting station port channel. If there is no optimization to be done, fall back to selecting previous operating channel.

### `WDI_P2P_GO_INTERNAL_RESET_POLICY_MAX`