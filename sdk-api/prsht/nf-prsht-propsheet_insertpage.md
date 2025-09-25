# PropSheet_InsertPage macro

## Syntax

```cpp
BOOL PropSheet_InsertPage(
   HWND hDlg,
   HWND index,
   HWND hpage
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a nonzero value if the page was successfully inserted, or zero otherwise.

## Description

Inserts a new page into an existing property sheet. The page can be inserted either at a specified index or after a specified page. You can use this macro or send the [PSM_INSERTPAGE](https://learn.microsoft.com/windows/desktop/Controls/psm-insertpage) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `index`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Where the page is to be inserted. Set *index* to **NULL** to make the new page the first page. To specify where the new page is to be inserted, you can either pass an index or an existing page's HPROPSHEETPAGE handle.

| Value | Meaning |
| --- | --- |
| **index** | If *index* is less than MAXUSHORT (the largest unsigned short integer), it specifies the zero-based index for the new page. For example, to make the inserted page the third page on the property sheet, set *index* to 2. To make it the first page, set *index* to 0. If *index* has a value greater than the number of pages and less than MAXUSHORT, the page will be appended. |
| **hpageInsertAfter** | If you set *index* to an existing page's HPROPSHEETPAGE handle, the new page will be inserted after it. |

### `hpage`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the page to be inserted. The page must first be created by a call to the [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea) function.

## Remarks

The pages after the insertion point are shifted to the right to accommodate the new page.

The property sheet is not resized to fit the new page. Do not make the new page larger than the property sheet's largest page.

A number of messages and one function call occur while the property sheet is manipulating the list of pages. While this action is taking place, attempting to modify the list of pages will have unpredictable results. Accordingly, you should not use the **PropSheet_InsertPage** macro in your implementation of [PropSheetPageProc](https://learn.microsoft.com/windows/desktop/api/prsht/nc-prsht-lpfnpspcallbacka) or while handling the following notifications and Windows messages.

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

You can add or remove pages in response to these notifications, provided that you return (via DWL_MSGRESULT) a nonzero value to specify the desired new page. Note, however, that if you insert a page that is located before the current page (that has a smaller index than the current page), [PSN_KILLACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-killactive) might be sent to the wrong page.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).