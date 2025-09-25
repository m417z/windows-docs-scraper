# ImageList_AddIcon macro

## Syntax

```cpp
int ImageList_AddIcon(
   HIMAGELIST himl,
   HICON      hicon
);
```

## Description

Adds an icon or cursor to an image list. **ImageList_AddIcon** calls the [ImageList_ReplaceIcon](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_replaceicon) function.

## Parameters

### `himl`

Type: **HIMAGELIST**

A handle to the image list. If this parameter identifies a masked image list, the macro copies both the image and mask bitmaps of the icon or cursor. If this parameter identifies a nonmasked image list, the macro copies only the image bitmap.

### `hicon`

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the icon or cursor that contains the bitmap and mask for the new image.

## Return value

Type: **int**

Returns the index of the image if successful, or -1 otherwise.

## Remarks

Because the system does not save
*hicon*, you can destroy it after the macro returns if the icon or cursor was created by the [CreateIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createicon) function. You do not need to destroy *hicon* if it was loaded by the [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona) function; the system automatically frees an icon resource when it is no longer needed.

The **ImageList_AddIcon** macro is defined as follows:

``` syntax
#define  ImageList_AddIcon(himl, hicon) ImageList_ReplaceIcon(himl, -1, hicon)
```