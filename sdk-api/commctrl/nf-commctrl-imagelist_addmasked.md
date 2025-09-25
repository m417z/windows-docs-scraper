# ImageList_AddMasked function

## Description

Adds an image or images to an image list, generating a mask from the specified bitmap.

## Parameters

### `himl`

Type: **HIMAGELIST**

A handle to the image list.

### `hbmImage`

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the bitmap that contains one or more images. The number of images is inferred from the width of the bitmap.

### `crMask`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The color used to generate the mask. Each pixel of this color in the specified bitmap is changed to black, and the corresponding bit in the mask is set to 1. If this parameter is CLR_DEFAULT, then the color of the pixel at (0,0) is used as the mask.

## Return value

Type: **int**

Returns the index of the first new image if successful, or -1 otherwise.

## Remarks

The **ImageList_AddMasked** function copies the bitmap to an internal data structure. Bitmaps with color depth greater than 8bpp are not supported. Be sure to use the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete *hbmImage* after the function returns.