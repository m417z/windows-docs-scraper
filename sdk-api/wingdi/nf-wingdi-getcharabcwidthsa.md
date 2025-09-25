# GetCharABCWidthsA function

## Description

The **GetCharABCWidths** function retrieves the widths, in logical units, of consecutive characters in a specified range from the current TrueType font. This function succeeds only with TrueType fonts.

## Parameters

### `hdc` [in]

A handle to the device context.

### `wFirst` [in]

The first character in the group of consecutive characters from the current font.

### `wLast` [in]

The last character in the group of consecutive characters from the current font.

### `lpABC` [out]

A pointer to an array of [ABC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-abc) structures that receives the character widths, in logical units. This array must contain at least as many **ABC** structures as there are characters in the range specified by the *uFirstChar* and *uLastChar* parameters.

## Return value

If the function succeeds, the return value is nonzero

If the function fails, the return value is zero.

## Remarks

The TrueType rasterizer provides ABC character spacing after a specific point size has been selected. A spacing is the distance added to the current position before placing the glyph. B spacing is the width of the black part of the glyph. C spacing is the distance added to the current position to provide white space to the right of the glyph. The total advanced width is specified by A+B+C.

When the **GetCharABCWidths** function retrieves negative A or C widths for a character, that character includes underhangs or overhangs.

To convert the ABC widths to font design units, an application should use the value stored in the **otmEMSquare** member of a [OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica) structure. This value can be retrieved by calling the [GetOutlineTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getoutlinetextmetricsa) function.

The ABC widths of the default character are used for characters outside the range of the currently selected font.

To retrieve the widths of characters in non-TrueType fonts, applications should use the [GetCharWidth](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidtha) function.

> [!NOTE]
> The wingdi.h header defines GetCharABCWidths as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ABC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-abc)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetCharWidth](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidtha)

[GetOutlineTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getoutlinetextmetricsa)

[OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica)