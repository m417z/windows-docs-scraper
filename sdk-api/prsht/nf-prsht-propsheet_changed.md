# PropSheet_Changed macro

## Syntax

```cpp
BOOL PropSheet_Changed(
   HWND hDlg,
   HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Informs a property sheet that information in a page has changed. You can use this macro or send the [PSM_CHANGED](https://learn.microsoft.com/windows/desktop/Controls/psm-changed) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the page that has changed.

## Remarks

The property sheet enables the **Apply** button.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).