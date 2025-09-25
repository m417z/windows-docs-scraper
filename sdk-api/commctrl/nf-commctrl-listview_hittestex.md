# ListView_HitTestEx macro

## Syntax

```cpp
int ListView_HitTestEx(
   HWND            hwndLV,
   LPLVHITTESTINFO pinfo
);
```

## Return value

Type: **int**

Returns the index of the item at the specified position, if any, or -1 otherwise.

## Description

Determines which list-view item, if any, is at a specified position. You can use this macro or send the [LVM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/lvm-hittest) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `pinfo`

Type: **LPLVHITTESTINFO**

A pointer to an [LVHITTESTINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvhittestinfo) structure that contains the position to hit test and receives information about the results of the hit test.

## Remarks

This macro passes -1 as the *wParam* of the message, specifying that the **iGroup** and **iSubItem** members of *pinfo* are retrieved.