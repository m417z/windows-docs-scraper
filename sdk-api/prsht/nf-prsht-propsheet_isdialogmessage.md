# PropSheet_IsDialogMessage macro

## Syntax

```cpp
BOOL PropSheet_IsDialogMessage(
   HWND  hDlg,
   LPMSG pMsg
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the macro has been processed, or **FALSE** if the macro has not been processed.

## Description

Passes a message to a property sheet dialog box and indicates whether the dialog box processed the message. You can use this macro or send the [PSM_ISDIALOGMESSAGE](https://learn.microsoft.com/windows/desktop/Controls/psm-isdialogmessage) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `pMsg`

Type: **LPMSG**

Pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that contains the message to be checked.

## Remarks

Your message loop should use the **PropSheet_IsDialogMessage** macro with modeless property sheets to pass messages to the property sheet dialog box. On systems that support Unicode, use the Unicode versions of the [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) and [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) functions (**GetMessageW** and **PeekMessageW**) to retrieve messages.

If the return value indicates that the message was processed, it must not be passed to the [TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage) or [DispatchMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dispatchmessage) function.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).

## See also

[PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta)