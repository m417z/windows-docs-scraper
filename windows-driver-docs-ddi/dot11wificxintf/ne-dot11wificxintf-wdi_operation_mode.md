## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is now in maintenance mode and will only receive high priority fixes.

The **WDI_OPERATION_MODE** enumeration defines operation modes.

## Constants

### `WDI_OPERATION_MODE_STA`

Infrastructure client.

### `WDI_OPERATION_MODE_P2P_DEVICE`

Wi-Fi Direct Device.

### `WDI_OPERATION_MODE_P2P_CLIENT`

Wi-Fi Direct Client.

### `WDI_OPERATION_MODE_P2P_GO`

Wi-Fi Direct Group Owner.

## Remarks

The **WDI_OPERATION_MODE** enum is a value in the [**WDI_TLV_OPERATION_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-operation-mode) TLV.

## See also

[**WDI_TLV_OPERATION_MODE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-operation-mode)