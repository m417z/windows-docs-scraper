# LPCQADDPAGESPROC callback function

## Description

The **CQAddPagesProc** callback function is called by a query form extension to add a page to a query form in the query dialog box. A pointer to this function is supplied to the query form extension in the *pAddPagesProc* parameter of the [IQueryForm::AddPages](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-iqueryform-addpages) method. **CQAddPagesProc** is a placeholder for the query handler-defined function name.

## Parameters

### `lParam`

Contains a 32-bit value defined by the query handler. This value is passed to the query form extension as the *lParam* parameter in the [IQueryForm::AddPages](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-iqueryform-addpages) call.

### `clsidForm`

Contains the **CLSID** of the form that the page should be added to. This member can contain the **CLSID** of a custom query form or one of the system-supplied forms defined for the **clsidDefaultForm** member of the [OPENQUERYWINDOW](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-openquerywindow) structure.

### `pPage`

Pointer to a [CQPAGE](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-cqpage) structure that defines the page to be added.

## Return value

Returns an **HRESULT** value that indicates the success or failure of the page add operation. The following list lists possible return values.

## See also

[CQPAGE](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-cqpage)

[IQueryForm::AddPages](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-iqueryform-addpages)

[OPENQUERYWINDOW](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-openquerywindow)