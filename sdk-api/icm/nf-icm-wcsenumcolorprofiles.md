## Description

Enumerates color profiles associated with any device, in the specified scope.

> [!NOTE]
> This API does not support "advanced color" profiles for HDR monitors. Use [**ColorProfileGetDisplayList**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofilegetdisplaylist) for managing advanced color profiles.

## Parameters

### `scope`

A [**WCS\_PROFILE\_MANAGEMENT\_SCOPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope) value specifying the scope of this profile management operation.

### `pEnumRecord`

A pointer to a structure specifying the enumeration criteria.

### `pBuffer`

A pointer to a buffer in which the profile names are to be enumerated. The **WcsEnumColorProfiles** function places, in this buffer, a MULTI\_SZ string that consists of profile names that satisfy the criteria specified in *\*pEnumRecord*.

### `dwSize`

A variable that contains the size, in bytes, of the buffer that is pointed to by *pBuffer*. See **Remarks**.

### `pnProfiles`

An optional pointer to a variable that receives the number of profile names that are copied to the buffer to which *pBuffer* points. Can be **NULL** if this information is not needed.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

Use the [**WcsEnumColorProfilesSize**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsenumcolorprofilessize) function to retrieve the value for the *dwSize* parameter, which is the size, in bytes, of the buffer pointed to by the *pBuffer* parameter.

If the *profileManagementScope* parameter is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_SYSTEM\_WIDE, only system-wide associations of profiles to the device are considered. If *profileManagementScope* is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER, only per-user associations for the current user are considered. If [**WcsSetUsePerUserProfiles**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcssetuseperuserprofiles) has never been called for this user, or if **WcsSetUsePerUserProfiles** was most recently called for this user with its *usePerUserProfiles* parameter set to **FALSE**, then **WCSEnumColorProfiles** returns an empty list.

If WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER (the current user setting) is present, it overrides the system-wide default for the *profileManagementScope* parameter.

This function is executable in Least-Privileged User Account (LUA) context.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [WCS_PROFILE_MANAGEMENT_SCOPE](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope)
* [WcsEnumColorProfilesSize](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsenumcolorprofilessize)