# TreeView_GetItemRect macro

## Syntax

```cpp
BOOL TreeView_GetItemRect(
   HWND      hwnd,
   HTREEITEM hitem,
   LPRECT    prc,
   BOOL      code
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the item is visible and the bounding rectangle is successfully retrieved, the return value is **TRUE**. Otherwise, the **TVM_GETITEMRECT** message returns **FALSE** and does not retrieve the bounding rectangle.

## Description

Retrieves the bounding rectangle for a tree-view item and indicates whether the item is visible. You can use this macro or send the [TVM_GETITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitemrect) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to the tree-view item.

### `prc`

Type: **LPRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the bounding rectangle. The coordinates are relative to the upper-left corner of the tree-view control.

### `code`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specifying the portion of the item for which to retrieve the bounding rectangle. If this parameter is **TRUE**, the bounding rectangle includes only the text of the item. Otherwise, it includes the entire line that the item occupies in the tree-view control.