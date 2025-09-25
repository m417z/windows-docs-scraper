# IPrintDialogCallback::SelectionChange

## Description

Called by [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) when the user selects a different printer from the list of installed printers on the **General** page of the [Print Property Sheet](https://learn.microsoft.com/windows/desktop/dlgbox/print-property-sheet).

## Return value

Type: **HRESULT**

Return **S_OK** to prevent the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function from performing its default actions.

Return **S_FALSE** to allow [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) to perform its default actions, which include adjustments to the **Copies**, **Collate**, and **Print Range** items.

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[IPrintDialogCallback](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogcallback)

[PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85))

**Reference**