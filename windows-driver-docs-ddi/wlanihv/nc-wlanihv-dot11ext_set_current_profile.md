# DOT11EXT_SET_CURRENT_PROFILE callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtSetCurrentProfile** function to specify the settings for the
IHV-defined connectivity and security profile fragments. These fragments will be applied to the current
network profile.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the wireless LAN (WLAN) adapter. This handle
value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `hConnectSession` [in, optional]

The handle used by the operating system to reference the connection session with the basic service
set (BSS) network. This handle value was specified through a previous call to the
[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate) IHV Handler function.

### `pIhvConnProfile` [in, optional]

A pointer to a
[DOT11EXT_IHV_CONNECTIVITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_connectivity_profile) structure that contains connectivity settings for the IHV
profile.

### `pIhvSecProfile` [in, optional]

A pointer to a
[DOT11EXT_IHV_SECURITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_security_profile) structure that specifies security settings for the IHV
profile.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtSetCurrentProfile(
  _In_opt_ HANDLE                             hDot11SvcHandle,
  _In_opt_ HANDLE                             hConnectSession,
  _In_opt_ PDOT11EXT_IHV_CONNECTIVITY_PROFILE pIhvConnProfile,
  _In_opt_ PDOT11EXT_IHV_SECURITY_PROFILE     pIhvSecProfile
);
```

## Remarks

The
**Dot11ExtSetCurrentProfile** function allows the IHV to add custom
connectivity and security profile fragments to the current network profile used for the basic service set
(BSS) network connection. The profile fragments are IHV-specific and are applicable to connectivity or
security extensions available to the user through the
[Native 802.11 IHV UI Extensions
DLL](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560635(v=vs.85)).

The IHV Extensions DLL must follow these guidelines when calling the
**Dot11ExtSetCurrentProfile** function:

* The IHV Extensions DLL must only call
  **Dot11ExtSetCurrentProfile** when performing a pre-association operation
  initiated through a call to the
  [Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate) IHV Handler function. For more information about the
  pre-association operation, see
  [Pre-Association Operation](https://learn.microsoft.com/windows-hardware/drivers/network/pre-association-operation-overview).
* The IHV Extensions DLL must not call
  **Dot11ExtSetCurrentProfile** from within the call to the
  [Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate) IHV Handler function.
  **Dot11ExtSetCurrentProfile** must be called from a different thread than
  the one which is processing the call to
  *Dot11ExtIhvPerformPreAssociate*.

## See also

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[DOT11EXT_IHV_SECURITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_security_profile)

[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate)

[DOT11EXT_IHV_CONNECTIVITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_connectivity_profile)