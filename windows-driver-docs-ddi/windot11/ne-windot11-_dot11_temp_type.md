# _DOT11_TEMP_TYPE enumeration

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_TEMP_TYPE enumeration specifies the operating temperature range of a PHY on the 802.11
station.

## Constants

### `dot11_temp_type_unknown`

An uninitialized or unknown temperature type.

### `dot11_temp_type_1`

The commercial temperature range from 0 through 40 degrees Celsius.

### `dot11_temp_type_2`

The industrial temperature range from -30 through 70 degrees Celsius.

## Syntax

```cpp
typedef enum _DOT11_TEMP_TYPE {
  dot11_temp_type_unknown  = 0,
  dot11_temp_type_1        = 1,
  dot11_temp_type_2        = 2
} DOT11_TEMP_TYPE, *PDOT11_TEMP_TYPE;
```

## Remarks

There are different operating temperature requirements dependent on the anticipated environmental
conditions. The DOT11_TEMP_TYPE enumeration describes a PHY's operating temperature range capability.

## See also

[DOT11_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_attributes)

[OID_DOT11_TEMP_TYPE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-temp-type)