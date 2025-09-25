# Image::GetFrameDimensionsList

## Description

The **Image::GetFrameDimensionsList** method gets the identifiers for the frame dimensions of this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `dimensionIDs` [out]

Type: **GUID***

Pointer to an array that receives the identifiers.
GUIDs that identify various dimensions are defined in Gdiplusimaging.h.

### `count` [in]

Type: **UINT**

Integer that specifies the number of elements in the
*dimensionIDs* array. Call the
[Image::GetFrameDimensionsCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getframedimensionscount) method to determine this number.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

This method returns information about multiple-frame images, which come in two styles: multiple page and multiple resolution.

A multiple-page image is an image that contains more than one image. Each page contains a single image (or frame). These pages (or images, or frames) are typically displayed in succession to produce an animated sequence, such as in an animated GIF file.

A multiple-resolution image is an image that contains more than one copy of an image at different resolutions.

Windows GDI+ can support an arbitrary number of pages (or images, or frames), as well as an arbitrary number of resolutions.

#### Examples

The following console application creates an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a TIFF file. The code calls the [Image::GetFrameDimensionsCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getframedimensionscount) method to find out how many frame dimensions the
**Image** object has. Each of those frame dimensions is identified by a
GUID, and the call to **GetFrameDimensionsList** retrieves those
GUIDs. The first
GUID is at index 0 in the
*pDimensionIDs* array. The call to the [Image::GetFrameCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getframecount) method determines the number of frames in the dimension identified by the first
GUID.

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

   Image* image = new Image(L"Multiframe.tif");

   // How many frame dimensions does the Image object have?
   UINT count = 0;
   count = image->GetFrameDimensionsCount();
   printf("The number of dimensions is %d.\n", count);
   GUID* pDimensionIDs = (GUID*)malloc(sizeof(GUID)*count);

   // Get the list of frame dimensions from the Image object.
   image->GetFrameDimensionsList(pDimensionIDs, count);

   // Display the GUID of the first (and only) frame dimension.
   WCHAR strGuid[39];
   StringFromGUID2(pDimensionIDs[0], strGuid, 39);
   wprintf(L"The first (and only) dimension ID is %s.\n", strGuid);

   // Get the number of frames in the first dimension.
   UINT frameCount = image->GetFrameCount(&pDimensionIDs[0]);
   printf("The number of frames in that dimension is %d.\n", frameCount);

   free(pDimensionIDs);
   delete(image);
   GdiplusShutdown(gdiplusToken);
   return 0;
}
```

The preceding code, along with a particular file, Multiframe.tif, produced the following output:

```cpp
The number of dimensions is 1.
The first (and only) dimension ID is {7462DC86-6180-4C7E-8E3F-EE7333A7A483}.
The number of frames in that dimension is 4.
```

You can look up the displayed GUID in Gdiplusimaging.h and see that it is the identifier for the page dimension. So the program output tells us that the file Multiframe.tif has four pages; that is, four frames in the page dimension.

## See also

[Copying Individual Frames from a Multiple-Frame Image](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-copying-individual-frames-from-a-multiple-frame-image-use)

[Creating and Saving a Multiple-Frame Image](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-and-saving-a-multiple-frame-image-use)

[EncoderParameter](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85))

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetFrameCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getframecount)

[Image::GetFrameDimensionsCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getframedimensionscount)

[Image::SaveAdd Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-saveadd(inimage_inconstencoderparameters))