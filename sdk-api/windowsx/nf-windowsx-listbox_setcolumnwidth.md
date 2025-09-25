# ListBox_SetColumnWidth macro

## Syntax

```cpp
void ListBox_SetColumnWidth(
   HWND hwndCtl,
   int  cxColumn
);
```

## Description

Sets the width of all columns in a multiple-column list box. You can use this macro or send the [LB_SETCOLUMNWIDTH](https://learn.microsoft.com/windows/desktop/Controls/lb-setcolumnwidth) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `cxColumn`

Type: **int**

The width, in pixels, of all columns.