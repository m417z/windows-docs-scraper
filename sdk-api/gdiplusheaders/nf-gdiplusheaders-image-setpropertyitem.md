# Image::SetPropertyItem

## Description

The **Image::SetPropertyItem** method sets a property item (piece of metadata) for this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object. If the item already exists, then its contents are updated; otherwise, a new item is added.

## Parameters

### `item` [in]

Type: **const PropertyItem***

Pointer to a [PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85)) object that specifies the property item to be set.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Certain image formats (for example, ICON and EMF) don't support properties. If you call the **Image::SetPropertyItem** method on an image that doesn't support properties, it will return PropertyNotSupported.

#### Examples

The following console application creates a
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a JPEG file. The code calls the **Image::SetPropertyItem** method of that
**Image** object to set the title of the image. Then the code retrieves and displays the new title.

```cpp
#include <windows.h>
#include <gdiplus.h>
#include <stdio.h>
using namespace Gdiplus;

INT main()
{
   GdiplusStartupInput gdiplusStartupInput;
   ULONG_PTR gdiplusToken;
   GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

   // Create an Image object based on a JPEG file.
   Image* image = new Image(L"FakePhoto.jpg");

   // Set the image title.
   PropertyItem* propItem = new PropertyItem;
   CHAR newTitleValue[] = "Fake Photograph 2";

   propItem->id = PropertyTagImageTitle;
   propItem->length = 18;  //  includes null terminator
   propItem->type = PropertyTagTypeASCII;
   propItem->value = newTitleValue;

   image->SetPropertyItem(propItem);

   // Get and display the new image title.
   UINT size = image->GetPropertyItemSize(PropertyTagImageTitle);
   PropertyItem* title = (PropertyItem*)malloc(size);
   image->GetPropertyItem(PropertyTagImageTitle, size, title);
   printf("The image title is %s.\n", title->value);

   free(title);
   delete propItem;
   delete image;
   GdiplusShutdown(gdiplusToken);
   return 0;
}
```

## See also

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetPropertyCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertycount)

[Image::GetPropertyIdList](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyidlist)

[Image::GetPropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitem)

[Image::GetPropertyItemSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitemsize)

[Image::GetPropertySize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertysize)

[Image::RemovePropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-removepropertyitem)

[PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85))

[Reading and Writing Metadata](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-reading-and-writing-metadata-use)