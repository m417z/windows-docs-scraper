# TreeView_GetImageList macro

## Syntax

```cpp
HIMAGELIST TreeView_GetImageList(
   HWND hwnd,
   INT  iImage
);
```

## Return value

Type: **HIMAGELIST**

Returns an HIMAGELIST handle to the specified image list.

## Description

Retrieves the handle to the normal or state image list associated with a tree-view control. You can use this macro or send the [TVM_GETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/tvm-getimagelist) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `iImage`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Type of image list to retrieve. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **TVSIL_NORMAL** | Indicates the normal image list, which contains selected, nonselected, and overlay images for the items of a tree-view control. |
| **TVSIL_STATE** | Indicates the state image list. You can use state images to indicate application-defined item states. A state image is displayed to the left of an item's selected or nonselected image. |

## See also

[TreeView_SetImageList](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_setimagelist)