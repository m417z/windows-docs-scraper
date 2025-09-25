# ImageList_GetIcon function

## Description

Creates an icon from an image and mask in an image list.

## Parameters

### `himl`

Type: **HIMAGELIST**

A handle to the image list.

### `i`

Type: **int**

An index of the image.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of flags that specify the drawing style. For a list of values, see the description of the *fStyle* parameter of the [ImageList_Draw](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_draw) function.

## Return value

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the handle to the icon if successful, or **NULL** otherwise.

## Remarks

It is the responsibility of the calling application to destroy the icon returned from this function using the [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) function.