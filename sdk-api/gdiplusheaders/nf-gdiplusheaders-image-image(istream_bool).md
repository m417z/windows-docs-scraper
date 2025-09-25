# Image::Image(IN IStream,IN BOOL)

## Description

Creates an **Image::Image** object based on a stream.

## Parameters

### `stream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface. The implementation of IStream must include the **Seek**, **Read**, and **Stat** methods.

### `useEmbeddedColorManagement` [in]

Type: **BOOL**

Optional. **BOOL** value that specifies whether the new **Image::Image** object applies color correction according to color management information that is embedded in the stream. Embedded information can include ICC profiles, gamma values, and chromaticity information.

#### FALSE

Default. Specifies that color correction is enabled

#### TRUE

Specifies that color correction is not enabled

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Drawing, Positioning, and Cloning Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-positioning-and-cloning-images-about)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-image(gpimage_status))

[Image::Clone](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-clone)

[Image::FromFile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-fromfile)

[Image::FromStream](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-fromstream)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)