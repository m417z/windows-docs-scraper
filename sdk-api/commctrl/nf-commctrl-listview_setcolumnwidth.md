# ListView_SetColumnWidth macro

## Syntax

```cpp
BOOL ListView_SetColumnWidth(
   HWND hwnd,
   int  iCol,
   int  cx
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Used to change the width of a column in report view or the width of all columns in list-view mode. You can use this macro or send the [LVM_SETCOLUMNWIDTH](https://learn.microsoft.com/windows/desktop/Controls/lvm-setcolumnwidth) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iCol`

Type: **int**

The zero-based index of a valid column. For list-view mode, this parameter must be set to zero.

### `cx`

Type: **int**

The new width of the column, in pixels. For report-view mode, the following special values are supported:

| Value | Meaning |
| --- | --- |
| **LVSCW_AUTOSIZE** | Automatically sizes the column. |
| **LVSCW_AUTOSIZE_USEHEADER** | Automatically sizes the column to fit the header text. If you use this value with the last column, its width is set to fill the remaining width of the list-view control. |

## Remarks

Assume that you have a 2-column list-view control with a width of 500 pixels. If the width of column zero is set to 200 pixels, and you make the following call.

`ListView_SetColumnWidth(hwnd, 1, LVSCW_AUTOSIZE_USEHEADER)`

The second (and last) column will be 300 pixels wide.

Note that **ListView_SetColumnWidth** converts the
*cx* parameter to a 16-bit value.