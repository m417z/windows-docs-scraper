# Image::GetEncoderParameterList

## Description

The **Image::GetEncoderParameterList** method gets a list of the parameters supported by a specified image encoder.

## Parameters

### `clsidEncoder` [in]

Type: **const CLSID***

Pointer to a
**CLSID** that specifies the encoder.

### `size` [in]

Type: **UINT**

Integer that specifies the size, in bytes, of the
*buffer* array. Call the [Image::GetEncoderParameterListSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getencoderparameterlistsize) method to obtain the required size.

### `buffer` [out]

Type: **[EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85))***

Pointer to an
[EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85)) object that receives the list of supported parameters.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The **Image::GetEncoderParameterList** method returns an array of
[EncoderParameter](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85)) objects. Before you call **Image::GetEncoderParameterList**, you must allocate a buffer large enough to receive that array, which is part of an
[EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85)) object. You can call the [Image::GetEncoderParameterListSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getencoderparameterlistsize) method to get the size, in bytes, of the required
**EncoderParameters** object.

## See also

[GetImageEncoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoders)

[GetImageEncodersSize](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoderssize)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetEncoderParameterListSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getencoderparameterlistsize)

[Using Image Encoders and Decoders](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-image-encoders-and-decoders-use)