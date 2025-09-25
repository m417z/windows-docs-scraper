# ListView_SetHotItem macro

## Syntax

```cpp
INT ListView_SetHotItem(
   HWND hwnd,
   INT  i
);
```

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the index of the item that was previously hot.

## Description

Sets the hot item in a list-view control. You can use this macro or send the [LVM_SETHOTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-sethotitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `i`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index of the item to be set as the hot item.