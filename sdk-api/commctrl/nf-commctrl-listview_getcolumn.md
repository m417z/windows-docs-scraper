# ListView_GetColumn macro

## Syntax

```cpp
BOOL ListView_GetColumn(
   HWND       hwnd,
   int        iCol,
   LPLVCOLUMN pcol
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets the attributes of a list-view control's column. You can use this macro or send the [LVM_GETCOLUMN](https://learn.microsoft.com/windows/desktop/Controls/lvm-getcolumn) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iCol`

Type: **int**

The index of the column.

### `pcol`

Type: **LPLVCOLUMN**

A pointer to an [LVCOLUMN](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvcolumna) structure that specifies the information to retrieve and receives information about the column. The
**mask** member specifies which column attributes to retrieve. If the **mask** member specifies the LVCF_TEXT value, the **pszText** member must contain the address of the buffer that receives the item text, and the **cchTextMax** member must specify the size of the buffer.