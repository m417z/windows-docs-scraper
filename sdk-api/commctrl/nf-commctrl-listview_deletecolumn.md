# ListView_DeleteColumn macro

## Syntax

```cpp
BOOL ListView_DeleteColumn(
   HWND hwnd,
   int  iCol
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Removes a column from a list-view control. You can use this macro or send the [LVM_DELETECOLUMN](https://learn.microsoft.com/windows/desktop/Controls/lvm-deletecolumn) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iCol`

Type: **int**

An index of the column to delete.

## Remarks

Deleting column zero of a list-view control is supported only in ComCtl32.dll version 6 and later. Version 5 also supports deleting column zero, but only after you use [CCM_SETVERSION](https://learn.microsoft.com/windows/desktop/Controls/ccm-setversion) to set the version to 5 or later. In versions prior to version 5, if you must delete column zero, insert a zero length dummy column zero and delete column one and above.