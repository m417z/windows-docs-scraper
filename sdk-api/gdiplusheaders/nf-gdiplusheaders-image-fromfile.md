# Image::FromFile

## Description

The **Image::FromFile** method creates an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a file.

## Parameters

### `filename` [in]

Type: **const WCHAR***

Pointer to a wide-character string that specifies the name of the file.

### `useEmbeddedColorManagement` [in]

Type: **BOOL**

Optional. Boolean value that specifies whether the new
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object applies color correction according to color management information that is embedded in the image file. Embedded information can include International Color Consortium (ICC) profiles, gamma values, and chromaticity information. **TRUE** specifies that color correction is enabled, and **FALSE** specifies that color correction is not enabled. The default value is **FALSE**.

## Return value

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

This method returns a pointer to the new
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Remarks

You can create
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) objects based on files of a variety of types including BMP, GIF, JPEG, PNG, TIFF, and EMF.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Drawing, Positioning, and Cloning Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-positioning-and-cloning-images-about)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-image(gpimage_status))

[Image::Clone](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-clone)

[Image::FromStream](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-fromstream)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)