# IPrintDialogCallback::HandleMessage

## Description

Called by [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) to give your application an opportunity to handle messages sent to the child dialog box in the lower portion of the **General** page of the [Print Property Sheet](https://learn.microsoft.com/windows/desktop/dlgbox/print-property-sheet). The child dialog box contains controls similar to those of the **Print** dialog box.

## Parameters

### `hDlg`

Type: **HWND**

A handle to the child dialog box in the lower portion of the **General** page.

### `uMsg`

Type: **UINT**

The identifier of the message being received.

### `wParam`

Type: **WPARAM**

Additional information about the message. The exact meaning depends on the value of the *uMsg* parameter.

### `lParam`

Type: **LPARAM**

Additional information about the message. The exact meaning depends on the value of the *uMsg* parameter.

If the *uMsg* parameter indicates the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message, *lParam* is a pointer to a [PRINTDLGEX](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-printdlgexa) structure containing the values specified when the property sheet was created.

### `pResult`

Type: **LRESULT***

Indicates the result to be returned by the dialog box procedure for the message. The value pointed to should be **TRUE** if you process the message, otherwise it should be **FALSE** or whatever is an appropriate value according to the message type.

## Return value

Type: **HRESULT**

Return **S_OK** if your **IPrintDialogCallback::HandleMessage** implementation handled the message. In this case, the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function does not perform any default message handling.

Return **S_FALSE** if you want [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) to perform its default message handling.

## Remarks

For notification messages passed by the [WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify) message, you must use the [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga) function with the **DWL_MSGRESULT** value to set a return value. When you call **SetWindowLong**, use [GetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getparent)(*hDlg*) to set the **DWL_MSGRESULT** value of the **General** page, which is the parent of the child window.

The default dialog box procedure for the child window in the lower portion of the **General** page processes the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message before passing it to the **HandleMessage** method. For all other messages sent to the child window, **HandleMessage** receives the message first. Then the **HandleMessage** return value determines whether the default dialog procedure processes the message or ignores it.

If **HandleMessage** processes the [WM_CTLCOLORDLG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-ctlcolordlg) message, it must return a valid brush handle to painting the background of the dialog box. In general, if **HandleMessage** processes any **WM_CTLCOLOR*** message, it must return a valid brush handle to painting the background of the specified control.

Do not call the [EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog) function from the **HandleMessage** method. Instead, **HandleMessage** can call the [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) function to post a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message with the IDABORT value to the dialog box procedure. Posting **IDABORT** closes the [Print Property Sheet](https://learn.microsoft.com/windows/desktop/dlgbox/print-property-sheet) and causes [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) to return **PD_RESULT_CANCEL** in the **dwResultAction** member of the [PRINTDLGEX](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-printdlgexa) structure. If you need to know why **HandleMessage** closed the dialog box, you must provide your own communication mechanism between the **HandleMessage** method and your application.

You can subclass the standard controls of the child dialog box in the lower portion of the **General** page. These standard controls are similar to those found in the **Print** dialog box. However, the default dialog box procedure may also subclass the controls. Because of this, you should subclass controls when **HandleMessage** processes the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message. This ensures that your subclass procedure receives control-specific messages before the subclass procedure set by the dialog box procedure.

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog)

[IPrintDialogCallback](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogcallback)

**Other Resources**

[PRINTDLGEX](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-printdlgexa)

[PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea)

[PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85))

**Reference**

[SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga)

[WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command)

[WM_CTLCOLORDLG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-ctlcolordlg)

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)

[WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify)