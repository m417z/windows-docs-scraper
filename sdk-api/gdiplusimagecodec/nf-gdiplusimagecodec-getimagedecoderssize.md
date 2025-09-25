# GetImageDecodersSize function

## Description

The **GetImageDecodersSize** function gets the number of available image decoders and the total size of the array of
[ImageCodecInfo](https://learn.microsoft.com/previous-versions/ms534466(v=vs.85)) objects that is returned by the [GetImageDecoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimagedecoders) function.

## Parameters

### `numDecoders` [out]

Type: **UINT***

Pointer to a **UINT** that receives the number of available image decoders.

### `size` [out]

Type: **UINT***

Pointer to a
**UINT** that receives the total size, in bytes, of the array of
[ImageCodecInfo](https://learn.microsoft.com/previous-versions/ms534466(v=vs.85)) objects that is returned by the [GetImageDecoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimagedecoders) function.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the function succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the function fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[GetImageDecoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimagedecoders)

[GetImageEncoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoders)

[GetImageEncodersSize](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoderssize)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Using Image Encoders and Decoders](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-image-encoders-and-decoders-use)