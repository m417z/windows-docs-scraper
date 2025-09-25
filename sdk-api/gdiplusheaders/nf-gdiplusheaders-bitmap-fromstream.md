# Bitmap::FromStream

## Description

The **Bitmap::FromStream** method creates a
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object based on a stream.

## Parameters

### `stream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to an
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) COM interface. The implementation of
IStream must include the
[IStream::Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek),
**Read**, and
[IStream::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat) methods.

### `useEmbeddedColorManagement` [in]

Type: **BOOL**

Optional. **BOOL** value that specifies whether the new
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object applies color correction according to color management information that is embedded in the stream. Embedded information can include International Color Consortium (ICC) profiles, gamma values, and chromaticity information. **TRUE** specifies that color correction is enabled, and **FALSE** specifies that color correction is not enabled. The default value is **FALSE**.

## Return value

Type: **[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)***

This method returns a pointer to the new
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)