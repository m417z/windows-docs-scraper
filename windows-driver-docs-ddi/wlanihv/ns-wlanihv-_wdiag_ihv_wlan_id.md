# _WDIAG_IHV_WLAN_ID structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The WDIAG_IHV_WLAN_ID structure specifies an identifier used for error diagnostics on an IHV
profile.

## Members

### `strProfileName`

A string that defines the IHV profile name.

### `Ssid`

The service set identifier (SSID) of the basic service set (BSS) network. The
**Ssid** member is of the
[DOT11_SSID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-_dot11_ssid) type.

### `BssType`

The type of the BSS network. The
**BssType** member contains a value defined for the
[DOT11_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_bss_type) enumeration.

### `dwFlags`

A flag which, if set to WDIAG_IHV_WLAN_ID_FLAG_SECURITY_ENABLED, indicates that security is
enabled for this IHV profile. Otherwise, security is not enabled.

### `dwReasonCode`

An error reason code, when available.

## Syntax

```cpp
typedef struct _WDIAG_IHV_WLAN_ID {
  WCHAR          strProfileName[MS_MAX_PROFILE_NAME_LENGTH];
  DOT11_SSID     Ssid;
  DOT11_BSS_TYPE BssType;
  DWORD          dwFlags;
  DWORD          dwReasonCode;
} WDIAG_IHV_WLAN_ID, *PWDIAG_IHV_WLAN_ID;
```

## See also

[DOT11_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_bss_type)

[DOT11_SSID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ns-wlantypes-_dot11_ssid)