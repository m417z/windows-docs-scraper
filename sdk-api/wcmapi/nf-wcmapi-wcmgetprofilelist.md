# WcmGetProfileList function

## Description

The **WcmGetProfileList** function retrieves a list of profiles in preferred order, descending from the most preferred to the least preferred. The list includes all WCM-managed auto-connect profiles across all WCM-managed media types.

## Parameters

### `pReserved`

Type: **PVOID**

Reserved.

### `ppProfileList` [out]

Type: **[PWCM_PROFILE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_profile_info_list)***

The list of profiles.

## Return value

Type: **DWORD**

Returns ERROR_SUCCESS if successful, or an error value otherwise.

## See also

[PWCM_PROFILE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_profile_info_list)