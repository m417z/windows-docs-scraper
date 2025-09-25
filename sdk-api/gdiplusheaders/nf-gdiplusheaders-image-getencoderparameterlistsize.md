# Image::GetEncoderParameterListSize

## Description

The **Image::GetEncoderParameterListSize** method gets the size, in bytes, of the parameter list for a specified image encoder.

## Parameters

### `clsidEncoder` [in]

Type: **const CLSID***

Pointer to a
**CLSID** that specifies the encoder.

## Return value

Type: **UINT**

This method returns the size, in bytes, of the parameter list.

## Remarks

The [Image::GetEncoderParameterList](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getencoderparameterlist) method returns an array of
[EncoderParameter](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85)) objects. Before you call **Image::GetEncoderParameterList**, you must allocate a buffer large enough to receive that array, which is part of an
[EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85)) object. You can call the **Image::GetEncoderParameterListSize** method to get the size, in bytes, of the required
**EncoderParameters** object.

## See also

[GetImageEncoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoders)

[GetImageEncodersSize](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoderssize)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetEncoderParameterList](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getencoderparameterlist)

[Using Image Encoders and Decoders](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-image-encoders-and-decoders-use)