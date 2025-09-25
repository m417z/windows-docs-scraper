# ListView_EnsureVisible macro

## Syntax

```cpp
BOOL ListView_EnsureVisible(
   HWND hwndLV,
   int  i,
   BOOL fPartialOK
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Ensures that a list-view item is either entirely or partially visible, scrolling the list-view control if necessary. You can use this macro or send the [LVM_ENSUREVISIBLE](https://learn.microsoft.com/windows/desktop/Controls/lvm-ensurevisible) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The index of the list-view item.

### `fPartialOK`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value specifying whether the item must be entirely visible. If this parameter is **TRUE**, no scrolling occurs if the item is at least partially visible.