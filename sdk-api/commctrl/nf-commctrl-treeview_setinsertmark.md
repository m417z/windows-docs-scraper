# TreeView_SetInsertMark macro

## Syntax

```cpp
BOOL TreeView_SetInsertMark(
   HWND      hwnd,
   HTREEITEM hItem,
   BOOL      fAfter
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Sets the insertion mark in a tree-view control. You can use this macro or send the [TVM_SETINSERTMARK](https://learn.microsoft.com/windows/desktop/Controls/tvm-setinsertmark) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

### `hItem`

Type: **HTREEITEM**

**HTREEITEM** that specifies at which item the insertion mark will be placed. If this argument is **NULL**, the insertion mark is removed.

### `fAfter`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**BOOL** value that specifies if the insertion mark is placed before or after the specified item. If this argument is nonzero, the insertion mark will be placed after the item. If this argument is zero, the insertion mark will be placed before the item.