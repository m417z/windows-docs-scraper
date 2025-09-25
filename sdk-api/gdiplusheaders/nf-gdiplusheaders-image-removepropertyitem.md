# Image::RemovePropertyItem

## Description

The **Image::RemovePropertyItem** method removes a property item (piece of metadata) from this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `propId` [in]

Type: **PROPID**

Integer that identifies the property item to be removed.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The **Image::RemovePropertyItem** method removes a specified property from an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object, but that property item is not removed from the file or stream that was used to construct the
**Image** object. To save the image (with the property item removed) to a new JPEG file or stream, call the
**Save** method of the
**Image** object.

#### Examples

The following example creates an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a JPEG file. The code removes the PropertyTagEquipMake property item from the
**Image** object by calling its **Image::RemovePropertyItem** method. The code calls [Image::GetPropertyItemSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitemsize) twice (once before and once after removing the item) to determine the size of the PropertyTagEquipMake property item. The code does not remove the property item from the image file; it removes the property item only from the
**Image** object.

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

   Image* image = new Image(L"FakePhoto3.jpg");
   UINT size = 0;

   size = image->GetPropertyItemSize(PropertyTagEquipMake);
   printf("The size of the PropertyTagEquipMake item is %u.\n", size);

   image->RemovePropertyItem(PropertyTagEquipMake);

   size = image->GetPropertyItemSize(PropertyTagEquipMake);
   printf("The size of the PropertyTagEquipMake item is %u.\n", size);

   delete image;
   GdiplusShutdown(gdiplusToken);
   return 0;
}
```

The preceding code, along with a particular file, FakePhoto3.jpg, produced the following output:

```cpp
The size of the PropertyTagEquipMake item is 33.
The size of the PropertyTagEquipMake item is 0.
```

## See also

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetAllPropertyItems](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getallpropertyitems)

[Image::GetPropertyCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertycount)

[Image::GetPropertyIdList](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyidlist)

[Image::GetPropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitem)

[Image::GetPropertyItemSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitemsize)

[Image::GetPropertySize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertysize)

[Image::SetPropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-setpropertyitem)

[PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85))

[Reading and Writing Metadata](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-reading-and-writing-metadata-use)