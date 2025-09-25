# _DOT11_POWER_MODE_REASON enumeration

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_POWER_MODE_REASON lists the different reasons for changes to auto power save mode state.

## Constants

### `dot11_power_mode_reason_no_change`

Device is initially in this state and has not changed since.

### `dot11_power_mode_reason_noncompliant_AP`

AP is not compliant. As to be in CAM.

### `dot11_power_mode_reason_legacy_WFD_device`

WFD device is legacy.

### `dot11_power_mode_reason_compliant_AP`

AP is compliant.

### `dot11_power_mode_reason_compliant_WFD_device`

All connected WFD device can do PSM.

### `dot11_power_mode_reason_others`

Other reason.

## Syntax

```cpp
typedef enum _DOT11_POWER_MODE_REASON {
  dot11_power_mode_reason_no_change             = 0,
  dot11_power_mode_reason_noncompliant_AP       = 1,
  dot11_power_mode_reason_legacy_WFD_device     = 2,
  dot11_power_mode_reason_compliant_AP          = 3,
  dot11_power_mode_reason_compliant_WFD_device  = 4,
  dot11_power_mode_reason_others                = 5
} DOT11_POWER_MODE_REASON;
```