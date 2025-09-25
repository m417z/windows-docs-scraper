# ListView_GetItemSpacing macro

## Syntax

```cpp
DWORD ListView_GetItemSpacing(
   HWND hwndLV,
   BOOL fSmall
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the amount of spacing between items. The horizontal spacing is contained in the **LOWORD** and the vertical spacing is contained in the **HIWORD**.

## Description

Determines the spacing between items in a list-view control. You can use this macro or send the [LVM_GETITEMSPACING](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitemspacing) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `fSmall`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A view for which to retrieve the item spacing. This parameter is **TRUE** for small icon view, or **FALSE** for icon view.