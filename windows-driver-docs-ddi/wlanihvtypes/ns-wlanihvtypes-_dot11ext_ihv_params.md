# _DOT11EXT_IHV_PARAMS structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_IHV_PARAMS structure defines the parameters associated with an IHV profile.

## Members

### `dot11ExtIhvProfileParams`

A
[DOT11EXT_IHV_PROFILE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_profile_params) structure that specifies general parameters of a basic service set
(BSS) network with which a network profile will be applied.

### `wstrProfileName`

A string that defines the IHV profile name.

### `dwProfileTypeFlags`

The flags associated with this IHV profile type.

### `interfaceGuid`

The globally unique identifier (GUID) for the wireless LAN (WLAN) adapter.

The operating system passes the GUID and other data related to the WLAN adapter through the
*pDot11Adapter* parameter of the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) function, which the operating system calls when it detects the arrival of
the WLAN adapter. For more information about this operation, see
[802.11 WLAN Adapter
Arrival](https://learn.microsoft.com/windows/win32/api/l2cmn/ns-l2cmn-l2_notification_data).

## Syntax

```cpp
typedef struct _DOT11EXT_IHV_PARAMS {
  DOT11EXT_IHV_PROFILE_PARAMS dot11ExtIhvProfileParams;
  WCHAR                       wstrProfileName[MS_MAX_PROFILE_NAME_LENGTH];
  DWORD                       dwProfileTypeFlags;
  GUID                        interfaceGuid;
} DOT11EXT_IHV_PARAMS, *PDOT11EXT_IHV_PARAMS;
```

## See also

[DOT11EXT_IHV_PROFILE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_profile_params)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)