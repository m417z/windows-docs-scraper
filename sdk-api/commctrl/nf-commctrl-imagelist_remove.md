# ImageList_Remove function

## Description

Removes an image from an image list.

## Parameters

### `himl`

Type: **HIMAGELIST**

A handle to the image list.

### `i`

Type: **int**

The index of the image to remove. If this parameter is -1, the function removes all images.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

When an image is removed, the indexes of the remaining images are adjusted so that the image indexes always range from zero to one less than the number of images in the image list. For example, if you remove the image at index 0, then image 1 becomes image 0, image 2 becomes image 1, and so on.

## See also

[ImageList_RemoveAll](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_removeall)