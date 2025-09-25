# ListView_GetImageList macro

## Syntax

```cpp
HIMAGELIST ListView_GetImageList(
   HWND hwnd,
   int  iImageList
);
```

## Return value

Type: **HIMAGELIST**

Returns the handle to the specified image list if successful, or **NULL** otherwise.

## Description

Gets the handle to an image list used for drawing list-view items. You can use this macro or send the [LVM_GETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/lvm-getimagelist) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iImageList`

Type: **int**

The image list to retrieve. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **LVSIL_NORMAL** | Image list with large icons. |
| **LVSIL_SMALL** | Image list with small icons. |
| **LVSIL_STATE** | Image list with state images. |
| **LVSIL_GROUPHEADER** | Image list for group header. |