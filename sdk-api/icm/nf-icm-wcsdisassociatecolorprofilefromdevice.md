## Description

Disassociates a specified WCS color profile from a specified device on a computer.

> [!NOTE]
> This API does not support "advanced color" profiles for HDR monitors. Use [**ColorProfileRemoveDisplayAssociation**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofileremovedisplayassociation) for managing advanced color profiles.

## Parameters

### `scope`

A [**WCS\_PROFILE\_MANAGEMENT\_SCOPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-wcs_profile_management_scope) value that specifies the scope of this profile management operation, which could be system-wide or for the current user.

### `pProfileName`

A pointer to the file name of the profile to disassociate.

### `pDeviceName`

A pointer to the name of the device from which to disassociate the profile.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

The WCS color profile should be installed. Moreover, you must use the same *profileManagementScope* value as when the device was associated with the profile. See [**WcsAssociateColorProfileWithDevice**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsassociatecolorprofilewithdevice).

If *profileManagementScope* is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_SYSTEM\_WIDE, the profile disassociation is systemwide and applies to all users. If *profileManagementScope* is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER, the disassociation is only for the current user.

If more than one color profile is associated with a device, WCS uses the last associated profile as the default. For example, if your application sequentially associates three profiles with a device, WCS uses the last profile associated as the default. If your application then calls the **WcsDisassociateColorProfileFromDevice** function to disassociate the third profile (which is the default in this example), WCS uses the second profile as the default.

If your application disassociates all profiles from a device, WCS uses the sRGB profile as the default.

If *profileManagementScope* is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER, this function is executable in Least-Privileged User Account (LUA) context. Otherwise, administrative privileges are required.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [WcsAssociateColorProfileWithDevice](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsassociatecolorprofilewithdevice)