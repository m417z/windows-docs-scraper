# _DOT11EXT_IHV_SECURITY_PROFILE structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_IHV_SECURITY_PROFILE structure specifies security settings for the IHV profile.

## Members

### `pszXmlFragmentIhvSecurity`

A pointer to the string that defines the IHV security profile.

### `bUseMSOnex`

A flag that indicates whether the IHV security profile is using the Microsoft 802.1X
implementation. If **TRUE**, the profile uses the Microsoft 802.1X implementation.

## Syntax

```cpp
typedef struct _DOT11EXT_IHV_SECURITY_PROFILE {
  LPWSTR pszXmlFragmentIhvSecurity;
  BOOL   bUseMSOnex;
} DOT11EXT_IHV_SECURITY_PROFILE, *PDOT11EXT_IHV_SECURITY_PROFILE;
```