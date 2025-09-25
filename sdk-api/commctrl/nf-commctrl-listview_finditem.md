# ListView_FindItem macro

## Syntax

```cpp
int ListView_FindItem(
         HWND         hwnd,
         int          iStart,
   const LPLVFINDINFO plvfi
);
```

## Return value

Type: **int**

Returns the index of the item if successful, or -1 otherwise.

## Description

Searches for a list-view item with the specified characteristics. You can use this macro or send the [LVM_FINDITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-finditem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iStart`

Type: **int**

The index of the item after which to begin the search, or -1 to start from the beginning.

### `plvfi`

Type: **const LPLVFINDINFO**

A pointer to an [LVFINDINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvfindinfoa) structure that contains information about what to search for.