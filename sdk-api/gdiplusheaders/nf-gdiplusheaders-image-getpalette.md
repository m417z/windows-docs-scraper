# Image::GetPalette

## Description

The **Image::GetPalette** method gets the [ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette) of this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `palette` [out]

Type: **[ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette)***

Pointer to a [ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette) structure that receives the palette.

### `size` [in]

Type: **INT**

Integer that specifies the size, in bytes, of the palette. Call the [Image::GetPaletteSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpalettesize) method to determine the size.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetPaletteSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpalettesize)

[Image::SetPalette](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-setpalette)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)