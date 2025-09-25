# IImageList::GetImageCount

## Description

Gets the number of images in an image list.

## Parameters

### `pi` [out]

Type: **int***

A pointer to an **int** that contains the number of images when the method returns.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::GetImageCount**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).