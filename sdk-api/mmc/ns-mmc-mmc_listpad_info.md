# MMC_LISTPAD_INFO structure

## Description

The
**MMC_LISTPAD_INFO** structure is introduced in MMC 1.1.

The
**MMC_LISTPAD_INFO** structure is filled in by the
[IExtendTaskPad::GetListPadInfo](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-getlistpadinfo) method to specify the following information for a list view taskpad:

* Title text for the list control
* Text for an optional button
* The command ID passed to
  [IExtendTaskPad::TaskNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-tasknotify) when that button is clicked.

## Members

### `szTitle`

A pointer to a null-terminated string that contains the text placed directly above the list control. This text can be the label for the objects within the list control (such as "Printers" if the list contains printers) or instructions (such as "Select a printer and click an action to perform.").

If **szTitle** is **NULL** or empty, no title is displayed for the list control.

Be aware that the **szTitle** member is not the same as the *pszTitle* parameter for
[IExtendTaskPad::GetTitle](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-gettitle). The **IExtendTaskPad::GetTitle** method returns the title for the entire taskpad that appears at the top of the taskpad and appears on every standard MMC taskpad. The **szTitle** member of
**MMC_LISTPAD_INFO** is the label for the list control and appears only on MMC list view taskpads.

### `szButtonText`

A pointer to a null-terminated string that contains the text placed on a button that is directly above the list control and to the right of the **szTitle** text.

When the user clicks this button on the taskpad, MMC calls the
[IExtendTaskPad::TaskNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-tasknotify) method of the snap-in and passes the value specified in **nCommandID** as a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure in the arg parameter. The **VARIANT** passed to
**TaskNotify** has a **vt** member set to **VT_I4** and an **lVal** member that contains the command ID.

To make the button to appear with no text, set **szButtonText** to an empty string.

To hide this button to appear on the taskpad, set **szButtonText** to **NULL**.

### `nCommandID`

Value that serves as an identifier for the button specified by **szButtonText**. It is recommended that you make this value unique to each taskpad to help identify the taskpad that sent the button-click notification.

When the user clicks this button, MMC calls the [IExtendTaskPad::TaskNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-tasknotify) method of the snap-in and passes this value as a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) in the arg parameter.

This value is ignored if **szButtonText** is **NULL**.

## Remarks

Allocate the **szTitle** and **szButtonText** strings with the COM API function [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) (or the equivalent) and MMC will release it.

## See also

[IExtendTaskPad::GetListPadInfo](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-getlistpadinfo)

[IExtendTaskPad::TaskNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-tasknotify)