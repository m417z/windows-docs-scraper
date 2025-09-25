# _DOT11EXT_IHV_CONNECTIVITY_PROFILE structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_IHV_CONNECTIVITY_PROFILE structure specifies connectivity settings for the IHV
profile.

## Members

### `pszXmlFragmentIhvConnectivity`

A pointer to the string that defines the IHV connectivity profile.

## Syntax

```cpp
typedef struct _DOT11EXT_IHV_CONNECTIVITY_PROFILE {
  LPWSTR pszXmlFragmentIhvConnectivity;
} DOT11EXT_IHV_CONNECTIVITY_PROFILE, *PDOT11EXT_IHV_CONNECTIVITY_PROFILE;
```