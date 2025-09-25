# PropSheet_Apply macro

## Syntax

```cpp
BOOL PropSheet_Apply(
   HWND hDlg
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if all pages successfully applied the changes, or **FALSE** otherwise.

## Description

Simulates the selection of the **Apply** button, indicating that one or more pages have changed and the changes need to be validated and recorded. You can use this macro or send the [PSM_APPLY](https://learn.microsoft.com/windows/desktop/Controls/psm-apply) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

## Remarks

The property sheet sends the [PSN_KILLACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-killactive) notification code to the current page. If the current page returns **FALSE**, the property sheet sends the [PSN_APPLY](https://learn.microsoft.com/windows/desktop/Controls/psn-apply) notification code to all active pages.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).