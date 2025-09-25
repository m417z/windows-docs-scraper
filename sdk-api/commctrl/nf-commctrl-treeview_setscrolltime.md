# TreeView_SetScrollTime macro

## Syntax

```cpp
UINT TreeView_SetScrollTime(
   HWND hwnd,
   UINT uTime
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the previous scroll time, in milliseconds.

## Description

Sets the maximum scroll time for the tree-view control. You can use this macro or send the [TVM_SETSCROLLTIME](https://learn.microsoft.com/windows/desktop/Controls/tvm-setscrolltime) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

### `uTime`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New maximum scroll time, in milliseconds. If this value is less than 100, it will be rounded up to 100.

## Remarks

The maximum scroll time is the longest amount of time that a scroll operation can take. Scrolling will be adjusted so that the scroll will take place within the maximum scroll time. A scroll operation may take less time than the maximum.

## See also

[TVM_GETSCROLLTIME](https://learn.microsoft.com/windows/desktop/Controls/tvm-getscrolltime)