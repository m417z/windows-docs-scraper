# _DOT11EXT_IHV_DISCOVERY_PROFILE structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_IHV_DISCOVERY_PROFILE structure specifies a single IHV discovery profile.

## Members

### `IhvConnectivityProfile`

The IHV connectivity profile specified by a
[DOT11EXT_IHV_CONNECTIVITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_connectivity_profile) structure.

### `IhvSecurityProfile`

The IHV security profile specified by a
[DOT11EXT_IHV_SECURITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_security_profile) structure.

## Syntax

```cpp
typedef struct _DOT11EXT_IHV_DISCOVERY_PROFILE {
  DOT11EXT_IHV_CONNECTIVITY_PROFILE IhvConnectivityProfile;
  DOT11EXT_IHV_SECURITY_PROFILE     IhvSecurityProfile;
} DOT11EXT_IHV_DISCOVERY_PROFILE, *PDOT11EXT_IHV_DISCOVERY_PROFILE;
```

## See also

[DOT11EXT_IHV_SECURITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_security_profile)

[DOT11EXT_IHV_CONNECTIVITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_connectivity_profile)