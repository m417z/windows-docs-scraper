# EndDialog function

## Description

Destroys a modal dialog box, causing the system to end any processing for the dialog box.

## Parameters

### `hDlg` [in]

Type: **HWND**

A handle to the dialog box to be destroyed.

### `nResult` [in]

Type: **INT_PTR**

The value to be returned to the application from the function that created the dialog box.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Dialog boxes created by the [DialogBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxa), [DialogBoxParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxparama), [DialogBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirecta), and [DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama) functions must be destroyed using the **EndDialog** function. An application calls **EndDialog** from within the dialog box procedure; the function must not be used for any other purpose.

A dialog box procedure can call **EndDialog** at any time, even during the processing of the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message. If your application calls the function while **WM_INITDIALOG** is being processed, the dialog box is destroyed before it is shown and before the input focus is set.

**EndDialog** does not destroy the dialog box immediately. Instead, it sets a flag and allows the dialog box procedure to return control to the system. The system checks the flag before attempting to retrieve the next message from the application queue. If the flag is set, the system ends the message loop, destroys the dialog box, and uses the value in *nResult* as the return value from the function that created the dialog box.

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[DialogBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxa)

[DialogBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirecta)

[DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama)

[DialogBoxParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxparama)

**Reference**

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)