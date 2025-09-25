## Description

Receives messages or notifications intended for the default dialog box procedure of the **Color** dialog box. This is an application-defined or library-defined callback function that is used with the [ChooseColor](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646912(v=vs.85)) function.

The **LPCCHOOKPROC** type defines a pointer to this callback function. *CCHookProc* is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

A handle to the **Color** dialog box for which the message is intended.

### `unnamedParam2`

The identifier of the message being received.

### `unnamedParam3`

Additional information about the message. The exact meaning depends on the value of the *unnamedParam2* parameter.

### `unnamedParam4`

Additional information about the message. The exact meaning depends on the value of the *unnamedParam2* parameter. If the *unnamedParam2* parameter indicates the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message, then *unnamedParam4* is a pointer to a [CHOOSECOLOR](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-choosecolora-r1) structure containing the values specified when the dialog was created.

## Return value

If the hook procedure returns zero, the default dialog box procedure processes the message.

If the hook procedure returns a nonzero value, the default dialog box procedure ignores the message.

## Remarks

When you use the [ChooseColor](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646912(v=vs.85)) function to create a **Color** dialog box, you can provide a *CCHookProc* hook procedure to process messages or notifications intended for the dialog box procedure. To enable the hook procedure, use the [CHOOSECOLOR](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-choosecolora-r1) structure that you passed to the dialog creation function. Specify the address of the hook procedure in the **lpfnHook** member and specify the **CC_ENABLEHOOK** flag in the **Flags** member.

The default dialog box procedure processes the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message before passing it to the hook procedure. For all other messages, the hook procedure receives the message first. Then, the return value of the hook procedure determines whether the default dialog procedure processes the message or ignores it.

If the hook procedure processes the [WM_CTLCOLORDLG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-ctlcolordlg) message, it must return a valid brush handle to painting the background of the dialog box. In general, if the hook procedure processes any **WM_CTLCOLOR*** message, it must return a valid brush handle to painting the background of the specified control.

Do not call the [EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog) function from the hook procedure. Instead, the hook procedure can call the [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) function to post a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message with the **IDABORT** value to the dialog box procedure. Posting **IDABORT** closes the dialog box and causes the dialog box function to return **FALSE**. If you need to know why the hook procedure closed the dialog box, you must provide your own communication mechanism between the hook procedure and your application.

You can subclass the standard controls of a common dialog box. However, the dialog box procedure may also subclass the controls. Because of this, you should subclass controls when your hook procedure processes the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message. This ensures that your subclass procedure receives the control-specific messages before the subclass procedure set by the dialog box procedure.

## See also

[CHOOSECOLOR](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-choosecolora-r1)

[ChooseColor](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646912(v=vs.85))

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog)

[PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea)

**Reference**

[WM_CTLCOLORDLG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-ctlcolordlg)

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)