# IDWriteFontFace2::GetPaletteEntries

## Description

Gets color values from the font's color palette.

## Parameters

### `colorPaletteIndex`

Zero-based index of the color palette. If the font does not have a palette with the specified index, the method returns **DWRITE_E_NOCOLOR**.

### `firstEntryIndex`

Zero-based index of the first palette entry to read.

### `entryCount`

Number of palette entries to read.

### `paletteEntries` [out]

Array that receives the color values.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| E_INVALIDARG | The sum of *firstEntryIndex* and *entryCount* is greater than the actual number of palette entries that's returned by the [GetPaletteEntryCount](https://learn.microsoft.com/windows/win32/api/dwrite_2/nf-dwrite_2-idwritefontface2-getpaletteentrycount) method. |
| DWRITE_E_NOCOLOR | The font doesn't have a palette with the specified palette index. |

## See also

[IDWriteFontFace2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefontface2)