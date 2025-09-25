# TreeView_GetToolTips macro

## Syntax

```cpp
HWND TreeView_GetToolTips(
   HWND hwnd
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the child tooltip control, or **NULL** if the control is not using tooltips.

## Description

Retrieves the handle to the child tooltip control used by a tree-view control. You can use this macro or send the [TVM_GETTOOLTIPS](https://learn.microsoft.com/windows/desktop/Controls/tvm-gettooltips) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

## Remarks

When created, tree-view controls automatically create a child tooltip control. To prevent a tree-view control from using tooltips, create the control with the [TVS_NOTOOLTIPS](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) style.

## See also

[TreeView_SetToolTips](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_settooltips)