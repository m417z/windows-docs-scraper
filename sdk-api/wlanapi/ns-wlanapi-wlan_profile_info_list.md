# WLAN_PROFILE_INFO_LIST structure

## Description

The **WLAN_PROFILE_INFO_LIST** structure contains a list of wireless profile information.

## Members

### `dwNumberOfItems`

The number of wireless profile entries in the **ProfileInfo** member.

### `dwIndex`

The index of the current item. The index of the first item is 0. The **dwIndex** member must be less than the **dwNumberOfItems** member.

This member is not used by the wireless service. Applications can use this member when processing individual profiles in the **WLAN_PROFILE_INFO_LIST** structure. When an application passes this structure from one function to another, it can set the value of **dwIndex** to the index of the item currently being processed. This can help an application maintain state.

**dwIndex** should always be initialized before use.

### `ProfileInfo.unique`

### `ProfileInfo.size_is`

### `ProfileInfo.size_is.dwNumberOfItems`

### `ProfileInfo`

An array of [WLAN_PROFILE_INFO](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_profile_info) structures containing interface information. The number of items in the array is specified in the **dwNumberOfItems** member.

## See also

[WLAN_PROFILE_INFO](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_profile_info)

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist)