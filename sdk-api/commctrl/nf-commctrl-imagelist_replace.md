# ImageList_Replace function

## Description

Replaces an image in an image list with a new image.

## Parameters

### `himl`

Type: **HIMAGELIST**

A handle to the image list.

### `i`

Type: **int**

An index of the image to replace.

### `hbmImage`

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains the image.

### `hbmMask`

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains the mask. If no mask is used with the image list, this parameter is ignored.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

The **ImageList_Replace** function copies the bitmap to an internal data structure. Be sure to use the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete *hbmImage* and *hbmMask* after the function returns.