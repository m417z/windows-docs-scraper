# WcmSetProfileList function

## Description

The **WcmSetProfileList** function reorders a profile list or a subset of a profile list.

## Parameters

### `pProfileList` [in]

Type: **[WCM_PROFILE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_profile_info_list)***

The list of profiles to be reordered, provided in the preferred order (descending from the most preferred to the least preferred).

### `dwPosition` [in]

Type: **DWORD**

Specifies the position in the list to start the reorder.

### `fIgnoreUnknownProfiles` [in]

Type: **BOOL**

True if any profiles in *pProfileList* which do not exist should be ignored; the call will proceed with the remainder of the list. False if the call should fail without modifying the profile order if any profiles in *pProfileList* do not exist.

### `pReserved`

Type: **PVOID**

Reserved.

## Return value

Type: **DWORD**

Returns ERROR_SUCCESS if successful, or an error value otherwise.

## See also

[WCM_PROFILE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_profile_info_list)