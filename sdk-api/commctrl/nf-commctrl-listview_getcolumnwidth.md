# ListView_GetColumnWidth macro

## Syntax

```cpp
int ListView_GetColumnWidth(
   HWND hwnd,
   int  iCol
);
```

## Return value

Type: **int**

Returns the column width if successful, or zero otherwise. If this macro is used on a list-view control with the **LVS_REPORT** style and the specified column does not exist, the return value is undefined.

## Description

Gets the width of a column in report or list view. You can use this macro or send the [LVM_GETCOLUMNWIDTH](https://learn.microsoft.com/windows/desktop/Controls/lvm-getcolumnwidth) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iCol`

Type: **int**

The index of the column. This parameter is ignored in list view.