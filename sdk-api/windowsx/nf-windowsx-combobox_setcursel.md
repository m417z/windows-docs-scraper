# ComboBox_SetCurSel macro

## Syntax

```cpp
int ComboBox_SetCurSel(
   HWND hwndCtl,
   int  index
);
```

## Return value

Type: **int**

If an error occurs, the return value is CB_ERR. If the *index* parameter is –1, the return value is CB_ERR even though no error occurred.

## Description

Sets the currently selected item in a combo box. You can use this macro or send the [CB_SETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/cb-setcursel) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item to select, or –1 to clear the selection.