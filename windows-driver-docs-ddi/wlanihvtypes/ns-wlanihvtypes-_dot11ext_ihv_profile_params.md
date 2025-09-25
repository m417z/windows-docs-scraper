# _DOT11EXT_IHV_PROFILE_PARAMS structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11EXT_IHV_PROFILE_PARAMS structure specifies the general parameters of a basic service set
(BSS) network with which a network profile will be applied.

## Members

### `pSsidList`

A pointer to the list of service set identifiers (SSIDs) of the basic service set (BSS) network.
The
**pSsidList** member is formatted as a pointer to a
[DOT11EXT_IHV_SSID_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_ssid_list) structure.

### `BssType`

The type of the BSS network. The
**BssType** member contains a value defined for the
[DOT11_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_bss_type) enumeration.

### `pMSSecuritySettings`

A pointer to a
[DOT11_MSSECURITY_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11_mssecurity_settings) structure that defines Microsoft security settings in the Microsoft
802.1X implementation.

## Syntax

```cpp
typedef struct _DOT11EXT_IHV_PROFILE_PARAMS {
  PDOT11EXT_IHV_SSID_LIST    pSsidList;
  DOT11_BSS_TYPE             BssType;
  PDOT11_MSSECURITY_SETTINGS pMSSecuritySettings;
} DOT11EXT_IHV_PROFILE_PARAMS, *PDOT11EXT_IHV_PROFILE_PARAMS;
```

## Remarks

The operating system passes a pointer to a DOT11EXT_IHV_PROFILE_PARAMS structure as a parameter to any
IHV handler function that processes the IHV-defined fragments of connectivity and security profiles. For
more information, see
[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions).

Although the IHV handler function cannot access the entire network profile, the function can access
the general attributes of the profile through the DOT11EXT_IHV_PROFILE_PARAMS structure.

## See also

[DOT11_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_bss_type)

[Dot11ExtIhvPerformCapabilityMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_capability_match)

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[IDot11ExtUIProperty::Dot11ExtUIPropertySetDisplayInfo](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff553763(v=vs.85))

[Dot11ExtIhvValidateProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_validate_profile)

[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate)

[DOT11EXT_IHV_SSID_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11ext_ihv_ssid_list)

[DOT11_MSSECURITY_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihvtypes/ns-wlanihvtypes-_dot11_mssecurity_settings)

[Dot11ExtIhvCreateDiscoveryProfiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_create_discovery_profiles)

[IDot11ExtUIProperty::Dot11ExtUIPropertyGetDisplayInfo](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff553752(v=vs.85))