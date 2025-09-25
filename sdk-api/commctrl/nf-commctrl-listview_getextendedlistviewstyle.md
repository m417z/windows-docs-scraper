# ListView_GetExtendedListViewStyle macro

## Syntax

```cpp
DWORD ListView_GetExtendedListViewStyle(
   HWND hwndLV
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **DWORD** value that represents the styles currently in use for a given list-view control. This can be a combination of extended styles.

## Description

Gets the extended styles that are currently in use for a given list-view control. You can use this macro or send the [LVM_GETEXTENDEDLISTVIEWSTYLE](https://learn.microsoft.com/windows/desktop/Controls/lvm-getextendedlistviewstyle) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.