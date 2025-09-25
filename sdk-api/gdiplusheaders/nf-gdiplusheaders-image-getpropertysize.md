# Image::GetPropertySize

## Description

The **Image::GetPropertySize** method gets the total size, in bytes, of all the property items stored in this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object. The **Image::GetPropertySize** method also gets the number of property items stored in this
**Image** object.

## Parameters

### `totalBufferSize` [out]

Type: **UINT***

Pointer to a
**UINT** that receives the total size, in bytes, of all the property items.

### `numProperties` [out]

Type: **UINT***

Pointer to a
**UINT** that receives the number of property items.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Windows GDI+ stores an individual piece of metadata in a [PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85)) object. The [Image::GetAllPropertyItems](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getallpropertyitems) method returns an array of **PropertyItem** objects. Before you call **Image::GetAllPropertyItems**, you must allocate a buffer large enough to receive that array. You can call the **Image::GetPropertySize** method of an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object to get the size, in bytes, of the required buffer. The **Image::GetPropertySize** method also gives you the number of properties (pieces of metadata) in the image.

#### Examples

The following example creates an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a JPEG file. The code calls the [Image::GetAllPropertyItems](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getallpropertyitems) method of that
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

   // Print the ID of each property item.
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

The preceding output shows the hexadecimal value of each property identifier. You can look up those numbers in Gdiplusimaging.h and find out that they represent the following property tags.

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

[Image::GetAllPropertyItems](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getallpropertyitems)

[Image::GetPropertyCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertycount)

[Image::GetPropertyIdList](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyidlist)

[Image::GetPropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitem)

[Image::GetPropertyItemSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitemsize)

[Image::RemovePropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-removepropertyitem)

[Image::SetPropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-setpropertyitem)

[PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85))

[Reading and Writing Metadata](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-reading-and-writing-metadata-use)