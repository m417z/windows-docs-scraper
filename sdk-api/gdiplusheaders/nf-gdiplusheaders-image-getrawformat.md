# Image::GetRawFormat

## Description

The **Image::GetRawFormat** method gets a globally unique identifier ( GUID) that identifies the format of this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.
GUIDs that identify various file formats are defined in Gdiplusimaging.h.

## Parameters

### `format` [out]

Type: **GUID***

Pointer to a
GUID that receives the format identifier.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetType](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-gettype)

[ImageType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-imagetype)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)