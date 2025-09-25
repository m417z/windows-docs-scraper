# ListView_GetHoverTime macro

## Syntax

```cpp
DWORD ListView_GetHoverTime(
   HWND hwndLV
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the amount of time, in milliseconds, that the mouse cursor must hover over an item before it is selected. If the return value is (**DWORD**)-1, then the hover time is the default hover time.

## Description

Gets the amount of time that the mouse cursor must hover over an item before it is selected. You can use this macro or send the [LVM_GETHOVERTIME](https://learn.microsoft.com/windows/desktop/Controls/lvm-gethovertime) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

## Remarks

The hover time only affects list-view controls that have the [LVS_EX_TRACKSELECT](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles), [LVS_EX_ONECLICKACTIVATE](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles), or [LVS_EX_TWOCLICKACTIVATE](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles) extended list-view style.