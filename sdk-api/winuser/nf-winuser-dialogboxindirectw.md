# DialogBoxIndirectW macro

## Description

Creates a modal dialog box from a dialog box template in memory. **DialogBoxIndirect** does not return control until the specified callback function terminates the modal dialog box by calling the [EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog) function.

**DialogBoxIndirect** is implemented as a call to the [DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama) function.

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the module that creates the dialog box.

### `lpTemplate` [in]

Type: **LPCDLGTEMPLATE**

The template that **DialogBoxIndirect** uses to create the dialog box. A dialog box template consists of a header that describes the dialog box, followed by one or more additional blocks of data that describe each of the controls in the dialog box. The template can use either the standard format or the extended format.

In a standard template for a dialog box, the header is a [DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate) structure followed by additional variable-length arrays. The data for each control consists of a [DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate) structure followed by additional variable-length arrays.

In an extended template for a dialog box, the header uses the [DLGTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgtemplateex) format and the control definitions use the [DLGITEMTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgitemtemplateex) format.

### `hWndParent` [in, optional]

Type: **HWND**

A handle to the window that owns the dialog box.

### `lpDialogFunc` [in, optional]

Type: **DLGPROC**

A pointer to the dialog box procedure. For more information about the dialog box procedure, see [DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc).

## Remarks

The **DialogBoxIndirect** macro uses the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function to create the dialog box. **DialogBoxIndirect** then sends a [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message to the dialog box procedure. If the template specifies the [DS_SETFONT](https://learn.microsoft.com/windows/desktop/dlgbox/about-dialog-boxes) or DS_SHELLFONT style, the function also sends a [WM_SETFONT](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont) message to the dialog box procedure. The function displays the dialog box (regardless of whether the template specifies the **WS_VISIBLE** style), disables the owner window, and starts its own message loop to retrieve and dispatch messages for the dialog box.

When the dialog box procedure calls the [EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog) function, **DialogBoxIndirect** destroys the dialog box, ends the message loop, enables the owner window (if previously enabled), and returns the *nResult* parameter specified by the dialog box procedure when it called **EndDialog**.

In a standard dialog box template, the [DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate) structure and each of the [DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate) structures must be aligned on **DWORD** boundaries. The creation data array that follows a **DLGITEMTEMPLATE** structure must also be aligned on a **DWORD** boundary. All of the other variable-length arrays in the template must be aligned on **WORD** boundaries.

In an extended dialog box template, the [DLGTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgtemplateex) header and each of the [DLGITEMTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgitemtemplateex) control definitions must be aligned on **DWORD** boundaries. The creation data array, if any, that follows a **DLGITEMTEMPLATEEX** structure must also be aligned on a **DWORD** boundary. All of the other variable-length arrays in the template must be aligned on **WORD** boundaries.

All character strings in the dialog box template, such as titles for the dialog box and buttons, must be Unicode strings. Use the [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) function to generate Unicode strings from ANSI strings.

#### Examples

For an example, see [Creating a Template in Memory](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

> [!NOTE]
> The winuser.h header defines DialogBoxIndirect as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate)

[DLGITEMTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgitemtemplateex)

[DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate)

[DLGTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgtemplateex)

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[DialogBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxa)

[DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama)

[DialogBoxParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxparama)

[DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc)

[EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog)

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

**Other Resources**

**Reference**

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)

[WM_SETFONT](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont)