# EnumICMProfilesA function

## Description

The **EnumICMProfiles** function enumerates the different output color profiles that the system supports for a given device context.

## Parameters

### `hdc`

Specifies the device context.

### `proc`

Specifies the procedure instance address of a callback function defined by the application. (See [EnumICMProfilesProcCallback](https://learn.microsoft.com/windows/desktop/api/wingdi/nc-wingdi-icmenumproca).)

### `param`

Data supplied by the application that is passed to the callback function along with the color profile information.

## Return value

This function returns zero if the application interrupted the enumeration. The return value is -1 if there are no color profiles to enumerate. Otherwise, the return value is the last value returned by the callback function.

## Remarks

The **EnumICMProfiles** function returns a list of profiles that are associated with a device context (DC), and whose settings match those of the DC. It is possible for a device context to contain device profiles that are not associated with particular hardware devices, or device profiles that do not match the settings of the DC. The sRGB profile is an example. The [SetICMProfile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-seticmprofilea) function is used to associate these types of profiles with a DC. The [GetICMProfile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-geticmprofilea) function can be used to retrieve a profile that is not enumerated by the **EnumICMProfiles** function.

**Windows 95/98/Me:****EnumICMProfilesW** is supported by the Microsoft Layer for Unicode. To use this, you must add certain files to your application, as outlined in [Microsoft Layer for Unicode on Windows 95/98/Me Systems](https://msdn.microsoft.com/library?url=/library/mslu/winprog/microsoft_layer_for_unicode_on_windows_95_98_me_systems.asp).

> [!NOTE]
> The wingdi.h header defines EnumICMProfiles as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [DeleteColorSpaceW](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-deletecolorspace)
* [ICMENUMPROCA callback function](https://learn.microsoft.com/windows/win32/api/wingdi/nc-wingdi-icmenumproca)
* [GetICMProfileW](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-geticmprofilew)
* [SetICMProfileW](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-seticmprofilew)