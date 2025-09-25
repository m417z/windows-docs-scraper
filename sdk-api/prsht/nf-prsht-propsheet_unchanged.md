# PropSheet_UnChanged macro

## Syntax

```cpp
VOID PropSheet_UnChanged(
   HWND hDlg,
   HWND hwnd
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Informs a property sheet that information in a page has reverted to the previously saved state. You can use this macro or send the [PSM_UNCHANGED](https://learn.microsoft.com/windows/desktop/Controls/psm-unchanged) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the page that has reverted to the previously saved state.

## Remarks

The property sheet disables the **Apply Now** button if no other pages have registered changes with the property sheet.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).