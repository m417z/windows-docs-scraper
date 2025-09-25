# GetCharWidthI function

## Description

The **GetCharWidthI** function retrieves the widths, in logical coordinates, of consecutive glyph indices in a specified range from the current font.

## Parameters

### `hdc` [in]

A handle to the device context.

### `giFirst` [in]

The first glyph index in the group of consecutive glyph indices.

### `cgi` [in]

The number of glyph indices.

### `pgi` [in]

A pointer to an array of glyph indices. If this parameter is not **NULL**, it is used instead of the *giFirst* parameter.

### `piWidths` [out]

A pointer to a buffer that receives the widths, in logical coordinates.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **GetCharWidthI** function processes a consecutive glyph indices if the *pgi* parameter is **NULL** with the *giFirst* parameter indicating the first glyph index to process and the *cgi* parameter indicating how many glyph indices to process. Otherwise the **GetCharWidthI** function processes the array of glyph indices pointed to by the *pgi* parameter with the *cgi* parameter indicating how many glyph indices to process.

If a character does not exist in the current font, it is assigned the width of the default character.

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetCharABCWidths](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsa)

[GetCharABCWidthsFloat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsfloata)

[GetCharWidth32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidth32a)

[GetCharWidthFloat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidthfloata)