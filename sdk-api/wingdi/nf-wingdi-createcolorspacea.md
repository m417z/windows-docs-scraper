# CreateColorSpaceA function

## Description

The **CreateColorSpace** function creates a logical [color space](https://learn.microsoft.com/windows/win32/wcs/c#color-space).

## Parameters

### `lplcs`

Pointer to the [LOGCOLORSPACE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logcolorspacea) data structure.

## Return value

If this function succeeds, the return value is a handle that identifies a color space.

If this function fails, the return value is **NULL**.

## Remarks

When the color space is no longer needed, use **DeleteColorSpace** to delete it.

**Windows 95/98/Me:** **CreateColorSpaceW** is supported by the Microsoft Layer for Unicode. To use this, you must add certain files to your application, as outlined in [Microsoft Layer for Unicode on Windows 95/98/Me Systems](https://msdn.microsoft.com/library?url=/library/mslu/winprog/microsoft_layer_for_unicode_on_windows_95_98_me_systems.asp).

> [!NOTE]
> The wingdi.h header defines CreateColorSpace as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [DeleteColorSpaceW](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-deletecolorspace)