# Bitmap::Bitmap(IN HBITMAP,IN HPALETTE)

## Description

Creates a **Bitmap::Bitmap** object based on a handle to a Windows Windows Graphics Device Interface (GDI) bitmap and a handle to a GDI palette.

## Parameters

### `hbm` [in]

Type: **HBITMAP**

Handle to a GDI bitmap.

### `hpal` [in]

Type: **HPALETTE**

Handle to a GDI palette used to define the bitmap colors if
*hbm* is not a device-independent bitmap (DIB).

## Remarks

You are responsible for deleting the GDI bitmap and the GDI palette. However, you should not delete the GDI bitmap or the GDI palette until after the GDI+ **Bitmap::Bitmap** object is deleted or goes out of scope.

Do not pass to the GDI+ **Bitmap::Bitmap** constructor a GDI bitmap or a GDI palette that is currently (or was previously) selected into a device context.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap Constructors](https://msdn.microsoft.com/9b246a76-e8c0-41b2-9bb2-0df06ebc5563)

[Bitmap::FromHBITMAP](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-fromhbitmap)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)