## Description

Registers a specified profile for a given standard [color space](https://learn.microsoft.com/windows/win32/wcs/c#color-space). The profile can be queried using [GetStandardColorSpaceProfileW](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-getstandardcolorspaceprofilew).

## Parameters

### `pMachineName`

Reserved. Must be **NULL**. This parameter is intended to point to the name of the machine on which to set a standard color space profile. A **NULL** pointer indicates the local machine.

### `dwProfileID`

Specifies the ID value of the standard color space that the given profile represents. This is a custom ID value used to uniquely identify the color space profile within your application.

### `pProfilename`

Points to a fully qualified path to the profile file.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The profile must already be installed on the system before it can be registered for a standard color space.

This function supports Windows Color System (WCS) device model profiles (DMPs) in addition to International Color Consortium (ICC) profiles. It does not support WCS CAMP or GMMP profiles and will return an error if such profiles are used.

***Per-user/LUA support***

This will register a specified profile for a given standard color space only for current user.

This uses **WcsSetDefaultColorProfile** with WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER.

This is executable in LUA context if the profile is already installed, fails otherwise with access denied since install is system-wide and requires administrator privileges.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [SetStandardColorSpaceProfileW](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-setstandardcolorspaceprofilew)