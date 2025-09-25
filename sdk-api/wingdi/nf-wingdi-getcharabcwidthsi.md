# GetCharABCWidthsI function

## Description

The **GetCharABCWidthsI** function retrieves the widths, in logical units, of consecutive glyph indices in a specified range from the current TrueType font. This function succeeds only with TrueType fonts.

## Parameters

### `hdc` [in]

A handle to the device context.

### `giFirst` [in]

The first glyph index in the group of consecutive glyph indices from the current font. This parameter is only used if the *pgi* parameter is **NULL**.

### `cgi` [in]

The number of glyph indices.

### `pgi` [in]

A pointer to an array that contains glyph indices. If this parameter is **NULL**, the *giFirst* parameter is used instead. The *cgi* parameter specifies the number of glyph indices in this array.

### `pabc` [out]

A pointer to an array of [ABC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-abc) structures that receives the character widths, in logical units. This array must contain at least as many **ABC** structures as there are glyph indices specified by the *cgi* parameter.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The TrueType rasterizer provides ABC character spacing after a specific point size has been selected. A spacing is the distance added to the current position before placing the glyph. B spacing is the width of the black part of the glyph. C spacing is the distance added to the current position to provide white space to the right of the glyph. The total advanced width is specified by A+B+C.

When the **GetCharABCWidthsI** function retrieves negative A or C widths for a character, that character includes underhangs or overhangs.

To convert the ABC widths to font design units, an application should use the value stored in the **otmEMSquare** member of a [OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica) structure. This value can be retrieved by calling the [GetOutlineTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getoutlinetextmetricsa) function.

The ABC widths of the default character are used for characters outside the range of the currently selected font.

To retrieve the widths of glyph indices in non-TrueType fonts, applications should use the [GetCharWidthI](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidthi) function.

## See also

[ABC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-abc)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetCharWidth](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidtha)

[GetOutlineTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getoutlinetextmetricsa)

[OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica)