# ICMENUMPROCA callback function

## Description

The **EnumICMProfilesProcCallback** callback is an application-defined callback function that processes color profile data from **EnumICMProfiles** .

## Parameters

### `unnamedParam1`

### `unnamedParam2`

#### - lParam

Data supplied by the application that is passed to the callback function by the [EnumICMProfiles](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumicmprofilesa) function.

#### - lpszFilename

Pointer to the file name of the color profile.

## Return value

This function must return a positive value to continue enumeration, or zero to stop enumeration. It may not return a negative value.

## Remarks

> [!NOTE]
> The wingdi.h header defines ICMENUMPROC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [EnumICMProfilesW](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-enumicmprofilesw)