# Image::GetItemData

## Description

The **Image::GetItemData** method gets one piece of metadata from this [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `item` [in]

Type: **[ImageItemData](https://learn.microsoft.com/previous-versions/ms534468(v=vs.85))***

Pointer to an [ImageItemData](https://learn.microsoft.com/previous-versions/ms534468(v=vs.85)) object that specifies the item to be retrieved. The Data member of the **ImageItemData** object points to a buffer that receives the custom metadata. If the Data member is set to **NULL**, this method returns the size of the required buffer in the DataSize member of the ImageItemData object.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)