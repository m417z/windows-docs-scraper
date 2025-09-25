# WLAN_PROFILE_INFO structure

## Description

The **WLAN_PROFILE_INFO** structure contains basic information about a profile.

## Members

### `strProfileName`

The name of the profile. This value may be the name of a domain if the profile is for provisioning. Profile names are case-sensitive. This string must be NULL-terminated.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** The name of the profile is derived automatically from the SSID of the wireless network. For infrastructure network profiles, the name of the profile is the SSID of the network. For ad hoc network profiles, the name of the profile is the SSID of the ad hoc network followed by `-adhoc`.

### `dwFlags`

A set of flags specifying settings for wireless profile. These values are defined in the *Wlanapi.h* header file.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** *dwFlags* must be 0. Per-user profiles are not supported.

Combinations of these flag bits are possible

| Value | Meaning |
| --- | --- |
| **WLAN_PROFILE_GROUP_POLICY** | This flag indicates that this profile was created by group policy. A group policy profile is read-only. Neither the content nor the preference order of the profile can be changed. |
| **WLAN_PROFILE_USER** | This flag indicates that the profile is a per-user profile. If not set, this profile is an all-user profile. |

## See also

[WLAN_PROFILE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_profile_info_list)

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist)