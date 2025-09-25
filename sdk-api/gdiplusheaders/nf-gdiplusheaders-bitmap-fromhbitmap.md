# Bitmap::FromHBITMAP

## Description

The **Bitmap::FromHBITMAP** method creates a
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object based on a handle to a Windows Graphics Device Interface (GDI) bitmap and a handle to a GDI palette.

## Parameters

### `hbm` [in]

Type: **HBITMAP**

Handle to GDI bitmap.

### `hpal` [in]

Type: **HPALETTE**

Handle to a GDI palette used to define the bitmap colors if
*hbm* is not a device-independent bitmap (DIB).

## Return value

Type: **[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)***

This method returns a pointer to the new
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object.

## Remarks

You are responsible for deleting the GDI bitmap and the GDI palette. However, you should not delete the GDI bitmap or the GDI palette until after the GDI+
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object is deleted or goes out of scope.

Do not pass to the **Bitmap::FromHBITMAP** method a GDI bitmap or a GDI palette that is currently (or was previously) selected into a device context.

This method does not preserve the alpha channel of the source GDI bitmap.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap Constructors](https://msdn.microsoft.com/9b246a76-e8c0-41b2-9bb2-0df06ebc5563)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)