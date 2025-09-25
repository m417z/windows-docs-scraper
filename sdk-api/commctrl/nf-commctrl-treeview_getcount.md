# TreeView_GetCount macro

## Syntax

```cpp
UINT TreeView_GetCount(
   HWND hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the count of items.

## Description

Retrieves a count of the items in a tree-view control. You can use this macro or send the [TVM_GETCOUNT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getcount) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## Remarks

The node count returned by **TreeView_GetCount** is limited to integer values. If you add a node beyond 32767 the macro returns a negative value. After adding 65536 nodes the count returns to zero. When this occurs, the tree-view control appears empty with no scrollbars. For more information see the Knowledge Base article [Q182231](https://support.microsoft.com/default.aspx?scid=kb;en-us;Q182231).