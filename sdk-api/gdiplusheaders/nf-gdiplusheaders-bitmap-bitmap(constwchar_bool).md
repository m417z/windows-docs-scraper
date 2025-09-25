# Bitmap::Bitmap(IN const WCHAR,IN BOOL)

## Description

Creates a **Bitmap::Bitmap** object based on an image file.

## Parameters

### `filename` [in]

Type: **const WCHAR***

Pointer to a null-terminated string that specifies the path name of the image file. The graphics file formats supported by GDI+ are BMP, GIF, JPEG, PNG, TIFF, Exif, WMF, and EMF.

### `useEmbeddedColorManagement` [in]

Type: **BOOL**

Optional. Boolean value that specifies whether the new **Bitmap::Bitmap** object applies color correction according to color management information that is embedded in the image file. Embedded information can include International Color Consortium (ICC) profiles, gamma values, and chromaticity information. **TRUE** specifies that color correction is enabled, and **FALSE** specifies that color correction is not enabled. The default value is **FALSE**.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap Constructors](https://msdn.microsoft.com/9b246a76-e8c0-41b2-9bb2-0df06ebc5563)

[Bitmap::FromFile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-fromfile)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)