## Description

Associates a specified WCS color profile with a specified device.

> [!NOTE]
> This API does not support "advanced color" profiles for HDR monitors. Use [**ColorProfileAddDisplayAssociation**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofileadddisplayassociation) for managing advanced color profiles.

## Parameters

### `scope`

A [**WCS\_PROFILE\_MANAGEMENT\_SCOPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope) value that specifies the scope of this profile management operation, which could be system-wide or for the current user.

### `pProfileName`

A pointer to the file name of the profile to associate.

### `pDeviceName`

A pointer to the name of the device with which the profile is to be associated.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

The **WCSAssociateColorProfileWithDevice** function fails if the profile has not been installed on the computer using the [**InstallColorProfileW**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-installcolorprofilew) function.

If the *profileManagementScope* parameter is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_SYSTEM\_WIDE, the profile association is system-wide and applies to all users. If *profileManagementScope* is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER, the association is only for the current user.

This function is executable in Least-Privileged User Account (LUA) context if *profileManagementScope* is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER. Otherwise, administrative privileges are required.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [WcsDisassociateColorProfileFromDevice**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsdisassociatecolorprofilefromdevice)