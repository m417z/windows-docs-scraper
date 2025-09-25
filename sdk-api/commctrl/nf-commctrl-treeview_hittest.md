# TreeView_HitTest macro

## Syntax

```cpp
HTREEITEM TreeView_HitTest(
   HWND            hwnd,
   LPTVHITTESTINFO lpht
);
```

## Return value

Type: **HTREEITEM**

Returns the handle to the tree-view item that occupies the specified point, or **NULL** if no item occupies the point.

## Description

Determines the location of the specified point relative to the client area of a tree-view control. You can use this macro or send the [TVM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/tvm-hittest) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `lpht`

Type: **LPTVHITTESTINFO**

Pointer to a [TVHITTESTINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvhittestinfo) structure. When the message is sent, the **pt** member specifies the coordinates of the point to test. When the message returns, the **hItem** member is the handle to the item at the specified point or **NULL** if no item occupies the point. Also, when the message returns, the **flags** member is a hit test value that indicates the location of the specified point. For a list of hit test values, see the description of the **TVHITTESTINFO** structure.