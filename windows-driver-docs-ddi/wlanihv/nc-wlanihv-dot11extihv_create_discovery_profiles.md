# DOT11EXTIHV_CREATE_DISCOVERY_PROFILES callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvCreateDiscoveryProfiles* function to return temporary connectivity and security profile
fragments that could be used to connect to a basic service set (BSS) network for which a network profile
does not exist.

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the wireless LAN (WLAN) adapter. This
handle value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `bInsecure` [in]

A Boolean value that specifies the security status of the discovery profiles. If set to **TRUE**, the
IHV Extensions DLL can only return secure profiles, such as profiles which involve user
authentication.

### `pIhvProfileParams` [in, optional]

A pointer to a
[DOT11EXT_IHV_PROFILE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_profile_params) structure. This structure defines the attributes of the basic service
set (BSS) network to which the profile extensions will be applied.

### `pConnectableBssid` [in, optional]

A pointer to a
[DOT11_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_bss_list) structure, which contains one
or more 802.11 Beacon or Probe Response frames received from a BSS network. This list is derived from
the results of the last scan operation performed by the WLAN adapter. For more information about the
scan operation, see
[Native 802.11 Scan Operations](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-scan-operations).

**Note** For Windows Vista, the IHV Extensions DLL supports only infrastructure basic
service set (BSS) networks.

### `pIhvDiscoveryProfileList` [out]

A pointer to a
[DOT11EXT_IHV_DISCOVERY_PROFILE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_discovery_profile_list) structure that specifies a list of IHV discovery
profiles.

### `pdwReasonCode` [out]

A pointer to a DWORD value, which provides additional information for the return value of the
*Dot11ExtIhvCreateDiscoveryProfiles* function. The IHV Extensions DLL must set *
*pdwReasonCode* to an L2_REASON_CODE_xxxx value, which are defined in
L2cmn.h.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_CREATE_DISCOVERY_PROFILES Dot11ExtIhvCreateDiscoveryProfiles;

DWORD APIENTRY Dot11ExtIhvCreateDiscoveryProfiles(
  _In_opt_ HANDLE                               hIhvExtAdapter,
  _In_     BOOL                                 bInsecure,
  _In_opt_ PDOT11EXT_IHV_PROFILE_PARAMS         pIhvProfileParams,
  _In_opt_ PDOT11_BSS_LIST                      pConnectableBssid,
  _Out_    PDOT11EXT_IHV_DISCOVERY_PROFILE_LIST pIhvDiscoveryProfileList,
  _Out_    PDWORD                               pdwReasonCode
)
{ ... }
```

## Remarks

After the WLAN adapter completes a scan operation, the operating system might call
*Dot11ExtIhvCreateDiscoveryProfiles* to create temporary profile fragments that could be used to
connect to a BSS network for which a network profile has not been created by the user.

When
*Dot11ExtIhvCreateDiscoveryProfiles* is called, the IHV Extensions DLL must follow these
guidelines.

* If the IHV Extensions DLL can return profile fragments that can be used to connect to the BSS
  network, the
  *Dot11ExtIhvCreateDiscoveryProfiles* function must return ERROR_SUCCESS. Otherwise, the function
  must return an appropriate error code from the ERROR_xxxx values defined in
  Winerror.h.
* The IHV Extensions DLL provides more information regarding the return result of the
  *Dot11ExtIhvCreateDiscoveryProfiles* function. The DLL must set *
  *pdwReasonCode* to one of the following:

  + L2_REASON_CODE_SUCCESS, if profile fragments can be returned for the list of BSS networks.
  + An appropriate L2_REASON_CODE_xxxx error value, if the profile fragments cannot be returned for
    the list of BSS networks.
  + An IHV-defined value in the range from L2_REASON_CODE_IHV_BASE to (L2_REASON_CODE_IHV_BASE+
    L2_REASON_CODE_GROUP_SIZE-1), regardless of whether profile fragments are returned.

For more information about creating discovery profiles, see
[Creating Network Profile
Extensions](https://learn.microsoft.com/windows-hardware/drivers/network/creating-network-profile-extensions).

## See also

[DOT11EXT_IHV_DISCOVERY_PROFILE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_discovery_profile_list)

[DOT11_BSS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlclient/ns-wlclient-_dot11_bss_list)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_free_buffer)

[Dot11ExtAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_allocate_buffer)

[DOT11EXT_IHV_PROFILE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_profile_params)