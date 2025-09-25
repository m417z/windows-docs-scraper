# ListBox_SetSel macro

## Syntax

```cpp
int ListBox_SetSel(
   HWND hwndCtl,
   BOOL fSelect,
   int  index
);
```

## Return value

Type: **int**

If an error occurs, the return value is LB_ERR.

## Description

Selects or deselects an item in a multiple-selection list box. You can use this macro or send the [LB_SETSEL](https://learn.microsoft.com/windows/desktop/Controls/lb-setsel) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `fSelect`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to select the item, or **FALSE** to deselect it.

### `index`

Type: **int**

The zero-based index of the item.