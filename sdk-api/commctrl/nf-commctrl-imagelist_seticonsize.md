# ImageList_SetIconSize function

## Description

Sets the dimensions of images in an image list and removes all images from the list.

## Parameters

### `himl`

Type: **HIMAGELIST**

A handle to the image list.

### `cx`

Type: **int**

The width, in pixels, of the images in the image list. All images in an image list have the same dimensions.

### `cy`

Type: **int**

The height, in pixels, of the images in the image list. All images in an image list have the same dimensions.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.