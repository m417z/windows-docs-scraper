# TreeView_SetImageList macro

## Syntax

```cpp
HIMAGELIST TreeView_SetImageList(
   HWND       hwnd,
   HIMAGELIST himl,
   INT        iImage
);
```

## Return value

Type: **HIMAGELIST**

Returns the HIMAGELIST handle to the previous image list, if any, or **NULL** otherwise.

## Description

Sets the normal or state image list for a tree-view control and redraws the control using the new images. You can use this macro or send the [TVM_SETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/tvm-setimagelist) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `himl`

Type: **HIMAGELIST**

The HIMAGELIST handle to the image list. If *himl* is **NULL**, the message removes the specified image list from the tree-view control.

### `iImage`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Type of image list to set. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **TVSIL_NORMAL** | Indicates the normal image list, which contains selected, nonselected, and overlay images for the items of a tree-view control. |
| **TVSIL_STATE** | Indicates the state image list. You can use state images to indicate application-defined item states. A state image is displayed to the left of an item's selected or nonselected image. |

## Remarks

The tree-view control will not destroy the image list specified with this message. Your application must destroy the image list when it is no longer needed.

## See also

**Reference**

[TVM_GETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/tvm-getimagelist)

[TreeView_GetImageList](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getimagelist)