# TabCtrl_SetItem macro

## Syntax

```cpp
BOOL TabCtrl_SetItem(
   HWND     hwnd,
   int      iItem,
   LPTCITEM pitem
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets some or all of a tab's attributes. You can use this macro or send the [TCM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-setitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `iItem`

Type: **int**

Index of the item.

### `pitem`

Type: **LPTCITEM**

Pointer to a [TCITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tcitema) structure that contains the new item attributes. The **mask** member specifies which attributes to set. If the **mask** member specifies the LVIF_TEXT value, the **pszText** member is the address of a null-terminated string and the **cchTextMax** member is ignored.