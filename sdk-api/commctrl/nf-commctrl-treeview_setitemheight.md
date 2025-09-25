# TreeView_SetItemHeight macro

## Syntax

```cpp
int TreeView_SetItemHeight(
   HWND  hwnd,
   SHORT iHeight
);
```

## Return value

Type: **int**

Returns the previous height of the items, in pixels.

## Description

Sets the height of the tree-view items. You can use this macro or send the [TVM_SETITEMHEIGHT](https://learn.microsoft.com/windows/desktop/Controls/tvm-setitemheight) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

### `iHeight`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New height of every item in the tree view, in pixels. Heights less than 1 will be set to 1. If this argument is not even, it will be rounded down to the nearest even value. If this argument is -1, the control will revert to using its default item height.

## Remarks

The tree-view control uses this value for the height of all items. To modify the height of individual items, see the description of the **iIntegral** member of the [TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa) structure.

## See also

[TreeView_GetItemHeight](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getitemheight)