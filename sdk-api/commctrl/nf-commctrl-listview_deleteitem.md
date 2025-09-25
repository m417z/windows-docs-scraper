# ListView_DeleteItem macro

## Syntax

```cpp
BOOL ListView_DeleteItem(
   HWND hwnd,
   int  i
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Removes an item from a list-view control. You can use this macro or send the [LVM_DELETEITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-deleteitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

An index of the list-view item to delete.