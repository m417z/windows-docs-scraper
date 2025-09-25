## Description

Returns the size, in bytes, of the buffer that is required by the [**WcsEnumColorProfiles**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsenumcolorprofiles) function to enumerate color profiles.

> [!NOTE]
> This API does not support "advanced color" profiles for HDR monitors. Use [**ColorProfileGetDisplayList**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofilegetdisplaylist) for managing advanced color profiles.

## Parameters

### `scope`

A [**WCS\_PROFILE\_MANAGEMENT\_SCOPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope) value that specifies the scope of the profile management operation that is performed by this function.

### `pEnumRecord`

A pointer to a structure that specifies the enumeration criteria.

### `pdwSize`

A pointer to a variable that receives the size of the buffer that is required to receive all enumerated profile names. This value is used by the *dwSize* parameter of the [**WcsEnumColorProfiles**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsenumcolorprofiles) function.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

This function is executable in Least-Privileged User Account (LUA) context.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [WcsEnumColorProfiles](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsenumcolorprofiles)
* [WCS_PROFILE_MANAGEMENT_SCOPE](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope)