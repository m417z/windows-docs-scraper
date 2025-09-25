# IImageList::ImageListSetStrip

## Description

The **IImageList::ImageListSetStrip** method enables a user to add a strip of icons to the image list using a pair of bitmaps (large and small icons), starting at a location identified by nStartLoc.

## Parameters

### `pBMapSm` [in]

Win32 HBITMAP handle to the small (16x16) icon image strip. The snap-in owns this resource and must free it when finished. A resource memory leak will occur if the snap-in does not free BMapSm.

### `pBMapLg` [in]

Win32 HBITMAP handle to the large (32x32) icon image strip. The snap-in owns this resource and must free it when finished. A resource memory leak will occur if the snap-in does not free BMapLg.

### `nStartLoc` [in]

A value that specifies the index assigned to the first image in the strip. This is a virtual index that is internally mapped to the actual index.

### `cMask` [in]

A value that specifies the color used to generate a mask.

## Return value

This method can return one of these values.

## Remarks

Both small and large bitmaps must be provided and the number of icons in each strip must be equal. The small bitmap must be 16 pixels high and 16*n pixels wide, where n is an integer value. The large bitmap must be 32 pixels high and 32*n pixels wide.

Each pixel of the color used to generate a mask in the specified bitmap is changed to black and the corresponding bit in the mask is set to one.

## See also

[IImageList](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iimagelist)