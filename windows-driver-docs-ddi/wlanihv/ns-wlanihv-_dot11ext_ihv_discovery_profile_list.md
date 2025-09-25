# _DOT11EXT_IHV_DISCOVERY_PROFILE_LIST structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_IHV_DISCOVERY_PROFILE_LIST structure specifies a list of IHV discovery profiles.

## Members

### `dwCount`

The number of
[DOT11EXT_IHV_DISCOVERY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_discovery_profile) IHV discovery profiles.

### `pIhvDiscoveryProfiles`

A pointer to an array of
[DOT11EXT_IHV_DISCOVERY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_discovery_profile) IHV discovery profiles.

## Syntax

```cpp
typedef struct _DOT11EXT_IHV_DISCOVERY_PROFILE_LIST {
  DWORD                           dwCount;
  PDOT11EXT_IHV_DISCOVERY_PROFILE pIhvDiscoveryProfiles;
} DOT11EXT_IHV_DISCOVERY_PROFILE_LIST, *PDOT11EXT_IHV_DISCOVERY_PROFILE_LIST;
```

## See also

[DOT11EXT_IHV_DISCOVERY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_discovery_profile)