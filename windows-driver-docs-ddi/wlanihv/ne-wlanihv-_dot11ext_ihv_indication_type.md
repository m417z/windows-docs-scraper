# _DOT11EXT_IHV_INDICATION_TYPE enumeration

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_IHV_INDICATION_TYPE enumeration specifies the indication types that can be sent by an
IHV framework to an IHV module.

## Constants

### `IndicationTypeNicSpecificNotification`

Indicates a NIC-specific notification.

### `IndicationTypePmkidCandidateList`

Indicates a PMKID candidate list.

### `IndicationTypeTkipMicFailure`

Indicates a TKIP MIC failure.

### `IndicationTypePhyStateChange`

Indicates a PHY state change.

### `IndicationTypeLinkQuality`

Indicates link quality.

## Syntax

```cpp
typedef enum _DOT11EXT_IHV_INDICATION_TYPE {
  IndicationTypeNicSpecificNotification  = 0,
  IndicationTypePmkidCandidateList       = 1,
  IndicationTypeTkipMicFailure           = 2,
  IndicationTypePhyStateChange           = 3,
  IndicationTypeLinkQuality              = 4
} DOT11EXT_IHV_INDICATION_TYPE, *PDOT11EXT_IHV_INDICATION_TYPE;
```