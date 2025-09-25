# TreeView_GetLineColor macro

## Syntax

```cpp
COLORREF TreeView_GetLineColor(
   HWND hwnd
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the current line color, or the CLR_DEFAULT value if none has been specified.

## Description

Gets the current line color. You can also use the [TVM_GETLINECOLOR](https://learn.microsoft.com/windows/desktop/Controls/tvm-getlinecolor) message directly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## Remarks

This message only retrieves line colors. To retrieve the colors of the plus sign (+) and minus sign (-) inside the buttons, use the [TreeView_GetTextColor](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_gettextcolor) macro.

## See also

[TVM_GETLINECOLOR](https://learn.microsoft.com/windows/desktop/Controls/tvm-getlinecolor)