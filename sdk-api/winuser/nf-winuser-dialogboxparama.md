# DialogBoxParamA function

## Description

Creates a modal dialog box from a dialog box template resource. Before displaying the dialog box, the function passes an application-defined value to the dialog box procedure as the *lParam* parameter of the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message. An application can use this value to initialize dialog box controls.

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the module which contains the dialog box template. If this parameter is NULL, then the current executable is used.

### `lpTemplateName` [in]

Type: **LPCTSTR**

The dialog box template. This parameter is either the pointer to a null-terminated character string that specifies the name of the dialog box template or an integer value that specifies the resource identifier of the dialog box template. If the parameter specifies a resource identifier, its high-order word must be zero and its low-order word must contain the identifier. You can use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro to create this value.

### `hWndParent` [in, optional]

Type: **HWND**

A handle to the window that owns the dialog box.

### `lpDialogFunc` [in, optional]

Type: **DLGPROC**

A pointer to the dialog box procedure. For more information about the dialog box procedure, see [DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc).

### `dwInitParam` [in]

Type: **LPARAM**

The value to pass to the dialog box in the *lParam* parameter of the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message.

## Return value

Type: **INT_PTR**

If the function succeeds, the return value is the value of the *nResult* parameter specified in the call to the [EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog) function used to terminate the dialog box.

If the function fails because the *hWndParent* parameter is invalid, the return value is zero. The function returns zero in this case for compatibility with previous versions of Windows. If the function fails for any other reason, the return value is –1. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **DialogBoxParam** function uses the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function to create the dialog box. **DialogBoxParam** then sends a [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message (and a [WM_SETFONT](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont) message if the template specifies the [DS_SETFONT](https://learn.microsoft.com/windows/desktop/dlgbox/about-dialog-boxes) or DS_SHELLFONT style) to the dialog box procedure. The function displays the dialog box (regardless of whether the template specifies the **WS_VISIBLE** style), disables the owner window, and starts its own message loop to retrieve and dispatch messages for the dialog box.

When the dialog box procedure calls the [EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog) function, **DialogBoxParam** destroys the dialog box, ends the message loop, enables the owner window (if previously enabled), and returns the *nResult* parameter specified by the dialog box procedure when it called **EndDialog**.

> [!NOTE]
> The winuser.h header defines DialogBoxParam as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[DialogBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxa)

[DialogBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirecta)

[DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama)

[DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc)

[EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

**Reference**

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)

[WM_SETFONT](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont)