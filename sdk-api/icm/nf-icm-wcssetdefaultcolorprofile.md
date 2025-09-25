## Description

Sets the default color profile name for the specified profile type in the specified profile management scope.

> [!NOTE]
> This API does not support "advanced color" profiles for HDR monitors. Use [**ColorProfileSetDisplayDefaultAssociation**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofilesetdisplaydefaultassociation) for managing advanced color profiles.

## Parameters

### `scope`

A [**WCS\_PROFILE\_MANAGEMENT\_SCOPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope) value that specifies the scope of this profile management operation.

### `pDeviceName`

A pointer to the name of the device for which the default color profile is to be set. If **NULL**, a device-independent default profile is used.

### `cptColorProfileType`

A [**COLORPROFILETYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofiletype) value that specifies the color profile type.

### `cpstColorProfileSubType`

A [**COLORPROFILESUBTYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofilesubtype) value that specifies the color profile subtype.

### `dwProfileID`

The ID of the color space that the color profile represents. This is a custom ID value used to uniquely identify the color space profile within your application.

### `pProfileName`

A pointer to a buffer that holds the name of the color profile. See Remarks.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the *pProfileName* parameter is **NULL** and the *profileManagementScope* parameter is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER, subsequent calls to **WcsSetDefaultColorProfile** will return the system-wide default profile.

If *profileManagementScope* is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER, this function is executable in Least-Privileged User Account (LUA) context. Otherwise, administrative privileges are required. The specified profile must already be installed, but it may be not yet associated with the specified device in the specified profile management scope.

If *profileManagementScope* is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER, this function will not correctly function if launched from system context and not a User Account.

When WcsSetDefaultColorProfile is called to set a device model profile DMP as the default profile for the RGB or custom working space, only a DMP profile that is of type RGBVirtualDevice, LCD, or CRT is valid; all others are invalid.

When WcsSetDefaultColorProfile is called to set an International Color Consortium (ICC) profile as the default profile for the RGB or custom working space, only an ICC profile with class "spac" or "disp", and "RGB" color space is valid; all others are invalid.

See notes on valid profile type/subtype combinations.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [COLORPROFILESUBTYPE](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofilesubtype)
* [COLORPROFILETYPE](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofiletype)
* [WCS_PROFILE_MANAGEMENT_SCOPE](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope)
* [WcsGetDefaultColorProfileSize](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsgetdefaultcolorprofilesize)