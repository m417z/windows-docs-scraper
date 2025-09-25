# Image::Image(IN const WCHAR,IN BOOL)

## Description

Creates an **Image::Image** object based on a file.

## Parameters

### `filename` [in]

Type: **const WCHAR***

Pointer to a wide-character string that specifies the name of the file.

### `useEmbeddedColorManagement` [in]

Type: **BOOL**

Optional. Boolean value that specifies whether the new **Image::Image** object applies color correction according to color management information that is embedded in the image file. Embedded information can include ICC profiles, gamma values, and chromaticity information.

#### FALSE

Default. Specifies that color correction is enabled

#### TRUE

Specifies that color correction is not enabled

## Remarks

You can construct **Image::Image** objects based on files of a variety of types including BMP, Graphics Interchange Format (GIF), JPEG, PNG, TIFF, and EMF.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Drawing, Positioning, and Cloning Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-positioning-and-cloning-images-about)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-image(gpimage_status))

[Image::Clone](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-clone)

[Image::FromFile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-fromfile)

[Image::FromStream](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-fromstream)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)