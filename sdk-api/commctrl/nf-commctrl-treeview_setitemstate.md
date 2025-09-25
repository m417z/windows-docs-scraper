# TreeView_SetItemState macro

## Syntax

```cpp
UINT TreeView_SetItemState(
   HWND      hwndTV,
   HTREEITEM hti,
   UINT      data,
   UINT      _mask
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is not used.

## Description

Sets a tree-view item's state attributes. You can use this macro or send the [TVM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-setitem) message explicitly.

## Parameters

### `hwndTV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hti`

Type: **HTREEITEM**

Handle to the item.

### `data`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value that is equivalent to the **data** member of [TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa).

### `_mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask used to select the states to be set. It is equivalent to the **_mask** member of [TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa).