# ListView_SetItemPosition32 macro

## Syntax

```cpp
void ListView_SetItemPosition32(
   HWND hwndLV,
   int  i,
   int  x0,
   int  y0
);
```

## Description

Moves an item to a specified position in a list-view control (in icon or small icon view). This macro differs from the [ListView_SetItemPosition](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setitemposition) macro in that it uses 32-bit coordinates. You can use the **ListView_SetItemPosition32** macro or send the [LVM_SETITEMPOSITION32](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitemposition32) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The index of the list-view item for which to set the position.

### `x0`

Type: **int**

New horizontal coordinates of the item.

### `y0`

Type: **int**

New vertical coordinates of the item.

## See also

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)