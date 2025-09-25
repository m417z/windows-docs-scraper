## Description

CPSUI's SetCPSUIUserData function allows CPSUI applications (including printer interface DLLs) to associate non-displayed data with a property sheet dialog box.

## Parameters

### `hDlg`

Caller-supplied handle to a property sheet dialog box. For more information, see the Remarks section below.

### `CPSUIUserData`

Caller-supplied value to be stored.

## Return value

The function returns **TRUE** if it is successful in associating the non-displayed data with the property sheet dialog box, and **FALSE** otherwise.

## Remarks

The **SetCPSUIUserData** function should be called only from within a dialog box procedure that has been associated with a dialog box by using a [**DLGPAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_dlgpage) or an [**EXTPUSH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_extpush) structure.

A value that is stored by calling SetCPSUIUserData can be later retrieved by calling [GetCPSUIUserData](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nf-compstui-getcpsuiuserdata).

The handle specified for *hDlg* must be the handle received as input to the [dialog box procedure](https://learn.microsoft.com/windows-hardware/drivers/print/dialog-box-procedures-and-cpsui).