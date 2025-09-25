# PWLX_MESSAGE_BOX callback function

## Description

[The WlxMessageBox function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxMessageBox** function is called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to create, display, and operate a message box.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `hwndOwner` [in]

Specifies the owner window of the message box to be created. If this parameter is **NULL**, the message box has no owner window.

### `lpszText` [in]

Points to a null-terminated string that contains the message to be displayed.

### `lpszTitle` [in]

Points to a null-terminated string used for the dialog box title. If this parameter is **NULL**, the default title Error is used.

### `fuStyle` [in]

Specifies the content and behavior of the dialog box. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **MB_ABORTRETRYIGNORE** | The message box contains three command buttons: **Abort**, **Retry**, and **Ignore**. |
| **MB_APPLMODAL** | The user must respond to the message box before continuing to work in the window identified by the *hWndOwner* parameter. However, the user can move to windows of other applications to work. <br><br>Depending on the hierarchy of windows in the application, the user may be able to move to other windows within the application. All child windows of the parent of the message box are automatically disabled but pop-up windows are not.<br><br>MB_APPLMODAL is the default value if neither MB_SYSTEMMODAL nor MB_TASKMODAL is specified. |
| **MB_DEFAULT_DESKTOP_ONLY** | The desktop currently receiving input must be a default desktop; otherwise, the function fails. A default desktop is one on which an application runs after the user has logged on. |
| **MB_DEFBUTTON1** | The first button is the default button. Note that the first button is always the default unless MB_DEFBUTTON2 or MB_DEFBUTTON3 is specified. |
| **MB_DEFBUTTON2** | The second button is a default button. |
| **MB_DEFBUTTON3** | The third button is a default button. |
| **MB_DEFBUTTON4** | The fourth button is a default button. |
| **MB_ICONASTERISK** | An icon that consists of a lowercase letter in a circle appears in the message box. |
| **MB_ICONEXCLAMATION** | An exclamation point icon appears in the message box. |
| **MB_ICONHAND** | A hand icon appears in the message box. |
| **MB_ICONINFORMATION** | An icon that consists of a lowercase letter in a circle appears in the message box. |
| **MB_ICONQUESTION** | A question mark icon appears in the message box. |
| **MB_ICONSTOP** | A stop sign icon appears in the message box. |
| **MB_OK** | The message box contains one command button: **OK**. |
| **MB_OKCANCEL** | The message box contains two command buttons: **OK** and **Cancel**. |
| **MB_RETRYCANCEL** | The message box contains two command buttons: **Retry** and **Cancel**. |
| **MB_SERVICE_NOTIFICATION** | The caller is a service notifying the user of an event. The function brings up a message box on the current active desktop, even if there is no user logged on to the computer. |
| **MB_SETFOREGROUND** | The message box becomes the foreground window. Internally, Windows calls the [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow) function for the message box. |
| **MB_SYSTEMMODAL** | All applications are suspended until the user responds to the message box. Unless the application specifies MB_ICONHAND, the message box does not become modal until after it is created. Consequently, the owner window and other windows continue to receive messages resulting from its activation. Use system-modal message boxes to notify the user of serious, potentially damaging errors that require immediate attention, for example, running out of memory. |
| **MB_TASKMODAL** | Same as MB_APPLMODAL except that all the top-level windows that belong to the current task are disabled if the *hWndOwner* parameter is **NULL**. Use this flag when the calling application or library does not have a window handle available, but still needs to prevent input to other windows in the current application without suspending other applications. |
| **MB_YESNO** | The message box contains two command buttons: **Yes** and **No**. |
| **MB_YESNOCANCEL** | The message box contains three command buttons: **Yes**, **No**, and **Cancel**. |

## Return value

If the function fails, or if there is not enough memory to create the message box, the return value is zero.

If the function succeeds, the return value is one of the following menu item values returned by the dialog box.

**Note** If a message box has a **Cancel** button, the function returns the IDCANCEL value if either the **ESC** key is pressed or the **Cancel** button is clicked. If the message box has no **Cancel** button, pressing **ESC** has no effect.

| Return code | Description |
| --- | --- |
| **IDABORT** | **Abort** button was selected. |
| **IDCANCEL** | **Cancel** button was selected. |
| **IDIGNORE** | **Ignore** button was selected. |
| **IDNO** | A button was not selected. |
| **IDOK** | **OK** button was selected. |
| **IDRETRY** | **Retry** button was selected. |
| **IDYES** | **Yes** button was selected. |

## Remarks

The **WlxMessageBox** function does not handle [SAS](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) events, and is not suitable for security dialog boxes. Use the
[WlxDialogBox](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_dialog_box),
[WlxDialogBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_dialog_box_indirect), or
[WlxDialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_dialog_box_indirect_param) function for security dialog boxes.

**WlxMessageBox** duplicates the Windows
[MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) function, with the exception that this function also allows Winlogon to time out the dialog box. For more information, see
**MessageBox**.

## See also

[MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox)

[SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow)

[WlxDialogBox](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_dialog_box)

[WlxDialogBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_dialog_box_indirect)

[WlxDialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_dialog_box_indirect_param)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)