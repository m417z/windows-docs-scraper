# ImageList_SetBkColor function

## Description

Sets the background color for an image list. This function only works if you add an icon or use [ImageList_AddMasked](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_addmasked) with a black and white bitmap. Without a mask, the entire image is drawn; hence the background color is not visible.

## Parameters

### `himl` [in]

Type: **HIMAGELIST**

A handle to the image list.

### `clrBk` [in]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The background color to set. This parameter can be the CLR_NONE value; in that case, images are drawn transparently using the mask.

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the previous background color if successful, or CLR_NONE otherwise.