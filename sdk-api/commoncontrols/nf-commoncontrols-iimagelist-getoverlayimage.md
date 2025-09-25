# IImageList::GetOverlayImage

## Description

Retrieves a specified image from the list of images used as overlay masks.

## Parameters

### `iOverlay` [in]

Type: **int**

A value of type **int** that contains the one-based index of the overlay mask.

### `piIndex` [out]

Type: **int***

A pointer to an **int** that receives the zero-based index of
an image in the image list. This index identifies the image that is used as an overlay mask.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::GetOverlayImage**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).