# Image::FromStream

## Description

The **Image::FromStream** method creates a new
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a stream.

## Parameters

### `stream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to an
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface. The implementation of
IStream must include the
[IStream::Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek),
**Read**, and
[IStream::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat) methods.

### `useEmbeddedColorManagement` [in]

Type: **BOOL**

Optional. Boolean value that specifies whether the new
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object applies color correction according to color management information that is embedded in the stream. Embedded information can include International Color Consortium (ICC) profiles, gamma values, and chromaticity information. **TRUE** specifies that color correction is enabled, and **FALSE** specifies that color correction is not enabled. The default value is **FALSE**.

## Return value

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

This method returns a pointer to the new
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Drawing, Positioning, and Cloning Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-positioning-and-cloning-images-about)

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-image(gpimage_status))

[Image::Clone](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-clone)

[Image::FromFile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-fromfile)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)

[StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage)