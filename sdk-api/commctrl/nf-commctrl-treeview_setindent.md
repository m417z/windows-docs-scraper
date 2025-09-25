# TreeView_SetIndent macro

## Syntax

```cpp
BOOL TreeView_SetIndent(
   HWND hwnd,
   INT  indent
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Although this macro is typed as a BOOL, it always returns zero.

## Description

Sets the width of indentation for a tree-view control and redraws the control to reflect the new width. You can use this macro or send the [TVM_SETINDENT](https://learn.microsoft.com/windows/desktop/Controls/tvm-setindent) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `indent`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Width, in pixels, of the indentation. If this parameter is less than the system-defined minimum width, the new width is set to the system-defined minimum.

## Remarks

The system-defined minimum indent value is typically five pixels, but it is not fixed. To retrieve the exact value of the minimum indent on a particular system, use the **TreeView_SetIndent** macro with *indent* set to zero. Then use the [TreeView_GetIndent](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getindent) macro to retrieve the minimum indent value.

## See also

[TVM_SETINDENT](https://learn.microsoft.com/windows/desktop/Controls/tvm-setindent)