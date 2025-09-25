# Image::GetFrameCount

## Description

The **Image::GetFrameCount** method gets the number of frames in a specified dimension of this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `dimensionID` [in]

Type: **const GUID***

Pointer to a
GUID that specifies the dimension.
GUIDs that identify various dimensions are defined in Gdiplusimaging.h.

## Return value

Type: **UINT**

This method returns the number of frames in the specified dimension of this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## See also

[Copying Individual Frames from a Multiple-Frame Image](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-copying-individual-frames-from-a-multiple-frame-image-use)

[Creating and Saving a Multiple-Frame Image](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-and-saving-a-multiple-frame-image-use)

[EncoderParameter](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85))

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetFrameDimensionsCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getframedimensionscount)

[Image::GetFrameDimensionsList](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getframedimensionslist)

[Image::SaveAdd Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-saveadd(inimage_inconstencoderparameters))