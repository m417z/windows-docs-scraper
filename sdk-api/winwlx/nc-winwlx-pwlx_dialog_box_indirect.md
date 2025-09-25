# PWLX_DIALOG_BOX_INDIRECT callback function

## Description

[The WlxDialogBoxIndirect function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to create a modal dialog box from a dialog box template in memory.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Winlogon handle provided to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `hInst` [in]

Identifies the instance of the module that creates the dialog box.

### `hDialogTemplate` [in]

Specifies the address of a global memory object that contains a dialog box template used to create the dialog box. The template is in the form of a
[DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate) structure followed by one or more
[DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate) structures. For a full description of these structures, see the Platform SDK.

### `hwndOwner` [in]

Identifies the window that owns the dialog box.

### `dlgprc` [in]

Points to the dialog box procedure. For more information about the dialog box procedure, see
[DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc).

## Return value

If the **WlxDialogBoxIndirect** function succeeds, the return value is the *nResult* parameter given in the call to the
[EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog) function used to terminate the dialog box. The following table lists some possible success return values.

| Return code | Description |
| --- | --- |
| **WLX_DLG_INPUT_TIMEOUT** | Input timed out. |
| **WLX_DLG_SAS** | A [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS) event occurred. |
| **WLX_DLG_SCREEN_SAVER_TIMEOUT** | The screen saver timed out. |
| **WLX_DLG_USER_LOGOFF** | The user logged off. |

If the function fails, the return value is –1.

## Remarks

**WlxDialogBoxIndirect** duplicates the Windows [DialogBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirecta) macro, and also allows Winlogon to terminate the dialog box. For more information, see
**DialogBoxIndirect**.

## See also

[DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate)

[DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate)

[DialogBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirecta)

[DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc)

[EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)