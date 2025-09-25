# ImageList_SetImageCount function

## Description

Resizes an existing image list.

## Parameters

### `himl` [in]

Type: **HIMAGELIST**

A handle to the image list that will be resized.

### `uNewCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value specifying the new size of the image list.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

If an application expands an image list with this function, it must add new images by using the [ImageList_Replace](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_replace) function. If your application does not add valid images at the new indexes, draw operations that use the new indexes will be unpredictable.

If you decrease the size of an image list by using this function, the truncated images are freed.