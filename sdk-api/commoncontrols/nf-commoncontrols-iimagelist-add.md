# IImageList::Add

## Description

Adds an image or images to an image list.

## Parameters

### `hbmImage` [in]

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains the image or images. The number of images is inferred from the width of the bitmap.

### `hbmMask` [in, optional]

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains the mask. If no mask is used with the image list, this parameter is ignored.

### `pi` [out]

Type: **int***

When this method returns, contains a pointer to the index of the first new image. If the method fails to successfully add the new image, this value is -1.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IImageList::Add** copies the bitmap to an internal data structure. You must use the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete *hbmImage* and *hbmMask* after the method returns.

To use **IImageList::Add**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).