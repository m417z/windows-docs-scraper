# ImageList_GetIconSize function

## Description

Retrieves the dimensions of images in an image list. All images in an image list have the same dimensions.

## Parameters

### `himl`

Type: **HIMAGELIST**

A handle to the image list.

### `cx`

Type: **int***

A pointer to an integer variable that receives the width, in pixels, of each image.

### `cy`

Type: **int***

A pointer to an integer variable that receives the height, in pixels, of each image.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.