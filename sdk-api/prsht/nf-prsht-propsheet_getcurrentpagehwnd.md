# PropSheet_GetCurrentPageHwnd macro

## Syntax

```cpp
HWND PropSheet_GetCurrentPageHwnd(
   HWND hDlg
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a handle to the window of the current property sheet page.

## Description

Retrieves a handle to the window of the current page of a property sheet. You can use this macro or send the [PSM_GETCURRENTPAGEHWND](https://learn.microsoft.com/windows/desktop/Controls/psm-getcurrentpagehwnd) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

## Remarks

Use the **PropSheet_GetCurrentPageHwnd** macro with modeless property sheets to determine when to destroy the dialog box. When the user clicks the **OK** or **Cancel** button, **PropSheet_GetCurrentPageHwnd** returns **NULL**, and you can then use the [DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow) function to destroy the dialog box.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).

## See also

[PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta)