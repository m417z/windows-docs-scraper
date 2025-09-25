# IToolbar::AddBitmap

## Description

The **IToolbar::AddBitmap** method enables a snap-in to add an image to the toolbar.

## Parameters

### `nImages` [in]

An index of images that are available. A value that specifies the number of images in the bitmap being passed in hbmp.

### `hbmp` [in]

A handle to the bitmap to be added to the toolbar.

**Note** The snap-in owns this resource and must free it. A memory leak will occur if the snap-in does not free hbmp.

### `cxSize` [in]

The height, in pixels, of the bitmap to be added. (In version 1.0, MMC only supported a cxSize of 16.)

### `cySize` [in]

The width, in pixels, of the bitmap to be added. (In version 1.0, MMC only supported a cySize of 16.)

### `crMask` [in]

The color used to generate a mask to overlay the images on the toolbar buttons.

## Return value

This method can return one of these values.

## See also

[IToolbar](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-itoolbar)