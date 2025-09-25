# TreeView_SetCheckState macro

## Syntax

```cpp
UINT TreeView_SetCheckState(
   HWND      hwndTV,
   HTREEITEM hti,
   BOOL      fCheck
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is not used.

## Description

Sets the item's state image to "checked" or "unchecked." You can also use the [TVM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-setitem) message directly.

## Parameters

### `hwndTV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hti`

Type: **HTREEITEM**

Handle to the item.

### `fCheck`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value that indicates which state image is displayed. Set
*fCheck* to **TRUE** to display the checked state image or **FALSE** to display the unchecked image.

## Remarks

A tree-view control can have two image lists. The normal image list stores the selected, nonselected, and overlay images. Check boxes are stored in the state image list and displayed to the left of the corresponding normal image. State images are specified by a one-based index. An index of zero indicates that there is no state image. See [Tree-View Image Lists](https://learn.microsoft.com/windows/desktop/Controls/tree-view-controls) for a discussion of how to handle tree-view images.

If you want to define your own state images, this macro assumes that the checked and unchecked images have the same indexes as the standard image list: 1 for unchecked and 2 for checked.