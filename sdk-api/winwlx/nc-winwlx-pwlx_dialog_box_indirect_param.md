# PWLX_DIALOG_BOX_INDIRECT_PARAM callback function

## Description

[The WlxDialogBoxIndirectParam function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to initialize dialog box controls and then create a modal dialog box from a dialog box template in memory.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `hInst` [in]

Specifies the instance of the module that creates the dialog box.

### `hDialogTemplate` [in]

Specifies the address of a global memory object that contains a dialog box template used to create the dialog box. The template is in the form of a
[DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate) structure followed by one or more
[DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate) structures. For a full description of these structures, see the Platform SDK.

### `hwndOwner` [in]

Specifies the window that owns the dialog box.

### `dlgprc` [in]

Points to the dialog box procedure. For more information about the dialog box procedure, see the description of the
[DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc) callback function in the Platform SDK.

### `dwInitParam` [in]

Specifies the value used to initialize the dialog box control. This value is passed to the dialog box in the *lParam* parameter of the
[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message.

## Return value

If the function succeeds, the function returns the *nResult* parameter given in the call to the
[EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog) function used to terminate the dialog box. The following table lists some possible success return values.

| Return code | Description |
| --- | --- |
| **WLX_DLG_INPUT_TIMEOUT** | Input timed out. |
| **WLX_DLG_SAS** | A [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS) event occurred. |
| **WLX_DLG_SCREEN_SAVER_TIMEOUT** | The screen saver timed out. |
| **WLX_DLG_USER_LOGOFF** | The user logged off. |

If the function fails, the return value is –1.

## Remarks

**WlxDialogBoxIndirectParam** duplicates the Windows [DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama) function and also allows Winlogon to terminate the dialog box. For more information, see
**DialogBoxIndirectParam**.

## See also

[DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate)

[DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate)

[DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama)

[DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc)

[EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog)

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)