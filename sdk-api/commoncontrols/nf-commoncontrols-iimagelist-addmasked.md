# IImageList::AddMasked

## Description

Adds an image or images to an image list, generating a mask from the specified bitmap.

## Parameters

### `hbmImage` [in]

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains one or more images. The number of images is inferred from the width of the bitmap.

### `crMask` [in]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The color used to generate the mask. Each pixel of this color in the specified bitmap is changed to black, and the corresponding bit in the mask is set to 1. If this parameter is CLR_DEFAULT, then the color of the pixel at (0,0) is used as the mask.

### `pi` [out]

Type: **int***

A pointer to an **int** that contains the index of the first new image when it returns, if successful, or -1 otherwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** The bitmap passed in *hbmImage* will be modified.

**IImageList::AddMasked** copies the bitmap to an internal data structure. Bitmaps with color depth greater than 8bpp are not supported. You must use the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete *hbmImage* and *crMask* after the method returns.

To use **IImageList::AddMasked**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).