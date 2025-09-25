# DOT11EXTIHV_PERFORM_CAPABILITY_MATCH callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvPerformCapabilityMatch* function to request that the IHV Extensions DLL determine whether a
detected basic service set (BSS) network matches the connectivity and security profile extensions defined
by the IHV.

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

### `pConnectableBssid` [in, optional]

A pointer to a
[DOT11_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_bss_list) structure, which contains one
or more 802.11 Beacon or Probe Response frames received from a BSS network. This list is derived from
the results of the last scan operation performed by the WLAN adapter. For more information about the
scan operation, see
[Native 802.11 Scan Operations](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-scan-operations).

**Note** For Windows Vista, the IHV Extensions DLL supports only infrastructure basic
service set (BSS) networks.

### `pdwReasonCode` [out]

A pointer to a DWORD value, which provides additional information for the return value of the
*Dot11ExtIhvPerformCapabilityMatch* function. The IHV Extensions DLL must set *
*pdwReasonCode* to an L2_REASON_CODE_xxxx value, which are defined in
L2cmn.h.

## Return value

If all of the entries in the list of 802.11 Beacon and Probe Response frames support the
connectivity and security attributes defined in the profile fragments, the function returns
ERROR_SUCCESS. Otherwise, it returns an error code defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_PERFORM_CAPABILITY_MATCH Dot11ExtIhvPerformCapabilityMatch;

DWORD APIENTRY Dot11ExtIhvPerformCapabilityMatch(
  _In_opt_ HANDLE                             hIhvExtAdapter,
  _In_opt_ PDOT11EXT_IHV_PROFILE_PARAMS       pIhvProfileParams,
  _In_     PDOT11EXT_IHV_CONNECTIVITY_PROFILE pIhvConnProfile,
  _In_     PDOT11EXT_IHV_SECURITY_PROFILE     pIhvSecProfile,
  _In_opt_ PDOT11_BSS_LIST                    pConnectableBssid,
  _Out_    PDWORD                             pdwReasonCode
)
{ ... }
```

## Remarks

After the WLAN adapter has completed a scan operation to detect the BSS networks within range, the
operating system might call the
*Dot11ExtIhvPerformCapabilityMatch* function to determine whether any of the detected BSS networks
matches the connectivity or security profile extensions defined by the IHV.

When the
*Dot11ExtIhvPerformCapabilityMatch* function is called, the IHV Extensions DLL must follow these
guidelines.

* If the IHV Extensions DLL finds at least one IEEE 802.11 Beacon or Probe Response frame that matches
  the profile fragments, it must set *
  *pdwReasonCode* to one of the following:

  + L2_REASON_CODE_SUCCESS.
  + An IHV-defined value in the range from L2_REASON_CODE_IHV_BASE to (L2_REASON_CODE_IHV_BASE+
    L2_REASON_CODE_GROUP_SIZE-1).In this situation, the
  *Dot11ExtIhvPerformCapabilityMatch* function must return ERROR_SUCCESS.
* If the IHV Extensions DLL does not find an IEEE 802.11 Beacon or Probe Response frame that matches
  the profile fragments, it must not set
  **pdwReasonCode* to L2_REASON_CODE_SUCCESS. Instead, the DLL must set *
  *pdwReasonCode* to one of the following:

  + An appropriate L2_REASON_CODE_xxxx error value.
  + An IHV-defined value in the range from L2_REASON_CODE_IHV_BASE to (L2_REASON_CODE_IHV_BASE+
    L2_REASON_CODE_GROUP_SIZE-1).In this situation, the
  *Dot11ExtIhvPerformCapabilityMatch* function must not return ERROR_SUCCESS.

For more information about the Native 802.11 XML schema, refer to the Microsoft Windows SDK
documentation.

## See also

[DOT11EXT_IHV_CONNECTIVITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_connectivity_profile)

[DOT11EXT_IHV_SECURITY_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_security_profile)

[DOT11_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_bss_list)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[DOT11EXT_IHV_PROFILE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_profile_params)