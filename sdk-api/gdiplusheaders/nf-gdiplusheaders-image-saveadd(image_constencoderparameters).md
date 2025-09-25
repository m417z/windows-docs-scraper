# Image::SaveAdd(IN Image,IN const EncoderParameters)

## Description

The **Image::SaveAdd** method adds a frame to a file or stream specified in a previous call to the
**Save** method.

## Parameters

### `newImage` [in]

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

Pointer to an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that holds the frame to be added.

### `encoderParams` [in]

Type: **const [EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85))***

Pointer to an [EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85)) object that contains parameters required by the image encoder used in the save-add operation.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[EncoderParameter](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85))

[EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85))

[GetImageEncoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoders)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::Save Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-save(inistream_inconstclsid_inconstencoderparameters))

[Image::SaveAdd Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-saveadd(inimage_inconstencoderparameters))

[Image::SelectActiveFrame](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-selectactiveframe)

[Using Image Encoders and Decoders](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-image-encoders-and-decoders-use)