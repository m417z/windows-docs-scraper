# PropSheet_AddPage macro

## Syntax

```cpp
BOOL PropSheet_AddPage(
   HWND           hDlg,
   HPROPSHEETPAGE hpage
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Adds a new page to the end of an existing property sheet. You can use this macro or send the [PSM_ADDPAGE](https://learn.microsoft.com/windows/desktop/Controls/psm-addpage) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `hpage`

Type: **HPROPSHEETPAGE**

Handle to the page to add. The page must have been created by a previous call to the [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea) function.

## Remarks

The new page should be no larger than the largest page currently in the property sheet because the property sheet is not resized to fit the new page.

A number of messages and one function call occur while the property sheet is manipulating the list of pages. While this action is taking place, attempting to modify the list of pages will have unpredictable results. Accordingly, you should not use the **PropSheet_AddPage** macro in your implementation of [PropSheetPageProc](https://learn.microsoft.com/windows/desktop/api/prsht/nc-prsht-lpfnpspcallbacka) or while handling the following notifications and Microsoft Windows messages:

* [PSN_APPLY](https://learn.microsoft.com/windows/desktop/Controls/psn-apply)
* [PSN_KILLACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-killactive)
* [PSN_RESET](https://learn.microsoft.com/windows/desktop/Controls/psn-reset)
* [PSN_SETACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-setactive)
* [WM_DESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-destroy)
* [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)

If you need to modify a property sheet page while you are handling one of these messages or while [PropSheetPageProc](https://learn.microsoft.com/windows/desktop/api/prsht/nc-prsht-lpfnpspcallbacka) is in operation, post yourself a private Windows message. Your application will not receive that message until after the property sheet manager has finished its tasks. Then you can modify the list of pages.