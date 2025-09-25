# Image::GetPropertyItem

## Description

The **Image::GetPropertyItem** method gets a specified property item (piece of metadata) from this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `propId` [in]

Type: **PROPID**

Integer that identifies the property item to be retrieved.

### `propSize` [in]

Type: **UINT**

Integer that specifies the size, in bytes, of the property item to be retrieved. Call the [Image::GetPropertyItemSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitemsize) method to determine the size.

### `buffer` [out]

Type: **[PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85))***

Pointer to a [PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85)) object that receives the property item.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The **Image::GetPropertyItem** method returns a [PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85)) object. Before you call
**Image::GetPropertyItem**, you must allocate a buffer large enough to receive that object — the size varies according to data type and value of the property item. You can call the [Image::GetPropertyItemSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitemsize) method of an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object to get the size, in bytes, of the required buffer.

#### Examples

The following example creates an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a JPEG file. The code gets the make of the camera that captured the image by passing the PropertyTagEquipMake constant to the **Image::GetPropertyItem** method of the
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

   UINT size = 0;
   PropertyItem* propertyItem = NULL;
   Image* image = new Image(L"FakePhoto.jpg");

   // Assume that the image has a property item of type PropertyItemEquipMake.
   // Get the size of that property item.
   size = image->GetPropertyItemSize(PropertyTagEquipMake);

   // Allocate a buffer to receive the property item.
   propertyItem = (PropertyItem*)malloc(size);

   // Get the property item.
   image->GetPropertyItem(PropertyTagEquipMake, size, propertyItem);

   // Display the members of the retrieved PropertyItem object.
   printf("The length of the property item is %u.\n", propertyItem->length);
   printf("The data type of the property item is %u.\n", propertyItem->type);

   if(propertyItem->type == PropertyTagTypeASCII)
      printf("The value of the property item is %s.\n", propertyItem->value);

   free(propertyItem);
   delete image;
   GdiplusShutdown(gdiplusToken);
   return 0;
}
```

The preceding code, along with a particular file, FakePhoto.jpg, produced the following output. Note that the data type is 2, the value of the PropertyTagTypeASCII constant that is defined in Gdiplusimaging.h.

```cpp
The length of the property item is 17.
The data type of the property item is 2.
The value of the property item is Northwind Traders.
```

## See also

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetAllPropertyItems](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getallpropertyitems)

[Image::GetPropertyCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertycount)

[Image::GetPropertyIdList](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyidlist)

[Image::GetPropertyItemSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitemsize)

[Image::GetPropertySize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertysize)

[Image::RemovePropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-removepropertyitem)

[Image::SetPropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-setpropertyitem)

[PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85))

[Reading and Writing Metadata](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-reading-and-writing-metadata-use)