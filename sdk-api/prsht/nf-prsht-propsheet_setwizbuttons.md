# PropSheet_SetWizButtons macro

## Syntax

```cpp
VOID PropSheet_SetWizButtons(
   HWND  hDlg,
   DWORD dwFlags
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Enables or disables the Back, Next, and Finish buttons in a wizard by posting a [PSM_SETWIZBUTTONS](https://learn.microsoft.com/windows/desktop/Controls/psm-setwizbuttons) message. You can use this macro or send the **PSM_SETWIZBUTTONS** message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that specifies which wizard buttons are enabled. You can combine one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **PSWIZB_BACK** | Enable the Back button. If this flag is not set, the Back button is displayed as disabled. |
| **PSWIZB_DISABLEDFINISH** | Display a disabled Finish button. |
| **PSWIZB_FINISH** | Display an enabled Finish button. |
| **PSWIZB_NEXT** | Enable the Next button. If this flag is not set, the Next button is displayed as disabled. |

## Remarks

This macro uses [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) to send the [PSM_SETWIZBUTTONS](https://learn.microsoft.com/windows/desktop/Controls/psm-setwizbuttons) message. If your notification handler calls **PropSheet_SetWizButtons**, do nothing that will affect window focus until after the handler returns. For example, if you call [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) immediately after calling **PropSheet_SetWizButtons**, the message box will receive focus. Since messages sent with **PostMessage** are not delivered until they reach the head of the message queue, the **PSM_SETWIZBUTTONS** message will not be delivered until after the wizard has lost focus to the message box. As a result, the property sheet will not be able to properly set the focus for the buttons.

Wizards display either three or four buttons below each page. This message is used to specify which buttons are enabled. Wizards normally display Back, Cancel, and either a Next or Finish button. You typically enable only the Next button for the welcome page, Next and Back for interior pages, and Back and Finish for the completion page. The Cancel button is always enabled. Normally, setting PSWIZB_FINISH or PSWIZB_DISABLEDFINISH replaces the Next button with a Finish button. To display Next and Finish buttons simultaneously, set the PSH_WIZARDHASFINISH FLAG in the **dwFlags** member of the wizard's [PROPSHEETHEADER](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2) structure when you create the wizard. Every page will then display all four buttons.