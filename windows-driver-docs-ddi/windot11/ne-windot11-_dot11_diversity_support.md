# _DOT11_DIVERSITY_SUPPORT enumeration

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_DIVERSITY_SUPPORT enumeration specifies the type of antenna diversity supported by a PHY on
the 802.11 station.

## Constants

### `dot11_diversity_support_unknown`

An uninitialized or unknown diversity support type.

### `dot11_diversity_support_fixedlist`

The PHY supports antenna diversity that is performed over the fixed list of antennas defined in
the
**dot11DiversitySelectionRx** MIB object. For more information about this MIB object, see
[OID_DOT11_DIVERSITY_SELECTION_RX](https://learn.microsoft.com/previous-versions/windows/embedded/ee483634(v=winembedded.80)).

### `dot11_diversity_support_notsupported`

The PHY does not support antenna diversity.

### `dot11_diversity_support_dynamic`

The PHY supports antenna diversity and the dynamic control of diversity. The PHY layer management
entity (LME) can dynamically modify the list of antennas specified by the
**dot11DiversitySelectionRx** MIB object

## Syntax

```cpp
typedef enum _DOT11_DIVERSITY_SUPPORT {
  dot11_diversity_support_unknown       = 0,
  dot11_diversity_support_fixedlist     = 1,
  dot11_diversity_support_notsupported  = 2,
  dot11_diversity_support_dynamic       = 3
} DOT11_DIVERSITY_SUPPORT, *PDOT11_DIVERSITY_SUPPORT;
```

## See also

[OID_DOT11_DIVERSITY_SELECTION_RX](https://learn.microsoft.com/previous-versions/windows/embedded/ee483634(v=winembedded.80))