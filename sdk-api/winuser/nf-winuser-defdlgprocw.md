# DefDlgProcW function

## Description

Calls the default dialog box window procedure to provide default processing for any window messages that a dialog box with a private window class does not process.

## Parameters

### `hDlg` [in]

Type: **HWND**

A handle to the dialog box.

### `Msg` [in]

Type: **UINT**

The message.

### `wParam` [in]

Type: **WPARAM**

Additional message-specific information.

### `lParam` [in]

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **LRESULT**

The return value specifies the result of the message processing and depends on the message sent.

## Remarks

The **DefDlgProc** function is the window procedure for the predefined class of dialog box. This procedure provides internal processing for the dialog box by forwarding messages to the dialog box procedure and carrying out default processing for any messages that the dialog box procedure returns as **FALSE**. Applications that create custom window procedures for their custom dialog boxes often use **DefDlgProc** instead of the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function to carry out default message processing.

Applications create custom dialog box classes by filling a [WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa) structure with appropriate information and registering the class with the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) function. Some applications fill the structure by using the [GetClassInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoa) function, specifying the name of the predefined dialog box. In such cases, the applications modify at least the **lpszClassName** member before registering. In all cases, the **cbWndExtra** member of **WNDCLASS** for a custom dialog box class must be set to at least **DLGWINDOWEXTRA**.

The **DefDlgProc** function must not be called by a dialog box procedure; doing so results in recursive execution.

## See also

**Conceptual**

[DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca)

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[GetClassInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoa)

**Reference**

[RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)

[WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa)