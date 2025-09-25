# PropSheet_RemovePage macro

## Syntax

```cpp
VOID PropSheet_RemovePage(
   HWND           hDlg,
   int            index,
   HPROPSHEETPAGE hpage
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Removes a page from a property sheet. You can use this macro or send the [PSM_REMOVEPAGE](https://learn.microsoft.com/windows/desktop/Controls/psm-removepage) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `index`

Type: **int**

Zero-based index of the page to be removed.

### `hpage`

Type: **HPROPSHEETPAGE**

Handle to the page to be removed.

## Remarks

An application can specify the page to be removed by assigning a value to either *index* or *hpage*. If values are assigned to both *index* and *hpage*, *hpage* takes precedence.

A number of messages and one function call occur while the property sheet is manipulating the list of pages. While this action is taking place, attempting to modify the list of pages will have unpredictable results. Accordingly, you should not use the **PropSheet_RemovePage** macro in your implementation of [PropSheetPageProc](https://learn.microsoft.com/windows/desktop/api/prsht/nc-prsht-lpfnpspcallbacka) or while handling the following notifications and Windows messages.

* [PSN_APPLY](https://learn.microsoft.com/windows/desktop/Controls/psn-apply)
* [PSN_KILLACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-killactive)
* [PSN_RESET](https://learn.microsoft.com/windows/desktop/Controls/psn-reset)
* [PSN_SETACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-setactive)
* [WM_DESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-destroy)
* [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)

If you need to modify a property sheet page while you are handling one of these messages or while [PropSheetPageProc](https://learn.microsoft.com/windows/desktop/api/prsht/nc-prsht-lpfnpspcallbacka) is in operation, post yourself a private Windows message. Your application will not receive that message until after the property sheet manager has finished its tasks. Then you can modify the list of pages.

The following notifications are also affected by property sheet modification.

* [PSN_WIZBACK](https://learn.microsoft.com/windows/desktop/Controls/psn-wizback)
* [PSN_WIZNEXT](https://learn.microsoft.com/windows/desktop/Controls/psn-wiznext)

You can add or remove pages in response to these notifications, provided that you return (via DWL_MSGRESULT) a nonzero value to specify the desired new page. Note, however, that if you remove a page that is located before the current page (that has a smaller index than the current page), [PSN_KILLACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-killactive) might be sent to the wrong page.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).