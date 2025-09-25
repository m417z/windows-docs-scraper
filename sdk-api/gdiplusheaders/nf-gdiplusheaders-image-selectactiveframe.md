# Image::SelectActiveFrame

## Description

The **Image::SelectActiveFrame** method selects the frame in this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object specified by a dimension and an index.

## Parameters

### `dimensionID` [in]

Type: **const GUID***

Pointer to a
**GUID** that specifies the frame dimension.
**GUID**s that identify various frame dimensions are defined in Gdiplusimaging.h.

### `frameIndex` [in]

Type: **UINT**

Integer that specifies the index of the frame within the specified frame dimension.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

**Remarks**

When you call the **Image::SelectActiveFrame** method, all changes that you made to the previously active frame are discarded. If you want to retain changes that you make to a frame, call the
**Save** method before you switch to a different frame.

Among all the image formats currently supported by GDI+, the only formats that support multiple-frame images are GIF and TIFF. When you call the **Image::SelectActiveFrame** method on a GIF image, you should use FrameDimensionTime. When you call the **Image::SelectActiveFrame** method on a TIFF image, you should use FrameDimensionPage.

## See also

[EncoderParameter](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85))

[EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85))

[GetImageEncoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoders)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::Save Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-save(inistream_inconstclsid_inconstencoderparameters))

[Image::SaveAdd Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-saveadd(inimage_inconstencoderparameters))

[Using Image Encoders and Decoders](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-image-encoders-and-decoders-use)