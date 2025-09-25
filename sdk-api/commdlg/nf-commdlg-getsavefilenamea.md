# GetSaveFileNameA function

## Description

[Starting with Windows Vista, the **Open** and **Save As** common dialog boxes have been superseded by the [Common Item Dialog](https://learn.microsoft.com/windows/win32/shell/common-file-dialog). We recommended that you use the Common Item Dialog API instead of these dialog boxes from the Common Dialog Box Library.]

Creates a **Save** dialog box that lets the user specify the drive, directory, and name of a file to save.

## Parameters

### `unnamedParam1` [in, out]

Type: **LPOPENFILENAME**

A pointer to an [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure that contains information used to initialize the dialog box. When **GetSaveFileName** returns, this structure contains information about the user's file selection.

## Return value

Type: **BOOL**

If the user specifies a file name and clicks the
**OK** button and the function is successful, the return value is nonzero. The buffer pointed to by the
**lpstrFile** member of the [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure contains the full path and file name specified by the user.

If the user cancels or closes the
**Save** dialog box or an error such as the file name buffer being too small occurs, the return value is zero. To get extended error information, call the [CommDlgExtendedError](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-commdlgextendederror) function, which can return one of the following values:

## Remarks

The Explorer-style **Save** dialog box that provides user-interface features that are similar to the Windows Explorer. You can provide an [OFNHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpofnhookproc) hook procedure for an Explorer-style **Save** dialog box. To enable the hook procedure, set the **OFN_EXPLORER** and **OFN_ENABLEHOOK** flags in the **Flags** member of the [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure and specify the address of the hook procedure in the **lpfnHook** member.

Windows continues to support old-style **Save** dialog boxes for applications that want to maintain a user-interface consistent with the old-style user-interface. To display the old-style **Save** dialog box, enable an [OFNHookProcOldStyle](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646932(v=vs.85)) hook procedure and ensure that the **OFN_EXPLORER** flag is not set.

#### Examples

For an example, see [Creating an Enhanced Metafile](https://learn.microsoft.com/windows/desktop/gdi/creating-an-enhanced-metafile).

> [!NOTE]
> The commdlg.h header defines GetSaveFileName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CommDlgExtendedError](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-commdlgextendederror)

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[GetOpenFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getopenfilenamea)

[OFNHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpofnhookproc)

[OFNHookProcOldStyle](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646932(v=vs.85))

[OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea)

**Reference**