## Description

Retrieves information about the specified named color profile.

## Parameters

### `hProfile`

The handle to the profile from which the information will be retrieved.

### `pNamedProfileInfo`

A pointer to a **NAMED_PROFILE_INFO** structure.

## Return value

If this function succeeds, the return value is TRUE.

If this function fails, the return value is FALSE. When this occurs, the CMM should call **SetLastError** to set the last error to a valid error value defined in Winerror.h.

## Remarks

This function is required in the default CMM. It is optional for all other CMMs.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [NAMED_PROFILE_INFO](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-named_profile_info)