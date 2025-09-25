# ComboBox_SetExtendedUI macro

## Syntax

```cpp
int ComboBox_SetExtendedUI(
   HWND hwndCtl,
   UINT flags
);
```

## Return value

Type: **int**

If an error occurs, the return value is CB_ERR.

## Description

Selects either the default user interface (UI) or the extended UI for a combo box that has the [CBS_DROPDOWN](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles) or [CBS_DROPDOWNLIST](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles) style. You can use this macro or send the [CB_SETEXTENDEDUI](https://learn.microsoft.com/windows/desktop/Controls/cb-setextendedui) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero to use the default UI, or nonzero to use the extended UI.

## Remarks

For more information, see [CB_SETEXTENDEDUI](https://learn.microsoft.com/windows/desktop/Controls/cb-setextendedui).