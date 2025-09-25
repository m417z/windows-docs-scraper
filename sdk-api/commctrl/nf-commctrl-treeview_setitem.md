# TreeView_SetItem macro

## Syntax

```cpp
BOOL TreeView_SetItem(
   HWND     hwnd,
   LPTVITEM pitem
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a nonzero value if successful, or zero otherwise.

## Description

The **TreeView_SetItem** macro sets some or all of a tree-view item's attributes. You can use this macro or send the [TVM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-setitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `pitem`

Type: **LPTVITEM**

Pointer to a [TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema) structure that contains the new item attributes. With [version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and later, you can instead use a [TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa) structure.

## Remarks

The **hItem** member of the [TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema) or [TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa) structure identifies the item, and the **mask** member specifies which attributes to set.

## See also

[TreeView_GetItem](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getitem)