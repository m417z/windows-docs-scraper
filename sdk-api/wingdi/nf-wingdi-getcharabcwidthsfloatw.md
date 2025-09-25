# GetCharABCWidthsFloatW function

## Description

The **GetCharABCWidthsFloat** function retrieves the widths, in logical units, of consecutive characters in a specified range from the current font.

## Parameters

### `hdc` [in]

Handle to the device context.

### `iFirst` [in]

Specifies the code point of the first character in the group of consecutive characters where the ABC widths are seeked.

### `iLast` [in]

Specifies the code point of the last character in the group of consecutive characters where the ABC widths are seeked. This range is inclusive. An error is returned if the specified last character precedes the specified first character.

### `lpABC` [out]

Pointer to an array of [ABCFLOAT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-abcfloat) structures that receives the character widths, in logical units.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Unlike the [GetCharABCWidths](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsa) function that returns widths only for TrueType fonts, the **GetCharABCWidthsFloat** function retrieves widths for any font. The widths returned by this function are in the IEEE floating-point format.

If the current world-to-device transformation is not identified, the returned widths may be noninteger values, even if the corresponding values in the device space are integers.

A spacing is the distance added to the current position before placing the glyph. B spacing is the width of the black part of the glyph. C spacing is the distance added to the current position to provide white space to the right of the glyph. The total advanced width is specified by A+B+C.

The ABC spaces are measured along the character base line of the selected font.

The ABC widths of the default character are used for characters outside the range of the currently selected font.

> [!NOTE]
> The wingdi.h header defines GetCharABCWidthsFloat as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ABCFLOAT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-abcfloat)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetCharABCWidths](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsa)

[GetCharWidth](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidtha)

[GetCharWidthFloat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidthfloata)