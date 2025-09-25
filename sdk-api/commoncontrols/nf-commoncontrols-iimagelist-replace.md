# IImageList::Replace

## Description

Replaces an image in an image list with a new image.

## Parameters

### `i` [in]

Type: **int**

A value of type **int** that contains the index of the image to replace.

### `hbmImage` [in]

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains the image.

### `hbmMask` [in, optional]

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains the mask. If no mask is used with the image list, this parameter is ignored.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IImageList::Replace** copies the bitmap to an internal data structure. You must use [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) to delete *hbmImage* and *hbmMask* after the method returns.

To use **IImageList::Replace**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).