# PropSheet_GetTabControl macro

## Syntax

```cpp
HWND PropSheet_GetTabControl(
   HWND hDlg
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the tab control.

## Description

Retrieves the handle to the tab control of a property sheet. You can use this macro or send the [PSM_GETTABCONTROL](https://learn.microsoft.com/windows/desktop/Controls/psm-gettabcontrol) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

## Remarks

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).