# ListView_SetColumn macro

## Syntax

```cpp
BOOL ListView_SetColumn(
   HWND       hwnd,
   int        iCol,
   LPLVCOLUMN pcol
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets the attributes of a list-view column. You can use this macro or send the [LVM_SETCOLUMN](https://learn.microsoft.com/windows/desktop/Controls/lvm-setcolumn) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iCol`

Type: **int**

The index of the column.

### `pcol`

Type: **LPLVCOLUMN**

A pointer to an [LVCOLUMN](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvcolumna) structure that contains the new column attributes. The **mask** member specifies which column attributes to set. If the **mask** member specifies the LVCF_TEXT value, the **pszText** member is the address of a null-terminated string and the **cchTextMax** member is ignored.