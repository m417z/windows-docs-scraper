## Description

Represents image metadata, including dimensions and format. This structure is populated by a search filter and returned from its implementation of [IPixelFilter::GetImageInfo](https://learn.microsoft.com/windows/win32/api/filter/nf-filter-ipixelfilter-getimageinfo).

## Members

### `Width`

The width of the image being indexed, in pixels.

### `Height`

The height of the image being indexed, in pixels.

### `Format`

A member of the [IMAGE_PIXELFORMAT](https://learn.microsoft.com/windows/win32/api/filter/ne-filter-image_pixelformat) enumeration, specifying the format of the image being indexed.

## Remarks

## See also