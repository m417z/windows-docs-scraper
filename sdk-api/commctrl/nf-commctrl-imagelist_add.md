# ImageList_Add function

## Description

Adds an image or images to an image list.

## Parameters

### `himl` [in]

Type: **HIMAGELIST**

A handle to the image list.

### `hbmImage` [in]

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains the image or images. The number of images is inferred from the width of the bitmap.

### `hbmMask` [in, optional]

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains the mask. If no mask is used with the image list, this parameter is ignored. This parameter can be **NULL**.

## Return value

Type: **int**

Returns the index of the first new image if successful, or -1 otherwise.

## Remarks

The **ImageList_Add** function copies the bitmap to an internal data structure. Be sure to use the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete
*hbmImage* and
*hbmMask* after the function returns.