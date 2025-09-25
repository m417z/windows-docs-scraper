# ListView_InsertColumn macro

## Syntax

```cpp
int ListView_InsertColumn(
         HWND       hwnd,
         int        iCol,
   const LPLVCOLUMN pcol
);
```

## Return value

Type: **int**

Returns the index of the new column if successful, or -1 otherwise.

## Description

Inserts a new column in a list-view control. You can use this macro or send the [LVM_INSERTCOLUMN](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertcolumn) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iCol`

Type: **int**

The index of the new column.

### `pcol`

Type: **const LPLVCOLUMN**

A pointer to an [LVCOLUMN](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvcolumna) structure that contains the attributes of the new column.

## Remarks

Columns are visible only in report (details) view.