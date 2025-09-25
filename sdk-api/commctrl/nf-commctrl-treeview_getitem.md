# TreeView_GetItem macro

## Syntax

```cpp
BOOL TreeView_GetItem(
   HWND     hwnd,
   LPTVITEM pitem
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Retrieves some or all of a tree-view item's attributes. You can use this macro or send the [TVM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `pitem`

Type: **LPTVITEM**

Pointer to a [TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema) structure that specifies the information to retrieve and receives information about the item. With [version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and later, you can use a [TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa) structure instead.

## Remarks

When the [TVM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitem) message is sent, the
**hItem** member of the [TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema) or [TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa) structure identifies the item to retrieve information about, and the **mask** member specifies the attributes to retrieve.

If the TVIF_TEXT flag is set in the
**mask** member of the [TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema) or [TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa) structure, the **pszText** member must point to a valid buffer and the **cchTextMax** member must be set to the number of characters in that buffer. The returned text will not necessarily be stored in the original buffer passed by the application. It is possible that **pszText** will point to text in a new buffer rather than place it in the old buffer.