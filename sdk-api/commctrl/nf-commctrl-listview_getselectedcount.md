# ListView_GetSelectedCount macro

## Syntax

```cpp
UINT ListView_GetSelectedCount(
   HWND hwndLV
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the number of selected items.

## Description

Determines the number of selected items in a list-view control. You can use this macro or send the [LVM_GETSELECTEDCOUNT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getselectedcount) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.