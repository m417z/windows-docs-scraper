# ISnapinAbout::GetStaticFolderImage

## Description

The **ISnapinAbout::GetStaticFolderImage** method allows the console to obtain the static folder images for the scope and result panes.

## Parameters

### `hSmallImage` [out]

A pointer to the handle to a small icon (16x16 pixels) in either the scope or result view pane.

### `hSmallImageOpen` [out]

A pointer to the handle to a small open-folder icon (16x16 pixels).

### `hLargeImage` [out]

A pointer to the handle to a large icon (32x32 pixels).

### `cMask` [out]

A pointer to a
COLORREF structure that specifies the color used to generate a mask.

## Return value

This method can return one of these values.

## Remarks

MMC creates copies of the returned bitmaps. The snap-in can free the originals when the
ISnapinAbout interface is released.

MMC uses default static folder images and icons if it cannot obtain the snap-in icons.

## See also

[ISnapinAbout](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-isnapinabout)