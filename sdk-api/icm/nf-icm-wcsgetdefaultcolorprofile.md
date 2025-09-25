## Description

Retrieves the default color profile for a device, or for a device-independent default if the device is not specified.

> [!NOTE]
> This API does not support "advanced color" profiles for HDR monitors. Use [**ColorProfileGetDisplayDefault**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofilegetdisplaydefault) for managing advanced color profiles.

## Parameters

### `scope`

A [**WCS_PROFILE_MANAGEMENT_SCOPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope) value specifying the scope of this profile management operation.

### `pDeviceName`

A pointer to the name of the device for which the default color profile is obtained. If **NULL**, a device-independent default profile is obtained.

### `cptColorProfileType`

A [**COLORPROFILETYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofiletype) value specifying the color profile type.

### `cpstColorProfileSubType`

A [**COLORPROFILESUBTYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofilesubtype) value specifying the color profile subtype.

### `dwProfileID`

The ID of the color space that the color profile represents.

### `cbProfileName`

The buffer size, in bytes, of the buffer that is pointed to by *pProfileName*.

### `pProfileName`

A pointer to a buffer to receive the name of the color profile. The size of the buffer, in bytes, will be the indicated by *cbProfileName*.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

Use the [**WcsGetDefaultColorProfileSize**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsgetdefaultcolorprofilesize) function to obtain the required size of the buffer that is pointed to by the *pProfileName* parameter.

If WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER is present, it overrides the system-wide default for *profileManagementScope*.

This function is executable in Least-Privileged User Account (LUA) context.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [COLORPROFILESUBTYPE](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofilesubtype)
* [COLORPROFILETYPE](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofiletype)
* [WCS_PROFILE_MANAGEMENT_SCOPE](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope)
* [WcsGetDefaultColorProfileSize](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsgetdefaultcolorprofilesize)