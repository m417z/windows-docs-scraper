# ListView_GetItemPosition macro

## Syntax

```cpp
BOOL ListView_GetItemPosition(
   HWND  hwndLV,
   int   i,
   POINT *ppt
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets the position of a list-view item. You can use this macro or explicitly send the [LVM_GETITEMPOSITION](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitemposition) message.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The index of the list-view item.

### `ppt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the position of the item's upper-left corner, in view coordinates.