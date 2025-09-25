## Description

> [!NOTE]
> This API may be unavailable in future releases. We encourage new and existing software to use other APIs for color profile interactions. Please refer to the below table for some examples.
>
>| Scenario | Mechanism |
>| :------: | :------: |
>| Enumerating all installed profiles | Use [**WcsEnumColorProfilesSize**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsenumcolorprofilessize) and [**WcsEnumColorProfiles**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcsenumcolorprofiles), or [**EnumColorProfilesA**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-EnumColorProfilesA) |
>| Installing/Uninstalling color profiles | Use [**InstallColorProfileA**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-InstallColorProfileA)/[**UninstallColorProfileA**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-UninstallColorProfileA) |
>| Opening a color profile file directly | Use [**OpenColorProfileA**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-OpenColorProfileA) with dwType=PROFILE_FILENAME in the PROFILE struct parameter.\
 Or use [**WcsOpenColorProfileA**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-WcsOpenColorProfileA). [**Icm.h**](https://learn.microsoft.com/windows/win32/api/icm) contains many APIs that accept the returned HPROFILE for color profile manipulation |

\

Retrieves the path of the Windows COLOR directory on a specified machine.

## Parameters

### `pMachineName`

Reserved; must be **NULL**. This parameter is intended to point to the name of the machine on which the profile is to be installed. A **NULL** pointer indicates the local machine.

### `pBuffer`

Points to the buffer in which the color directory path is to be placed.

### `pdwSize`

Points to a variable containing the size in bytes of the buffer pointed to by *pBuffer*. On return, the variable contains the size of the buffer actually used or needed.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

**Per-user/LUA support**

Color directory is still system-wide. This function is executable in LUA context.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)