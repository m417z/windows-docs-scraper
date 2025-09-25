# UpdateICMRegKeyW function

## Description

*(Obsolete; retained for backward compatibility)*

The **UpdateICMRegKey** function manages color profiles and Color Management Modules in the system.

## Parameters

### `reserved`

Reserved, must be set to zero.

### `lpszCMID`

Points to a string that specifies the ICC profile identifier for the color management DLL to use with the profile.

### `lpszFileName`

Points to a fully qualified ICC color profile file name or to a **DEVMODE** structure.

### `command`

Specifies a function to execute. It can have one of the following values.

| Value | Meaning |
| --- | --- |
| **ICM_ADDPROFILE** | Installs the ICC profile in the system. |
| **ICM_DELETEPROFILE** | Uninstalls the ICC profile from the system, but does not delete the file. |
| **ICM_QUERYPROFILE** | Determines whether the profile is already installed in the system. |
| **ICM_SETDEFAULTPROFILE** | Makes the profile first among equals. |
| **ICM_REGISTERICMATCHER** | Registers a CMM in the system. The *pszFileName* parameter points to a fully qualified path for the CMM DLL. The *lpszCMID* parameter points to a **DWORD** identifying the CMM. |
| **ICM_UNREGISTERICMATCHER** | Unregisters the CMM from the system. The *lpszCMID* parameter points to a **DWORD** identifying the CMM. |
| **ICM_QUERYMATCH** | Determines whether a profile exists based on the **DEVMODE** structure pointed to by the *pszFileName* parameter. |

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**.

## Remarks

Not all parameters are used by all functions. The *nCommand* parameter specifies the function to execute.

This function is retained for backward compatibility and may be removed in future versions of ICM.

**Windows 95/98/Me:** **UpdateICMRegKeyW** is supported by the Microsoft Layer for Unicode. To use this, you must add certain files to your application, as outlined in [Microsoft Layer for Unicode on Windows 95/98/Me Systems](https://msdn.microsoft.com/library?url=/library/mslu/winprog/microsoft_layer_for_unicode_on_windows_95_98_me_systems.asp).

> [!NOTE]
> The wingdi.h header defines UpdateICMRegKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Obsolete WCS functions](https://learn.microsoft.com/windows/win32/wcs/obsolete-wcs-functions)