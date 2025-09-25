# DOT11EXT_SET_PROFILE_CUSTOM_USER_DATA callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSetProfileCustomUserData** function to save data within the system
registry that is specific to the current user and network profile used for the basic service set (BSS)
network connection.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the wireless LAN (WLAN) adapter. This handle
value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `hConnectSession` [in, optional]

The handle used by the operating system to reference the connection session with the BSS network.
This handle value was specified through a previous call to the
[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate) IHV Handler function.

### `dwSessionID` [in]

The session identifier (session ID) of the current user.

### `dwDataSize` [in]

The size, in bytes, of the buffer referenced by
*pvData* .

### `pvData` [in]

A pointer to a caller-allocated buffer, which contains the data in a format defined by the
IHV.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSetProfileCustomUserData(
  _In_opt_ HANDLE hDot11SvcHandle,
  _In_opt_ HANDLE hConnectSession,
  _In_     DWORD  dwSessionID,
  _In_     DWORD  dwDataSize,
  _In_     LPVOID pvData
);
```

## Remarks

The operating system will not encrypt the data referenced by the
*pvData* parameter before storing it within the system registry. The IHV Extensions DLL should use
its own encryption algorithm to encrypt the data prior to calling
**Dot11ExtSetProfileCustomUserData**.

For every wireless WLAN profile used by the Native Wifi AutoConfig service, Windows maintains the
concept of custom user data. This custom user data is initially non-existent, but can be set by calling
the
*Dot11ExtSetProfileCustomUserData* function. The custom user data gets reset to empty any time the
profile is modified by calling the
[Dot11ExtSetCurrentProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_current_profile) function.

After custom user data has been set, this data can be accessed using the
[Dot11ExtGetProfileCustomUserData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_get_profile_custom_user_data) function. The operating system stores the data under the system
registry HKEY_CURRENT_USER key for the user that is referenced by the handle passed in the
*dwSessionID* parameter.

## See also

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtSetCurrentProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_set_current_profile)

[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate)

[Dot11ExtGetProfileCustomUserData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_get_profile_custom_user_data)