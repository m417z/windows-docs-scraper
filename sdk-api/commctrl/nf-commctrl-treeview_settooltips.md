# TreeView_SetToolTips macro

## Syntax

```cpp
HWND TreeView_SetToolTips(
   HWND hwnd,
   HWND hwndTT
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to tooltip control previously set for the tree-view control, or **NULL** if tooltips were not previously used.

## Description

Sets a tree-view control's child tooltip control. You can use this macro or send the [TVM_SETTOOLTIPS](https://learn.microsoft.com/windows/desktop/Controls/tvm-settooltips) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

### `hwndTT`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tooltip control.

## Remarks

When created, tree-view controls automatically create a child tooltip control. To prevent a tree-view control from using tooltips, create the control with the [TVS_NOTOOLTIPS](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) style.

## See also

[TreeView_GetToolTips](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_gettooltips)