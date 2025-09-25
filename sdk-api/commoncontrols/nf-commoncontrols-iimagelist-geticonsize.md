# IImageList::GetIconSize

## Description

Gets the dimensions of images in an image list. All images in an image list have the same dimensions.

## Parameters

### `cx` [out]

Type: **int***

A pointer to an **int** that receives the width, in pixels, of each image.

### `cy` [out]

Type: **int***

A pointer to an **int** that receives the height, in pixels, of each image.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::GetIconSize**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).