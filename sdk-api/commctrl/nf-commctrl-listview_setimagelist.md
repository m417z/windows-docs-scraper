# ListView_SetImageList macro

## Syntax

```cpp
HIMAGELIST ListView_SetImageList(
   HWND       hwnd,
   HIMAGELIST himl,
   int        iImageList
);
```

## Return value

Type: **HIMAGELIST**

Returns the handle to the image list previously associated with the control if successful, or **NULL** otherwise.

## Description

Assigns an image list to a list-view control. You can use this macro or send the [LVM_SETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/lvm-setimagelist) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `himl`

Type: **HIMAGELIST**

A handle to the image list to assign.

### `iImageList`

Type: **int**

The type of image list. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **LVSIL_NORMAL** | Image list with large icons. |
| **LVSIL_SMALL** | Image list with small icons. |
| **LVSIL_STATE** | Image list with state images. |
| **LVSIL_GROUPHEADER** | Image list for group header. |

## Remarks

The current image list will be destroyed when the list-view control is destroyed unless the [LVS_SHAREIMAGELISTS](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style is set. If you use this message to replace one image list with another, your application must explicitly destroy all image lists other than the current one.