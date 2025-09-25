# Image::GetPropertyIdList

## Description

The **Image::GetPropertyIdList** method gets a list of the property identifiers used in the metadata of this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `numOfProperty` [in]

Type: **UINT**

Integer that specifies the number of elements in the
*list* array. Call the [Image::GetPropertyCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertycount) method to determine this number.

### `list` [out]

Type: **PROPID***

Pointer to an array that receives the property identifiers.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The **Image::GetPropertyIdList** method returns an array of
**PROPID**s. Before you call **Image::GetPropertyIdList**, you must allocate a buffer large enough to receive that array. You can call the [Image::GetPropertyCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertycount) method of an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object to determine the size of the required buffer. The size of the buffer should be the return value of **Image::GetPropertyCount** multiplied by
**sizeof**(
**PROPID**).

#### Examples

The following example creates an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a JPEG file. The code calls the **Image::GetPropertyIdList** method of that
**Image** object to find out what types of metadata are stored in the image.

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

   UINT count = 0;
   Image* image = new Image(L"FakePhoto.jpg");

   // How many types of metadata are in the image?
   count = image->GetPropertyCount();
   if(count == 0)
      return 0;

   // Allocate a buffer to receive an array of PROPIDs.
   PROPID* propIDs = new PROPID[count];

   image->GetPropertyIdList(count, propIDs);

   // List the retrieved IDs.
   for(UINT j = 0; j < count; ++j)
      printf("%x\n", propIDs[j]);

   delete [] propIDs;
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

[Image::GetPropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitem)

[Image::GetPropertyItemSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertyitemsize)

[Image::GetPropertySize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpropertysize)

[Image::RemovePropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-removepropertyitem)

[Image::SetPropertyItem](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-setpropertyitem)

[PropertyItem](https://learn.microsoft.com/previous-versions/ms534493(v=vs.85))

[Reading and Writing Metadata](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-reading-and-writing-metadata-use)