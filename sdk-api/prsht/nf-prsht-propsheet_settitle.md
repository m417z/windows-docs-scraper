# PropSheet_SetTitle macro

## Syntax

```cpp
VOID PropSheet_SetTitle(
   HWND   hDlg,
   DWORD  wStyle,
   LPTSTR lpszText
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Sets the title of a property sheet. You can use this macro or send the [PSM_SETTITLE](https://learn.microsoft.com/windows/desktop/Controls/psm-settitle) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `wStyle`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag that indicates whether to include the prefix "Properties for" with the specified title string. If *wStyle* is the PSH_PROPTITLE value, the prefix is included. Otherwise, the prefix is not used.

### `lpszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a buffer that contains the title string. If the [HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85)) of this parameter is **NULL**, the property sheet loads the string resource specified in the [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)).

## Remarks

In an Aero Wizard, this macro can be used to change the title of an interior page dynamically; for example, when handling the [PSN_SETACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-setactive) notification.