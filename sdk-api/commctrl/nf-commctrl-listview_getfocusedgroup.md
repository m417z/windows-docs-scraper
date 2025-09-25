# ListView_GetFocusedGroup macro

## Syntax

```cpp
INT ListView_GetFocusedGroup(
  [in] HWND hwnd
);
```

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the index of the group with state of LVGS_FOCUSED, or -1 if there is no group with state of LVGS_FOCUSED.

## Description

Gets the group that has the focus. Use this macro or send the [LVM_GETFOCUSEDGROUP](https://learn.microsoft.com/windows/desktop/Controls/lvm-getfocusedgroup) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.