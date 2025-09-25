# GetICMProfileW function

## Description

The **GetICMProfile** function retrieves the file name of the current output color profile for a specified device context.

## Parameters

### `hdc`

Specifies a device context from which to retrieve the color profile.

### `pBufSize`

Pointer to a **DWORD** that contains the size of the buffer pointed to by *lpszFilename*. For the ANSI version of this function, the size is in bytes. For the Unicode version, the size is in WCHARs. If this function is successful, on return this parameter contains the size of the buffer actually used. However, if the buffer is not large enough, this function returns **FALSE**. In this case, the **GetLastError()** function returns ERROR_INSUFFICIENT_BUFFER and the **DWORD** pointed to by this parameter contains the size needed for the *lpszFilename* buffer.

### `pszFilename`

Points to the buffer that receives the path name of the profile.

## Return value

If this function succeeds, the return value is **TRUE**. It also returns **TRUE** if the *lpszFilename* parameter is **NULL** and the size required for the buffer is copied into *lpcbName.*

If this function fails, the return value is **FALSE**.

## Remarks

**GetICMProfile** obtains the file name of the current output profile regardless of whether or not color management is enabled for the device context.

Given a device context, **GetICMProfile** will output, through the parameter *lpszFilename*, the path name of the file containing the color profile currently being used by the device context. It will also output, through the parameter *lpcbName*, the length of the string containing the path name.

It is possible that the profile name returned by **GetICMProfile** will not be in the list of profiles returned by [EnumICMProfiles](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumicmprofilesa). The **EnumICMProfiles** function returns all color space profiles that are associated with a device context (DC) whose settings match that of the DC. If the [SetICMProfile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-seticmprofilea) function is used to set the current profile, a profile may be associated with the DC that does not match its settings. For instance, the **SetICMProfile** function can be used to associate the device-independent sRGB profile with a DC. This profile will be used as the current WCS profile for that DC, and calls to **GetICMProfile** will return its file name. However, the profile will not appear in the list of profiles that is returned from **EnumICMProfiles**.

If this function is called before any calls to the **SetICMProfile** function, it can be used to get the default profile for a device context.

**Windows 95/98/Me:** **GetICMProfileW** is supported by the Microsoft Layer for Unicode. To use this, you must add certain files to your application, as outlined in [Microsoft Layer for Unicode on Windows 95/98/Me Systems](https://msdn.microsoft.com/library?url=/library/mslu/winprog/microsoft_layer_for_unicode_on_windows_95_98_me_systems.asp).

> [!NOTE]
> The wingdi.h header defines GetICMProfile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [EnumICMProfilesW](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-enumicmprofilesw)
* [SetICMProfileW](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-seticmprofilew)