# FindTextW function

## Description

Creates a system-defined modeless **Find** dialog box that lets the user specify a string to search for and options to use when searching for text in a document.

## Parameters

### `unnamedParam1` [in]

Type: **LPFINDREPLACE**

A pointer to a [FINDREPLACE](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-findreplacea) structure that contains information used to initialize the dialog box. The dialog box uses this structure to send information about the user's input to your application. For more information, see the following Remarks section.

## Return value

Type: **HWND**

If the function succeeds, the return value is the window handle to the dialog box. You can use the window handle to communicate with or to close the dialog box.

If the function fails, the return value is **NULL**. To get extended error information, call the [CommDlgExtendedError](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-commdlgextendederror) function. **CommDlgExtendedError** may return one of the following error codes:

## Remarks

The **FindText** function does not perform a search operation. Instead, the dialog box sends [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) registered messages to the window procedure of the owner window of the dialog box. When you create the dialog box, the **hwndOwner** member of the [FINDREPLACE](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-findreplacea) structure is a handle to the owner window.

Before calling **FindText**, you must call the [RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea) function to get the identifier for the [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) message. The dialog box procedure uses this identifier to send messages when the user clicks the **Find Next** button, or when the dialog box is closing. The *lParam* parameter of the **FINDMSGSTRING** message contains a pointer to a [FINDREPLACE](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-findreplacea) structure. The **Flags** member of this structure indicates the event that caused the message. Other members of the structure indicate the user's input.

If you create a **Find** dialog box, you must also use the [IsDialogMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isdialogmessagea) function in the main message loop of your application to ensure that the dialog box correctly processes keyboard input, such as the TAB and ESC keys. **IsDialogMessage** returns a value that indicates whether the **Find** dialog box processed the message.

You can provide an [FRHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpfrhookproc) hook procedure for a **Find** dialog box. The hook procedure can process messages sent to the dialog box. To enable a hook procedure, set the **FR_ENABLEHOOK** flag in the **Flags** member of the [FINDREPLACE](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-findreplacea) structure and specify the address of the hook procedure in the **lpfnHook** member.

#### Examples

For an example, see [Finding Text](https://learn.microsoft.com/windows/desktop/dlgbox/using-common-dialog-boxes).

> [!NOTE]
> The commdlg.h header defines FindText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CommDlgExtendedError](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-commdlgextendederror)

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring)

[FINDREPLACE](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-findreplacea)

[FRHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpfrhookproc)

[IsDialogMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isdialogmessagea)

**Reference**

[RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea)

[ReplaceText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-replacetexta)