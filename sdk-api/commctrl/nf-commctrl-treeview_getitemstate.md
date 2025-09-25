# TreeView_GetItemState macro

## Syntax

```cpp
UINT TreeView_GetItemState(
   HWND      hwndTV,
   HTREEITEM hti,
   UINT      mask
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **UINT** value that is equivalent to the state member of **TVITEMEX**. The state bits that are both true and were specified in **mask** will be set.

## Description

Retrieves some or all of a tree-view item's state attributes. You can use this macro or send the [TVM_GETITEMSTATE](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitemstate) message explicitly.

## Parameters

### `hwndTV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hti`

Type: **HTREEITEM**

Handle to the item.

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask used to specify the states to query for. It is equivalent to the **mask** member of [TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa).