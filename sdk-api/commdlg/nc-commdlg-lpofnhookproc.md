## Description

[Starting with Windows Vista, the **Open** and **Save As** common dialog boxes have been superseded by the [Common Item Dialog](https://learn.microsoft.com/windows/win32/shell/common-file-dialog). We recommended that you use the Common Item Dialog API instead of these dialog boxes from the Common Dialog Box Library.]

Receives notification messages sent from the dialog box. The function also receives messages for any additional controls that you defined by specifying a child dialog template. The *OFNHookProc* hook procedure is an application-defined or library-defined callback function that is used with the Explorer-style **Open** and **Save As** dialog boxes.

The **LPOFNHOOKPROC** type defines a pointer to this callback function. *OFNHookProc* is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

A handle to the child dialog box of the **Open** or **Save As** dialog box. Use the [GetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getparent) function to get the handle to the **Open** or **Save As** dialog box.

### `unnamedParam2`

The identifier of the message being received.

### `unnamedParam3`

Additional information about the message. The exact meaning depends on the value of the *unnamedParam2* parameter.

### `unnamedParam4`

Additional information about the message. The exact meaning depends on the value of the *unnamedParam2* parameter. If the *unnamedParam2* parameter indicates the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message, *unnamedParam4* is a pointer to an [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure containing the values specified when the dialog box was created.

## Return value

If the hook procedure returns zero, the default dialog box procedure processes the message.

If the hook procedure returns a nonzero value, the default dialog box procedure ignores the message.

For the [CDN_SHAREVIOLATION](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-shareviolation) and [CDN_FILEOK](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-fileok) notification messages, the hook procedure should return a nonzero value to indicate that it has used the [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga) function to set a nonzero **DWL_MSGRESULT** value.

## Remarks

If you do not specify the **OFN_EXPLORER** flag when you create an **Open** or **Save As** dialog box, and you want a hook procedure, you must use an old-style [OFNHookProcOldStyle](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646932(v=vs.85)) hook procedure. In this case, the dialog box will have the old-style user interface.

When you use the [GetOpenFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getopenfilenamea) or [GetSaveFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getsavefilenamea) functions to create an Explorer-style **Open** or **Save As** dialog box, you can provide an *OFNHookProc* hook procedure. To enable the hook procedure, use the [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure that you passed to the dialog creation function. Specify the pointer to the hook procedure in the **lpfnHook** member and specify the **OFN_ENABLEHOOK** flag in the **Flags** member.

If you provide a hook procedure for an Explorer-style common dialog box, the system creates a dialog box that is a child of the default dialog box. The hook procedure acts as the dialog procedure for the child dialog. This child dialog is based on the template you specified in the [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure, or it is a default child dialog if no template is specified. The child dialog is created when the default dialog procedure is processing its [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message. After the child dialog processes its own **WM_INITDIALOG** message, the default dialog procedure moves the standard controls, if necessary, to make room for any additional controls of the child dialog. The system then sends the [CDN_INITDONE](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-initdone) notification message to the hook procedure.

The hook procedure does not receive messages intended for the standard controls of the default dialog box. You can subclass the standard controls, but this is discouraged because it may make your application incompatible with later versions. However, the Explorer-style common dialog boxes provide a set of messages that the hook procedure can use to monitor and control the dialog. These include a set of notification messages sent from the dialog, as well as messages that you can send to retrieve information from the dialog. For a complete list of these messages, see [Explorer-Style Hook Procedures](https://learn.microsoft.com/windows/desktop/dlgbox/open-and-save-as-dialog-boxes).

If the hook procedure processes the [WM_CTLCOLORDLG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-ctlcolordlg) message, it must return a valid brush handle to painting the background of the dialog box. In general, if it processes any **WM_CTLCOLOR*** message, it must return a valid brush handle to painting the background of the specified control.

Do not call the [EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog) function from the hook procedure. Instead, the hook procedure can call the [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) function to post a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message with the **IDCANCEL** value to the dialog box procedure. Posting **IDCANCEL** closes the dialog box and causes the dialog box function to return **FALSE**. If you need to know why the hook procedure closed the dialog box, you must provide your own communication mechanism between the hook procedure and your application.

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[GetOpenFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getopenfilenamea)

[GetSaveFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getsavefilenamea)

[OFNHookProcOldStyle](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646932(v=vs.85))

[OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea)

**Reference**