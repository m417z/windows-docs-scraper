# Image::GetPhysicalDimension

## Description

The **Image::GetPhysicalDimension** method gets the width and height of this image.

## Parameters

### `size` [out]

Type: **[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef)***

Pointer to a
[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef) object that receives the width and height of this image.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Cropping and Scaling Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-cropping-and-scaling-images-about)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetBounds](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getbounds)

[Image::GetHeight](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getheight)

[Image::GetHorizontalResolution](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-gethorizontalresolution)

[Image::GetVerticalResolution](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getverticalresolution)

[Image::GetWidth](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getwidth)

[Improving Performance by Avoiding Automatic Scaling](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-improving-performance-by-avoiding-automatic-scaling-use)