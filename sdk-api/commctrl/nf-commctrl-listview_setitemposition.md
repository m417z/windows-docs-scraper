# ListView_SetItemPosition macro

## Syntax

```cpp
BOOL ListView_SetItemPosition(
   HWND hwndLV,
   int  i,
   int  x,
   int  y
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Moves an item to a specified position in a list-view control (in icon or small icon view). You can use this macro or send the [LVM_SETITEMPOSITION](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitemposition) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The index of the list-view item.

### `x`

Type: **int**

The new x-position of the item's upper-left corner, in view coordinates.

### `y`

Type: **int**

The new y-position of the item's upper-left corner, in view coordinates.

## Remarks

If the list-view control has the [LVS_AUTOARRANGE](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style, the list-view control is arranged after the position of the item is set.

On Windows Vista, calling this macro on a list-view control with the [LVS_AUTOARRANGE](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style does nothing, and the return value is **FALSE**.