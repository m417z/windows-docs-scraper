# TreeView_GetVisibleCount macro

## Syntax

```cpp
UINT TreeView_GetVisibleCount(
   HWND hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the number of items that can be fully visible in the client window of the tree-view control.

## Description

Obtains the number of items that can be fully visible in the client window of a tree-view control. You can use this macro or send the [TVM_GETVISIBLECOUNT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getvisiblecount) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## Remarks

The number of items that can be fully visible may be greater than the number of items in the control. The control calculates this value by dividing the height of the client window by the height of an item.

Note that the return value is the number of items that can be
*fully* visible. If you can see all of 20 items and part of one more item, the return value is 20.