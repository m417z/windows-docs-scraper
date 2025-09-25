# ImageList_ExtractIcon macro

## Syntax

```cpp
HICON ImageList_ExtractIcon(
   HINSTANCE  hi,
   HIMAGELIST himl,
   int        i
);
```

## Return value

Type: **[HICON](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle of the icon or cursor if successful, or **NULL** otherwise.

## Description

Calls the [ImageList_GetIcon](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_geticon) function to create an icon or cursor based on an image and mask in an image list.

## Parameters

### `hi`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This parameter is not used and should always be zero.

### `himl`

Type: **HIMAGELIST**

A handle to the image list.

### `i`

Type: **int**

The index of the image.

## Remarks

It is the responsibility of the calling application to destroy the icon returned from this function by using the [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) function.