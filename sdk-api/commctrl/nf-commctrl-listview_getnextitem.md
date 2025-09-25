# ListView_GetNextItem macro

## Syntax

```cpp
int ListView_GetNextItem(
   HWND hwnd,
   int  i,
   UINT flags
);
```

## Return value

Type: **int**

Returns the index of the next item if successful, or -1 otherwise.

## Description

Searches for a list-view item that has the specified properties and bears the specified relationship to a specified item. You can use this macro or send the [LVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-getnextitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The index of the item with which to begin the search, or -1 to find the first item that matches the specified flags. The specified item itself is excluded from the search.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The geometric relation of the requested item to the specified item and, if specified, the state of the requested item. For a list of possible values, see the description of the
*lParam* parameter in the [LVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-getnextitem) message. If an item does not have all of the specified state flags set, the search continues with the next item.