# Image::FindFirstItem

## Description

The **Image::FindFirstItem** method retrieves the description and the data size of the first metadata item in this [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `item` [in, out]

Type: **[ImageItemData](https://learn.microsoft.com/previous-versions/ms534468(v=vs.85))***

Pointer to an [ImageItemData](https://learn.microsoft.com/previous-versions/ms534468(v=vs.85)) object. On input, the Desc member points to a buffer (allocated by the caller) large enough to hold the metadata description (1 byte for JPEG, 4 bytes for PNG, 11 bytes for GIF), and the DescSize member specifies the size (1, 4, or 6) of the buffer pointed to by Desc. On output, the buffer pointed to by Desc receives the metadata description, and the DataSize member receives the size, in bytes, of the metadata itself.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Use **Image::FindFirstItem** along with [Image::FindNextItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-findnextitem) to enumerate the metadata items, including custom metadata, stored in an image. **Image::FindFirstItem** and **Image::FindNextItem** do not enumerate the metadata items stored by the [Image::SetPropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-setpropertyitem) method.

## See also

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetItemData](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getitemdata)