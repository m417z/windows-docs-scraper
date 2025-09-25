# IImageList::GetImageRect

## Description

Gets an image's bounding rectangle.

## Parameters

### `i` [in]

Type: **int**

A value of type **int** that contains the index of the image.

### `prc` [out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a  **RECT** that contains the bounding rectangle when the method returns.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::GetImageRect**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).