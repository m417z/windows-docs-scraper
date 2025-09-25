# ListBox_SetCurSel macro

## Syntax

```cpp
int ListBox_SetCurSel(
   HWND hwndCtl,
   int  index
);
```

## Return value

Type: **int**

If an error occurs, the return value is LB_ERR. If the *index* parameter is –1, the return value is LB_ERR even though no error occurred.

## Description

Sets the currently selected item in a single-selection list box. You can use this macro or send the [LB_SETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/lb-setcursel) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item to select, or –1 to clear the selection.

## Remarks

For more information, see [LB_SETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/lb-setcursel).