# SetMapperFlags function

## Description

The **SetMapperFlags** function alters the algorithm the font mapper uses when it maps logical fonts to physical fonts.

## Parameters

### `hdc` [in]

A handle to the device context that contains the font-mapper flag.

### `flags` [in]

Specifies whether the font mapper should attempt to match a font's aspect ratio to the current device's aspect ratio. If bit zero is set, the mapper selects only matching fonts.

## Return value

If the function succeeds, the return value is the previous value of the font-mapper flag.

If the function fails, the return value is GDI_ERROR.

## Remarks

If the *dwFlag* parameter is set and no matching fonts exist, Windows chooses a new aspect ratio and retrieves a font that matches this ratio.

The remaining bits of the *dwFlag* parameter must be zero.

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetAspectRatioFilterEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getaspectratiofilterex)