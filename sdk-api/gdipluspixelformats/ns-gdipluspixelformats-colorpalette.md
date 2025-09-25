# ColorPalette structure

## Description

The **ColorPalette** structure defines an array of colors that make up a color palette. The colors are 32-bit ARGB colors.

## Members

### `Flags`

Type: **UINT**

Combination of flags from the [PaletteFlags](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ne-gdipluspixelformats-paletteflags) enumeration.

### `Count`

Type: **UINT**

Number of elements in the **Entries** array.

### `Entries`

Type: **ARGB[1]**

Array of ARGB colors.

## See also

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Image::GetPalette](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpalette)

[Image::SetPalette](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-setpalette)

[Types of Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-types-of-bitmaps-about)