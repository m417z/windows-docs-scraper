## Description

Associates a specified color profile with a specified device.

> [!NOTE]
> This API does not support "advanced color" profiles for HDR monitors. Use [**ColorProfileAddDisplayAssociation**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofileadddisplayassociation) for managing advanced color profiles.

## Parameters

### `pMachineName`

Reserved. Must be **NULL**. This parameter is intended to point to the name of the machine on which to associate the specified profile and device. A **NULL** pointer indicates the local machine.

### `pProfileName`

Points to the file name of the profile to associate.

### `pDeviceName`

Points to the name of the device to associate.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **AssociateColorProfileWithDevice** function will fail if the profile has not been installed on the computer using the [**InstallColorProfileW**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-installcolorprofilew) function.

Note that under Windows (Windows 95 or later), the PostScript device driver for printers assumes a CMYK color model. Therefore, all PostScript printers must use a CMYK color profile. Windows 2000 does not have this limitation.

If the specified device is a monitor, this function updates the default profile.

Several profiles are typically associated with printers, based on paper and ink types. There is no default. The GDI selects the best one from the associated profiles when your application creates a device context (DC).

Scanners also have no default profile. However, it is atypical to associate more than one profile with a scanner.

**AssociateColorProfileWithDevice** always adds the specified profile to the current user's per-user profile association list for the specified device. Before adding the profile to the list, **AssociateColorProfileWithDevice** determines whether the user has previously expressed the desire to use a per-user profile association list for the device. If so, then **AssociateColorProfileWithDevice** simply adds the specified profile to the existing per-user profile association list for the device. If not, then **AssociateColorProfileWithDevice** creates a new per-user profile association list for the device by copying the system-wide association list for that device. It then appends the specified profile to the per-user list. From that point on, the current user will be using a per-user profile association list for the specified device, as if [**WcsSetUsePerUserProfiles**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcssetuseperuserprofiles) had been called for *pDevice* with the *usePerUserProfiles* parameter set to **TRUE**.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [DisassociateColorProfileFromDevice](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-disassociatecolorprofilefromdevicew)