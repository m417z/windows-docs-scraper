# PropSheet_SetCurSel macro

## Syntax

```cpp
BOOL PropSheet_SetCurSel(
   HWND           hDlg,
   HPROPSHEETPAGE hpage,
   UINT           index
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Activates the specified page in a property sheet. You can use this macro or send the [PSM_SETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/psm-setcursel) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `hpage`

Type: **HPROPSHEETPAGE**

Handle to the page to activate. An application can specify the index or the handle, or both. If both are specified, *hpage* takes precedence.

### `index`

Type: **UINT**

Zero-based index of the page. An application can specify the index or the handle, or both. If both are specified, *hpage* takes precedence.

## Remarks

The window that is losing the activation receives the [PSN_KILLACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-killactive) notification code, and the window that is gaining the activation receives the [PSN_SETACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-setactive) notification code.