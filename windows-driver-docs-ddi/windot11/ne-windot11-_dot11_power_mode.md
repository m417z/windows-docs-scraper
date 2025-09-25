# _DOT11_POWER_MODE enumeration

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_POWER_MODE enumeration defines a power management mode for the PHY on the 802.11
station.

## Constants

### `dot11_power_mode_unknown`

Specifies an undefined or uninitialized power mode.

### `dot11_power_mode_active`

Specifies an active power mode in which the PHY is always turned on.

### `dot11_power_mode_powersave`

Specifies a power-save mode in which the PHY is periodically turned off.

## Syntax

```cpp
typedef enum _DOT11_POWER_MODE {
  dot11_power_mode_unknown    = 0,
  dot11_power_mode_active     = 1,
  dot11_power_mode_powersave  = 2
} DOT11_POWER_MODE, *PDOT11_POWER_MODE;
```

## Remarks

An 802.11 station advertises its power management mode through the Power Management subfield of the
Frame Control field in the 802.11 MAC header of transmitted frames. For more information about the Power
Management subfield, refer to Clause 8.2.4.1.7 of the IEEE 802.11-2012 standard.

## See also

[OID_DOT11_ENUM_ASSOCIATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-enum-association-info)