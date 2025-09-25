# ListView_SubItemHitTest macro

## Syntax

```cpp
INT ListView_SubItemHitTest(
   HWND            hwnd,
   LPLVHITTESTINFO plvhti
);
```

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the index of the item or subitem tested, if any, or -1 otherwise. If an item or subitem is at the given coordinates, the fields of the **LVHITTESTINFO** structure will be filled with the applicable hit information.

## Description

Determines which list-view item or subitem is located at a given position. You can use this macro or send the [LVM_SUBITEMHITTEST](https://learn.microsoft.com/windows/desktop/Controls/lvm-subitemhittest) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control that will be hit-tested.

### `plvhti`

Type: **LPLVHITTESTINFO**

A pointer to an [LVHITTESTINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvhittestinfo) structure. The [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure within **LVHITTESTINFO** must be set to the client coordinates to be hit-tested.