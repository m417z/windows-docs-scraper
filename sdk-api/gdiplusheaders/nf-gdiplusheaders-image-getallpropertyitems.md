# Image::GetAllPropertyItems

## Description

The **Image::GetAllPropertyItems** method gets all the property items (metadata) stored in this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `totalBufferSize` [in]

Type: **UINT**

Integer that specifies the size, in bytes, of the
*allItems* buffer. Call the [Image::GetPropertySize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertysize) method to obtain the required size.

### `numProperties` [in]

Type: **UINT**

Integer that specifies the number of properties in the image. Call the [Image::GetPropertySize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertysize) method to obtain this number.

### `allItems` [out]

Type: **[PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85))***

Pointer to an array of [PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85)) objects that receives the property items.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
**Status** enumeration.

## Remarks

Some image files contain metadata that you can read to determine features of the image. For example, a digital photograph might contain metadata that you can read to determine the make and model of the camera used to capture the image.

GDI+ stores an individual piece of metadata in a [PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85)) object. The **Image::GetAllPropertyItems** method returns an array of **PropertyItem** objects. Before you call **Image::GetAllPropertyItems**, you must allocate a buffer large enough to receive that array. You can call the [Image::GetPropertySize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertysize) method of an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object to get the size, in bytes, of the required buffer. The **Image::GetPropertySize** method also gives you the number of properties (pieces of metadata) in the image.

Several enumerations and constants related to image metadata are defined in Gdiplusimaging.h.

#### Examples

The following example creates an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a JPEG file. The code calls the **GetAllPropertyItems** method of that
**Image** object to obtain its property items (metadata).

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

   // Find out how many property items are in the image, and find out the
   // required size of the buffer that will receive those property items.
   UINT totalBufferSize;
   UINT numProperties;
   image->GetPropertySize(&totalBufferSize, &numProperties);

   // Allocate the buffer that will receive the property items.
   PropertyItem* pAllItems = (PropertyItem*)malloc(totalBufferSize);

   // Fill the buffer.
   image->GetAllPropertyItems(totalBufferSize, numProperties, pAllItems);

// Print the id data member of each property item.
   for(UINT j = 0; j < numProperties; ++j)
   {
      printf("%x\n", pAllItems[j].id);
   }

   free(pAllItems);
   delete image;
   GdiplusShutdown(gdiplusToken);
   return 0;
}
```

The preceding code, along with a particular file, FakePhoto.jpg, produced the following output:

```cpp
320
10f
110
9003
829a
5090
5091
```

The preceding output shows a hexadecimal ID number for each property item. You can look up those ID numbers in Gdiplusimaging.h and find out that they represent the following property tags.

| Hexadecimal value | Property tag |
| --- | --- |
| 0x0320 | PropertyTagImageTitle |
| 0x010f | PropertyTagEquipMake |
| 0x0110 | PropertyTagEquipModel |
| 0x9003 | PropertyTagExifDTOriginal |
| 0x829a | PropertyTagExifExposureTime |
| 0x5090 | PropertyTagLuminanceTable |
| 0x5091 | PropertyTagChrominanceTable |

## See also

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetPropertyCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertycount)

[Image::GetPropertyIdList](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyidlist)

[Image::GetPropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitem)

[Image::GetPropertyItemSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitemsize)

[Image::GetPropertySize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertysize)

[Image::RemovePropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-removepropertyitem)

[Image::SetPropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-setpropertyitem)

[PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85))

[Reading and Writing Metadata](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-reading-and-writing-metadata-use)