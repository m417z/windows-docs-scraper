# CreateDialogIndirectParamA function

## Description

Creates a modeless dialog box from a dialog box template in memory. Before displaying the dialog box, the function passes an application-defined value to the dialog box procedure as the *lParam* parameter of the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message. An application can use this value to initialize dialog box controls.

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the module which contains the dialog box template. If this parameter is NULL, then the current executable is used.

### `lpTemplate` [in]

Type: **LPCDLGTEMPLATE**

The template **CreateDialogIndirectParam** uses to create the dialog box. A dialog box template consists of a header that describes the dialog box, followed by one or more additional blocks of data that describe each of the controls in the dialog box. The template can use either the standard format or the extended format.

In a standard template, the header is a [DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate) structure followed by additional variable-length arrays. The data for each control consists of a [DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate) structure followed by additional variable-length arrays.

In an extended dialog box template, the header uses the [DLGTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgtemplateex) format and the control definitions use the [DLGITEMTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgitemtemplateex) format.

After **CreateDialogIndirectParam** returns, you can free the template, which is only used to get the dialog box started.

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

Type: **HWND**

If the function succeeds, the return value is the window handle to the dialog box.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **CreateDialogIndirectParam** function uses the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function to create the dialog box. **CreateDialogIndirectParam** then sends a [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message to the dialog box procedure. If the template specifies the [DS_SETFONT](https://learn.microsoft.com/windows/desktop/dlgbox/about-dialog-boxes) or DS_SHELLFONT style, the function also sends a [WM_SETFONT](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont) message to the dialog box procedure. The function displays the dialog box if the template specifies the **WS_VISIBLE** style. Finally, **CreateDialogIndirectParam** returns the window handle to the dialog box.

After **CreateDialogIndirectParam** returns, you can use the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function to display the dialog box (if it is not already visible). To destroy the dialog box, use the [DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow) function. To support keyboard navigation and other dialog box functionality, the message loop for the dialog box must call the [IsDialogMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isdialogmessagea) function.

In a standard dialog box template, the [DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate) structure and each of the [DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate) structures must be aligned on **DWORD** boundaries. The creation data array that follows a **DLGITEMTEMPLATE** structure must also be aligned on a **DWORD** boundary. All of the other variable-length arrays in the template must be aligned on **WORD** boundaries.

In an extended dialog box template, the [DLGTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgtemplateex) header and each of the [DLGITEMTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgitemtemplateex) control definitions must be aligned on **DWORD** boundaries. The creation data array, if any, that follows a **DLGITEMTEMPLATEEX** structure must also be aligned on a **DWORD** boundary. All of the other variable-length arrays in the template must be aligned on **WORD** boundaries.

All character strings in the dialog box template, such as titles for the dialog box and buttons, must be Unicode strings.

> [!NOTE]
> The winuser.h header defines CreateDialogIndirectParam as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[CreateDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialoga)

[CreateDialogIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialogindirecta)

[CreateDialogParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialogparama)

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate)

[DLGITEMTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgitemtemplateex)

[DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate)

[DLGTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgtemplateex)

[DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow)

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc)

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

**Other Resources**

**Reference**

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)

[WM_SETFONT](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont)