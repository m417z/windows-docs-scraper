# ListView_GetItemCount macro

## Syntax

```cpp
int ListView_GetItemCount(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns the number of items.

## Description

Gets the number of items in a list-view control. You can use this macro or send the [LVM_GETITEMCOUNT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitemcount) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.