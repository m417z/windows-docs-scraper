# SetICMProfileW function

## Description

The **SetICMProfile** function sets a specified color profile as the output profile for a specified device context (DC).

## Parameters

### `hdc`

Specifies a device context in which to set the color profile.

### `lpFileName`

Specifies the path name of the color profile to be set.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**.

## Remarks

**SetICMProfile** associates a color profile with a device context. It becomes the output profile for that device context. The color profile does not have to be associated with any particular device. Device-independent profiles such as sRGB can also be used. If the color profile is not associated with a hardware device, it will be returned by [GetICMProfile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-geticmprofilea), but not by [EnumICMProfiles](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumicmprofilesa).

Note that under Windows 95 or later, the PostScript device driver for printers assumes a CMYK color model. Therefore, all PostScript printers must use a CMYK color profile. Windows 2000 does not have this limitation.

**SetICMProfile** supports only RGB profiles in compatible DCs.

**Windows 95/98/Me:** **SetICMProfileW** is supported by the Microsoft Layer for Unicode. To use this, you must add certain files to your application, as outlined in [Microsoft Layer for Unicode on Windows 95/98/Me Systems](https://msdn.microsoft.com/library?url=/library/mslu/winprog/microsoft_layer_for_unicode_on_windows_95_98_me_systems.asp).

> [!NOTE]
> The wingdi.h header defines SetICMProfile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [EnumICMProfilesW](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-enumicmprofilesw)
* [GetICMProfileW](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-geticmprofilew)