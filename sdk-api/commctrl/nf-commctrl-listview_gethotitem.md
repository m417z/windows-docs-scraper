# ListView_GetHotItem macro

## Syntax

```cpp
INT ListView_GetHotItem(
   HWND hwnd
);
```

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the index of the item that is currently hot.

## Description

Gets the index of the hot item. You can use this macro or send the [LVM_GETHOTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-gethotitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.