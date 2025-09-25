## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_P2P_GO_INTERNAL_RESET_POLICY** enumeration defines the Wi-Fi Direct Group Owner internal reset policies.

## Constants

### `WDI_P2P_GO_INTERNAL_RESET_POLICY_USE_LAST_CHANNEL:1`

If an internal-to-firmware Group Owner reset is performed, post-reset Group Owner must operate on the same operating channel as before the internal reset operation.

### `WDI_P2P_GO_INTERNAL_RESET_POLICY_ALLOW_CHANNEL_OPTIMIZATION:2`

If an internal-to-firmware Group Owner reset is performed, firmware may freely decide its new operating channel. For example, firmware may choose to minimize channel switching by adopting station port channel. If there is no optimization to be done, fall back to selecting previous operating channel.

### `WDI_P2P_GO_INTERNAL_RESET_POLICY_MAX:0xFFFFFFFF`

## Remarks

The **WDI_P2P_GO_INTERNAL_RESET_POLICY** enum is a value in the [**WDI_TLV_P2P_GO_INTERNAL_RESET_POLICY**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-go-internal-reset-policy) TLV.

## See also

[**WDI_TLV_P2P_GO_INTERNAL_RESET_POLICY**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-go-internal-reset-policy)