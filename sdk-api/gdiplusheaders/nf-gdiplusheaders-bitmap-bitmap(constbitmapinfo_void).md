# Bitmap::Bitmap(IN const BITMAPINFO,IN VOID)

## Description

Creates a **Bitmap::Bitmap** object based on a
**BITMAPINFO** structure and an array of pixel data.

## Parameters

### `gdiBitmapInfo` [in]

Type: **const [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)***

Pointer to a GDI **BITMAPINFO** structure. This structure defines several bitmap attributes, such as size and pixel format. The
**BITMAPINFO** structure is defined in Wingdi.h.

### `gdiBitmapData` [in]

Type: **VOID***

Pointer to an array of bytes that contains the pixel data.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap Constructors](https://msdn.microsoft.com/9b246a76-e8c0-41b2-9bb2-0df06ebc5563)

[Bitmap::FromBITMAPINFO](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-frombitmapinfo)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)