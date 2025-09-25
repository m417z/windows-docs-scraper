# IImageList::Remove

## Description

Removes an image from an image list.

## Parameters

### `i` [in]

Type: **int**

A value of type **int** that contains the index of the image to remove. If this parameter is -1, the method removes all images.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When an image is removed, the indexes of the remaining images adjust so that they always range from zero to one less than the number of images in the image list. For example, if you remove the image at index 0, then image 1 becomes image 0, image 2 becomes image 1, and so on.

To use **IImageList::Remove**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).