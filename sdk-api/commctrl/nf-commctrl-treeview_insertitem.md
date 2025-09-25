# TreeView_InsertItem macro

## Syntax

```cpp
HTREEITEM TreeView_InsertItem(
   HWND             hwnd,
   LPTVINSERTSTRUCT lpis
);
```

## Return value

Type: **HTREEITEM**

Returns the **HTREEITEM** handle to the new item if successful, or **NULL** otherwise.

## Description

Inserts a new item in a tree-view control. You can use this macro or send the [TVM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-insertitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `lpis`

Type: **LPTVINSERTSTRUCT**

Pointer to a [TVINSERTSTRUCT](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvinsertstructa) structure that specifies the attributes of the tree-view item.

## See also

[TVN_ENDLABELEDIT](https://learn.microsoft.com/windows/desktop/Controls/tvn-endlabeledit)