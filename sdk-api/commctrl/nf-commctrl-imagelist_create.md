# ImageList_Create function

## Description

Creates a new image list.

## Parameters

### `cx`

Type: **int**

The width, in pixels, of each image.

### `cy`

Type: **int**

The height, in pixels, of each image.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of bit flags that specify the type of image list to create. This parameter can be a combination of the [Image List Creation Flags](https://learn.microsoft.com/windows/desktop/Controls/ilc-constants).

### `cInitial`

Type: **int**

The number of images that the image list initially contains.

### `cGrow`

Type: **int**

The number of images by which the image list can grow when the system needs to make room for new images. This parameter represents the number of new images that the resized image list can contain.

## Return value

Type: **HIMAGELIST**

Returns the handle to the image list if successful, or **NULL** otherwise.

## Remarks

When you finish using the image list, destroy it by calling the [ImageList_Destroy](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_destroy) function.

**Note** Comctl32.dll version 6 is not redistributable but it is included in Windows or later. To use Comctl32.dll version 6, specify it in a manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).