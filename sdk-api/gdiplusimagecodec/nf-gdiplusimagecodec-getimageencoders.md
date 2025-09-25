# GetImageEncoders function

## Description

The **GetImageEncoders** function gets an array of
[ImageCodecInfo](https://learn.microsoft.com/previous-versions/ms534466(v=vs.85)) objects that contain information about the available image encoders.

## Parameters

### `numEncoders` [in]

Type: **UINT**

Integer that specifies the number of available image encoders. Call [GetImageEncodersSize](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoderssize) to determine this number.

### `size` [in]

Type: **UINT**

Integer that specifies the size, in bytes, of the array of
[ImageCodecInfo](https://learn.microsoft.com/previous-versions/ms534466(v=vs.85)) objects. Call [GetImageEncodersSize](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoderssize) to determine this number.

### `encoders` [out]

Type: **[ImageCodecInfo](https://learn.microsoft.com/previous-versions/ms534466(v=vs.85))***

Pointer to a buffer that receives the array of
[ImageCodecInfo](https://learn.microsoft.com/previous-versions/ms534466(v=vs.85)) objects. You must allocate memory for this buffer. Call [GetImageEncodersSize](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoderssize) to determine the size of the required buffer.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the function succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the function fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[GetImageDecoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimagedecoders)

[GetImageDecodersSize](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimagedecoderssize)

[GetImageEncodersSize](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoderssize)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Using Image Encoders and Decoders](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-image-encoders-and-decoders-use)