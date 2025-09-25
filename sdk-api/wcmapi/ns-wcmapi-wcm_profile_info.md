# WCM_PROFILE_INFO structure

## Description

The **WCM_PROFILE_INFO** structure contains information about a specific profile.

## Members

### `strProfileName`

Type: **WCHAR[WCM_MAX_PROFILE_NAME]**

The profile name.

### `AdapterGUID`

Type: **GUID**

The GUID of the adapter.

### `Media`

Type: **[WCM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ne-wcmapi-wcm_media_type)**

The media type for the profile.

## See also

[WCM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ne-wcmapi-wcm_media_type)