## Description

CPSUI's **GetCPSUIUserData** function retrieves data that was previously stored using the [SetCPSUIUserData](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nf-compstui-setcpsuiuserdata) function.

## Parameters

### `hDlg`

Caller-supplied handle to a property sheet dialog box. For more information, see the **Remarks** section below.

## Return value

If the operation succeeds, the function returns the value that was previously supplied to [SetCPSUIUserData](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nf-compstui-setcpsuiuserdata); otherwise the function returns zero.

## Remarks

The **GetCPSUIUserData** function should only be called from within a dialog box procedure that has been associated with a dialog box by using a [DLGPAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_dlgpage) or an [EXTPUSH](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_extpush) structure.

The handle specified for *hDlg* must be the handle received as input to the dialog box procedure. For more information, see [Dialog box programming considerations](https://learn.microsoft.com/windows/win32/dlgbox/dlgbox-programming-considerations).