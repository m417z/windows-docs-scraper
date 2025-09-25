# ComboBox_GetExtendedUI macro

## Syntax

```cpp
UINT ComboBox_GetExtendedUI(
   HWND hwndCtl
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Zero if the control is using the default UI, or nonzero if it is using the extended UI.

## Description

Ascertains whether a combo box is using the default user interface (UI) or the extended UI. You can use this macro or send the [CB_GETEXTENDEDUI](https://learn.microsoft.com/windows/desktop/Controls/cb-getextendedui) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [CB_GETEXTENDEDUI](https://learn.microsoft.com/windows/desktop/Controls/cb-getextendedui).