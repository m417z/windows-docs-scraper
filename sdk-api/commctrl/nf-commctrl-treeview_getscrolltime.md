# TreeView_GetScrollTime macro

## Syntax

```cpp
UINT TreeView_GetScrollTime(
   HWND hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the maximum scroll time, in milliseconds.

## Description

Retrieves the maximum scroll time for the tree-view control. You can use this macro or send the [TVM_GETSCROLLTIME](https://learn.microsoft.com/windows/desktop/Controls/tvm-getscrolltime) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## Remarks

The maximum scroll time is the longest amount of time that a scroll operation can take. Scrolling will be adjusted so that the scroll will take place within the maximum scroll time. A scroll operation may take less time than the maximum.

## See also

[TreeView_SetScrollTime](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_setscrolltime)