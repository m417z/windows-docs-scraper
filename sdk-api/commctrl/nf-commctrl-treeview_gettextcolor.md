# TreeView_GetTextColor macro

## Syntax

```cpp
COLORREF TreeView_GetTextColor(
   HWND hwnd
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **COLORREF** value that represents the current text color. If this value is -1, the control is using the system color for the text color.

## Description

Retrieves the current text color of the control. You can use this macro or send the [TVM_GETTEXTCOLOR](https://learn.microsoft.com/windows/desktop/Controls/tvm-gettextcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

## See also

[TreeView_SetTextColor](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_settextcolor)