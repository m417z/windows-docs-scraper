## Description

Returns the size, in bytes, of the default color profile name (including the **NULL** terminator), for a device.

> [!NOTE]
> This API does not support "advanced color" profiles for HDR monitors. Use [**ColorProfileGetDisplayDefault**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofilegetdisplaydefault) for managing advanced color profiles.

## Parameters

### `scope`

A [**WCS\_PROFILE\_MANAGEMENT\_SCOPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope) value that specifies the scope of this profile management operation.

### `pDeviceName`

A pointer to the name of the device for which the default color profile is to be obtained. If **NULL**, a device-independent default profile will be used.

### `cptColorProfileType`

A [**COLORPROFILETYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofiletype) value specifying the color profile type.

### `cpstColorProfileSubType`

A [**COLORPROFILESUBTYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofilesubtype) value specifying the color profile subtype.

### `dwProfileID`

The ID of the color space that the color profile represents.

### `pcbProfileName`

A pointer to a location that receives the size, in bytes, of the path name of the default color profile, including the **NULL** terminator.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

Use this function to return the required size of the buffer that is pointed to by the *pProfileName* parameter in the [**WcsGetDefaultColorProfile**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsgetdefaultcolorprofile) function.

This function is executable in Least-Privileged User Account (LUA) context.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [COLORPROFILESUBTYPE](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofilesubtype)
* [COLORPROFILETYPE](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofiletype)
* [WCS_PROFILE_MANAGEMENT_SCOPE](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope)
* [WcsGetDefaultColorProfile](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsgetdefaultcolorprofile)