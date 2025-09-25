# PropSheet_CancelToClose macro

## Syntax

```cpp
VOID PropSheet_CancelToClose(
   HWND hDlg
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Used when changes made since the most recent [PSN_APPLY](https://learn.microsoft.com/windows/desktop/Controls/psn-apply) notification cannot be canceled. You can also send a [PSM_CANCELTOCLOSE](https://learn.microsoft.com/windows/desktop/Controls/psm-canceltoclose) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

## Remarks

[PSM_CANCELTOCLOSE](https://learn.microsoft.com/windows/desktop/Controls/psm-canceltoclose) disables the **Cancel** button and changes the text of the **OK** button to "Close". You can use this macro or send the **PSM_CANCELTOCLOSE** message explicitly.

Most property sheets wait to perform irreversible changes until a [PSN_APPLY](https://learn.microsoft.com/windows/desktop/Controls/psn-apply) notification is received. However, in some circumstances, a property sheet may make irreversible changes outside the standard PSN_APPLY/[PSN_RESET](https://learn.microsoft.com/windows/desktop/Controls/psn-reset) sequence. One example is a property sheet that contains an **Edit** button that is used to display a subdialog box for editing a property. When the user clicks **OK** to submit the change, the property sheet page has several options:

* It can record the changes but wait until it receives a [PSN_APPLY](https://learn.microsoft.com/windows/desktop/Controls/psn-apply) notification to apply them. This is the preferred approach.
* It can apply the changes immediately after exiting the subdialog box, but remember the original settings. Those settings can be used to restore the original state if a [PSN_RESET](https://learn.microsoft.com/windows/desktop/Controls/psn-reset) notification is received.
* It can apply the changes immediately and not attempt to restore the original settings when it receives a [PSN_RESET](https://learn.microsoft.com/windows/desktop/Controls/psn-reset) notification. This approach is not recommended, but may be necessary if the changes are too far-reaching for the other two options to be practical.

For the third option, applications should send a [PSM_CANCELTOCLOSE](https://learn.microsoft.com/windows/desktop/Controls/psm-canceltoclose) message to the property sheet. It indicates to the user that the changes made with the subdialog box cannot be reversed by clicking the **Cancel** button.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).