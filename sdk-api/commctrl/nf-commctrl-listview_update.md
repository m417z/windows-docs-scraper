# ListView_Update macro

## Syntax

```cpp
BOOL ListView_Update(
   HWND hwndLV,
   int  i
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Updates a list-view item. If the list-view control has the [LVS_AUTOARRANGE](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style, this macro causes the list-view control to be arranged. You can use this macro or send the [LVM_UPDATE](https://learn.microsoft.com/windows/desktop/Controls/lvm-update) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The index of the item to update.