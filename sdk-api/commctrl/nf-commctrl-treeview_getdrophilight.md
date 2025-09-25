# TreeView_GetDropHilight macro

## Syntax

```cpp
HTREEITEM TreeView_GetDropHilight(
   HWND hwnd
);
```

## Return value

Type: **HTREEITEM**

Returns the handle to the item if successful, or **NULL** otherwise.

## Description

Retrieves the tree-view item that is the target of a drag-and-drop operation. You can use this macro, or you can explicitly send the [TVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getnextitem) message with the TVGN_DROPHILITE flag.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.