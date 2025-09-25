# TSPI_providerFreeDialogInstance function

## Description

The
**TSPI_providerFreeDialogInstance** function informs the service provider that the dialog box associated with *hdDlgInst* has exited. After this function is called, the service provider should no longer send data to the dialog box using
[LINE_SENDDIALOGINSTANCEDATA](https://learn.microsoft.com/windows/desktop/Tapi/line-senddialoginstancedata) messages.

Implementation of this function is optional; it is needed only if the service provider generates spontaneous dialog boxes in application contexts using
[LINE_CREATEDIALOGINSTANCE](https://learn.microsoft.com/windows/desktop/Tapi/line-createdialoginstance).

## Parameters

### `hdDlgInst`

The opaque identifier of the association between the service provider and the dialog box in the application's context, which was passed as the **hdDlgInstance** member in the
[TUISPICREATEDIALOGINSTANCEPARAMS](https://learn.microsoft.com/windows/desktop/api/tspi/ns-tspi-tuispicreatedialoginstanceparams) structure with the LINE_CREATEDIALOGINSTANCE message that created the dialog box.

## Return value

Returns zero if successful, or one of these negative error values:

LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED.

## See also

[LINE_CREATEDIALOGINSTANCE](https://learn.microsoft.com/windows/desktop/Tapi/line-createdialoginstance)

[LINE_SENDDIALOGINSTANCEDATA](https://learn.microsoft.com/windows/desktop/Tapi/line-senddialoginstancedata)

[TUISPICREATEDIALOGINSTANCEPARAMS](https://learn.microsoft.com/windows/desktop/api/tspi/ns-tspi-tuispicreatedialoginstanceparams)