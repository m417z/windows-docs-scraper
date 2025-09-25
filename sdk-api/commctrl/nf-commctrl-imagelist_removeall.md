# ImageList_RemoveAll macro

## Syntax

```cpp
BOOL ImageList_RemoveAll(
   HIMAGELIST himl
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Calls the [ImageList_Remove](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_remove) function to remove all of the images from an image list.

## Parameters

### `himl`

Type: **HIMAGELIST**

A handle to the image list.