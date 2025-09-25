# TreeView_GetItemPartRect macro

## Syntax

```cpp
BOOL TreeView_GetItemPartRect(
   HWND       hwnd,
   HTREEITEM  hitem,
   RECT       *prc,
   TVITEMPART *partid
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Retrieves the largest possible bounding rectangle that constitutes the "hit zone" for a specified part of an item. Use this macro or send the [TVM_GETITEMPARTRECT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitempartrect) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to the tree-view item.

### `prc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the bounding rectangle. The caller is responsible for allocating this structure. The coordinates received are relative to the upper-left corner of the tree-view control.

### `partid`

Type: **TVITEMPART***

ID of the item part. This value must be **TVGIPR_BUTTON** (0x0001).

## Remarks

This message returns the largest possible bounding rectangle such that for every (x,y) coordinate within the rectangle, a click by the user at that coordinate would constitute a hit on that part of the item.