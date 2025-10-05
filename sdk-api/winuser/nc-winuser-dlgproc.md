# DLGPROC callback function

## Description

Application-defined callback function used with the [CreateDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialoga) and [DialogBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxa) families of functions. It processes messages sent to a modal or modeless dialog box. The **DLGPROC** type defines a pointer to this callback function. _DialogProc_ is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

Type: **HWND**

A handle to the dialog box. This parameter is typically named _hWnd_.

### `unnamedParam2`

Type: **UINT**

The message. This parameter is typically named _uMsg_.

### `unnamedParam3`

Type: **WPARAM**

Additional message-specific information. This parameter is typically named _wParam_.

### `unnamedParam4`

Type: **LPARAM**

Additional message-specific information. This parameter is typically named _lParam_.

## Return value

Type: **INT_PTR**

Typically, the dialog box procedure should return **TRUE** if it processed the message, and **FALSE** if it did not. If the dialog box procedure returns **FALSE**, the dialog manager performs the default dialog operation in response to the message.

If the dialog box procedure processes a message that requires a specific return value, the dialog box procedure should set the desired return value by calling [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga)(_hwndDlg_, **DWL_MSGRESULT**, _lResult_) immediately before returning **TRUE**. Note that you must call **SetWindowLong** immediately before returning **TRUE**; doing so earlier may result in the **DWL_MSGRESULT** value being overwritten by a nested dialog box message.

The following messages are exceptions to the general rules stated above. Consult the documentation for the specific message for details on the semantics of the return value.

- [WM_CHARTOITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-chartoitem)
- [WM_COMPAREITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-compareitem)
- [WM_CTLCOLORBTN](https://learn.microsoft.com/windows/desktop/Controls/wm-ctlcolorbtn)
- [WM_CTLCOLORDLG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-ctlcolordlg)
- [WM_CTLCOLOREDIT](https://learn.microsoft.com/windows/desktop/Controls/wm-ctlcoloredit)
- [WM_CTLCOLORLISTBOX](https://learn.microsoft.com/windows/desktop/Controls/wm-ctlcolorlistbox)
- [WM_CTLCOLORSCROLLBAR](https://learn.microsoft.com/windows/desktop/Controls/wm-ctlcolorscrollbar)
- [WM_CTLCOLORSTATIC](https://learn.microsoft.com/windows/desktop/Controls/wm-ctlcolorstatic)
- [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)
- [WM_QUERYDRAGICON](https://learn.microsoft.com/windows/desktop/winmsg/wm-querydragicon)
- [WM_VKEYTOITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-vkeytoitem)

## Remarks

> [!NOTE]
> The parameters are defined in the header with no names: `typedef INT_PTR (CALLBACK* DLGPROC)(HWND, UINT, WPARAM, LPARAM);`. Therefore, the syntax block lists them as `unnamedParam1` - `unnamedParam4`. You can name these parameters anything in your app. However, they are usually named as shown in the parameter descriptions.

You should use the dialog box procedure only if you use the dialog box class for the dialog box. This is the default class and is used when no explicit class is specified in the dialog box template. Although the dialog box procedure is similar to a window procedure, it must not call the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function to process unwanted messages. Unwanted messages are processed internally by the dialog box window procedure.

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)

**Reference**

[CreateDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialoga)

[CreateDialogIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialogindirecta)

[CreateDialogIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialogindirectparama)

[CreateDialogParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialogparama)

[DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca)

[DialogBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxa)

[DialogBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirecta)

[DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama)

[DialogBoxParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxparama)

[SetFocus](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setfocus)