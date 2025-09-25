# _DOT11_WPS_CONFIG_METHOD enumeration

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_WPS_CONFIG_METHOD enumeration specifies the Wi-Fi Protected Setup methods.

## Constants

### `DOT11_WPS_CONFIG_METHOD_NULL`

No setup method is configured.

### `DOT11_WPS_CONFIG_METHOD_DISPLAY`

Setup is configured by a software user interface.

### `DOT11_WPS_CONFIG_METHOD_NFC_TAG`

### `DOT11_WPS_CONFIG_METHOD_NFC_INTERFACE`

### `DOT11_WPS_CONFIG_METHOD_PUSHBUTTON`

Setup is configured by push button enablement.

### `DOT11_WPS_CONFIG_METHOD_KEYPAD`

Setup is configured by a keypad action.

### `DOT11_WPS_CONFIG_METHOD_WFDS_DEFAULT`

## Syntax

```cpp
typedef enum _DOT11_WPS_CONFIG_METHOD {
  DOT11_WPS_CONFIG_METHOD_NULL        = 0,
  DOT11_WPS_CONFIG_METHOD_DISPLAY     = 0x0008,
  DOT11_WPS_CONFIG_METHOD_PUSHBUTTON  = 0x0080,
  DOT11_WPS_CONFIG_METHOD_KEYPAD      = 0x0100
} DOT11_WPS_CONFIG_METHOD;
```