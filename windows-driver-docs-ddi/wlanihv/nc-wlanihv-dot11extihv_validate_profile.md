# DOT11EXTIHV_VALIDATE_PROFILE callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvValidateProfile* function to validate user data entered for a network profile. The IHV
Extensions DLL is only responsible for verifying the data for the fragments of the connectivity and
security profile defined by the IHV.

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the wireless LAN (WLAN) adapter. This
handle value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `pIhvProfileParams` [in, optional]

A pointer to a
[DOT11EXT_IHV_PROFILE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_profile_params) structure. This structure defines the attributes of the basic service
set (BSS) network to which the profile extensions will be applied.

### `pIhvConnProfile` [in]

A pointer to a
[DOT11EXT_IHV_CONNECTIVITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_connectivity_profile) structure that contains connectivity settings for the IHV
profile.

### `pIhvSecProfile` [in]

A pointer to a
[DOT11EXT_IHV_SECURITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_security_profile) structure that contains security settings for the IHV
profile.

### `pdwReasonCode` [out]

A pointer to a DWORD value, which provides additional information for the return value of the
*Dot11ExtIhvValidateProfile* function. The IHV Extensions DLL must set *
*pdwReasonCode* to an L2_REASON_CODE_xxxx value, which are defined in
L2cmn.h.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_VALIDATE_PROFILE Dot11ExtIhvValidateProfile;

DWORD APIENTRY Dot11ExtIhvValidateProfile(
  _In_opt_ HANDLE                             hIhvExtAdapter,
  _In_opt_ PDOT11EXT_IHV_PROFILE_PARAMS       pIhvProfileParams,
  _In_     PDOT11EXT_IHV_CONNECTIVITY_PROFILE pIhvConnProfile,
  _In_     PDOT11EXT_IHV_SECURITY_PROFILE     pIhvSecProfile,
  _Out_    PDWORD                             pdwReasonCode
)
{ ... }
```

## Remarks

The operating system calls the
*Dot11ExtIhvValidateProfile* function to verify the user-specified settings for a network profile
before the profile is processed or saved.

When the
*Dot11ExtIhvValidateProfile* function is called, the IHV Extensions DLL follows these guidelines:

* The IHV Extensions DLL verifies that the user-specified profile settings are valid for the general
  attributes of the basic service set (BSS) network to which the profile will be applied. The BSS network
  attributes are referenced through the
  *pIhvProfileParams* parameter.
* If the user data is valid for the network profile extensions,
  *Dot11ExtIhvValidateProfile* must return ERROR_SUCCESS. Otherwise, the function must return an
  appropriate error code from the ERROR_xxxx values defined in
  Winerror.h.
* The IHV Extensions DLL provides more information regarding the results of the validation of the user
  data. The DLL must set *
  *pdwReasonCode* to one of the following:

  + L2_REASON_CODE_SUCCESS, if the user data is valid.
  + An appropriate L2_REASON_CODE_xxxx error value, if the user data is not valid.
  + An IHV-defined value in the range from L2_REASON_CODE_IHV_BASE to (L2_REASON_CODE_IHV_BASE+
    L2_REASON_CODE_GROUP_SIZE-1), regardless of the validity of the user data.

For more information about the Native 802.11 XML schema, refer to the Microsoft Windows SDK
documentation.

## See also

[DOT11EXT_IHV_CONNECTIVITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_connectivity_profile)

[DOT11EXT_IHV_PROFILE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_profile_params)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[DOT11EXT_IHV_SECURITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_security_profile)