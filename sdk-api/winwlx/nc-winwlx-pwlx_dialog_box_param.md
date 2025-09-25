# PWLX_DIALOG_BOX_PARAM callback function

## Description

[The WlxDialogBoxParam function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to initialize dialog box controls and then create a modal dialog box from a dialog box template resource.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `hInst` [in]

Specifies an instance of the module whose executable file contains the dialog box template.

### `lpszTemplate` [in]

Specifies the dialog box template. This parameter is either the address of a null-terminated character string that specifies the name of the dialog box template, or an integer value that specifies the resource identifier of the dialog box template. If the parameter specifies a resource identifier, its high-order word must be zero and its low-order word must contain the identifier. You can use the
[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro to create this value.

### `hwndOwner` [in]

Specifies the window that owns the dialog box.

### `dlgprc` [in]

Points to the dialog box procedure. For more information about the dialog box procedure, see
[DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc).

### `dwInitParam` [in]

Specifies the value to pass to the dialog box in the *lParam* parameter of the
[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message.

## Return value

If the **WlxDialogBoxParam** function succeeds, the return value is the value of the *nResult* parameter given in the call to the
[EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog) function used to terminate the dialog box. The following table lists some possible success return values.

| Return code | Description |
| --- | --- |
| **WLX_DLG_INPUT_TIMEOUT** | Input timed out. |
| **WLX_DLG_SAS** | A [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS) event occurred. |
| **WLX_DLG_SCREEN_SAVER_TIMEOUT** | The screen saver timed out. |
| **WLX_DLG_USER_LOGOFF** | The user logged off. |

If the function fails, the return value is –1.

## Remarks

**WlxDialogBoxParam** duplicates the Windows [DialogBoxParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxparama) function, and also allows Winlogon to terminate the dialog box. For more information, see
**DialogBoxParam**.

## See also

[DialogBoxParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxparama)

[DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc)

[EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)