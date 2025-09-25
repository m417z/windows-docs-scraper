# IPrintDialogCallback::InitDone

## Description

Called by [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) when the system has finished initializing the **General** page of the [Print Property Sheet](https://learn.microsoft.com/windows/desktop/dlgbox/print-property-sheet).

## Return value

Type: **HRESULT**

Return **S_OK** to prevent the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function from performing its default actions.

Return **S_FALSE** to allow [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) to perform its default actions. Currently, **PrintDlgEx** does not perform any default processing after the **InitDone** call.

## Remarks

If your callback object implements the [IObjectWithSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iobjectwithsite) interface, the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function calls the [IObjectWithSite::SetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite) method to pass an [IPrintDialogServices](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogservices) pointer to the callback object. The **PrintDlgEx** function calls the **IObjectWithSite::SetSite** method before calling the **InitDone** method. This enables your **InitDone** implementation to use the **IPrintDialogServices** methods to retrieve information about the currently selected printer.

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[IPrintDialogCallback](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogcallback)

[IPrintDialogServices](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogservices)

[PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85))

**Reference**