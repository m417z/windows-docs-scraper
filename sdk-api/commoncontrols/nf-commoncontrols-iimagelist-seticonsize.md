# IImageList::SetIconSize

## Description

Sets the dimensions of images in an image list and removes all images from the list.

## Parameters

### `cx` [in]

Type: **int**

A value of type **int** that contains the width, in pixels, of the images in the image list. All images in an image list have the same dimensions.

### `cy` [in]

Type: **int**

A value of type **int** that contains the height, in pixels, of the images in the image list. All images in an image list have the same dimensions.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::SetIconSize**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).