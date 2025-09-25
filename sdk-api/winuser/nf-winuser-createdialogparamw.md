# CreateDialogParamW function

## Description

Creates a modeless dialog box from a dialog box template resource. Before displaying the dialog box, the function passes an application-defined value to the dialog box procedure as the *lParam* parameter of the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message. An application can use this value to initialize dialog box controls.

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the module which contains the dialog box template. If this parameter is NULL, then the current executable is used.

### `lpTemplateName` [in]

Type: **LPCTSTR**

The dialog box template. This parameter is either the pointer to a null-terminated character string that specifies the name of the dialog box template or an integer value that specifies the resource identifier of the dialog box template. If the parameter specifies a resource identifier, its high-order word must be zero and low-order word must contain the identifier. You can use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro to create this value.

### `hWndParent` [in, optional]

Type: **HWND**

A handle to the window that owns the dialog box.

### `lpDialogFunc` [in, optional]

Type: **DLGPROC**

A pointer to the dialog box procedure. For more information about the dialog box procedure, see [DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc).

### `dwInitParam` [in]

Type: **LPARAM**

The value to be passed to the dialog box procedure in the *lParam* parameter in the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message.

## Return value

Type: **HWND**

If the function succeeds, the return value is the window handle to the dialog box.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **CreateDialogParam** function uses the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function to create the dialog box. **CreateDialogParam** then sends a [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message (and a [WM_SETFONT](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont) message if the template specifies the [DS_SETFONT](https://learn.microsoft.com/windows/desktop/dlgbox/about-dialog-boxes) or DS_SHELLFONT style) to the dialog box procedure. The function displays the dialog box if the template specifies the **WS_VISIBLE** style. Finally, **CreateDialogParam** returns the window handle of the dialog box.

After **CreateDialogParam** returns, the application displays the dialog box (if it is not already displayed) using the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function. The application destroys the dialog box by using the [DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow) function. To support keyboard navigation and other dialog box functionality, the message loop for the dialog box must call the [IsDialogMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isdialogmessagea) function.

> [!NOTE]
> The winuser.h header defines CreateDialogParam as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[CreateDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialoga)

[CreateDialogIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialogindirecta)

[CreateDialogIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialogindirectparama)

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow)

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc)

[IsDialogMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isdialogmessagea)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

**Reference**

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)

[WM_SETFONT](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont)