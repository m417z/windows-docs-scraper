## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_WPS_CONFIGURATION_METHOD** enumeration defines WPS configuration methods.

## Constants

### `WDI_WPS_CONFIGURATION_METHOD_NULL:0`

WFDS.

### `WDI_WPS_CONFIGURATION_METHOD_DISPLAY:0x0008`

Pin display.

### `WDI_WPS_CONFIGURATION_METHOD_NFC_TAG:0x0020`

NFC tag.

### `WDI_WPS_CONFIGURATION_METHOD_NFC_INTERFACE:0x0040`

NFC interface.

### `WDI_WPS_CONFIGURATION_METHOD_PUSHBUTTON:0x0080`

Push button.

### `WDI_WPS_CONFIGURATION_METHOD_KEYPAD:0x0100`

Pin keypad.

### `WDI_WPS_CONFIGURATION_METHOD_WFDS_DEFAULT:0x1000`

WFDS.

### `WDI_WPS_CONFIGURATION_METHOD_DUMMY_MAX_VALUE:0xFFFF`

Reserved.

## Remarks

The **WDI_WPS_CONFIGURATION_METHOD** enum is a value in the [WDI_TLV_P2P_CONFIG_METHODS](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-config-methods) TLV.

## See also

[WDI_TLV_P2P_CONFIG_METHODS](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-config-methods)