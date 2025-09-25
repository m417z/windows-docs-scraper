# TreeView_SortChildrenCB macro

## Syntax

```cpp
BOOL TreeView_SortChildrenCB(
   HWND       hwnd,
   LPTVSORTCB psort,
   BOOL       recurse
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sorts tree-view items using an application-defined callback function that compares the items. You can use this macro or send the [TVM_SORTCHILDRENCB](https://learn.microsoft.com/windows/desktop/Controls/tvm-sortchildrencb) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `psort`

Type: **LPTVSORTCB**

Pointer to a [TVSORTCB](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvsortcb) structure. The **lpfnCompare** member is the address of the application-defined callback function, which is called during the sort operation each time the relative order of two list items needs to be compared. For more information about the callback function, see the description of **TVSORTCB**.

### `recurse`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved. Must be zero.