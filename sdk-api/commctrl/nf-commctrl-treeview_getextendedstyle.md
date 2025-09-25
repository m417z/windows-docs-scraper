# TreeView_GetExtendedStyle macro

## Syntax

```cpp
DWORD TreeView_GetExtendedStyle(
   HWND hwnd
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the value of extended style. For more information on styles, see [Tree-View Control Extended Styles](https://learn.microsoft.com/windows/win32/controls/tree-view-control-window-extended-styles).

## Description

Retrieves the extended style for a specified tree-view control. Use this macro or send the [TVM_GETEXTENDEDSTYLE](https://learn.microsoft.com/windows/desktop/Controls/tvm-getextendedstyle) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## Remarks

The extended styles for a tree-view control have nothing to do with the extended styles used with function [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) or function [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga).