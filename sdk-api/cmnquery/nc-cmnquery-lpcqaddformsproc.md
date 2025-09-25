# LPCQADDFORMSPROC callback function

## Description

The **CQAddFormsProc** callback function is called by a query form extension to add a form to the query dialog box. A pointer to this function is supplied to the query form extension in the *pAddFormsProc* parameter of the [IQueryForm::AddForms](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-iqueryform-addforms) method. **CQAddFormsProc** is a placeholder for the query handler-defined function name.

## Parameters

### `lParam`

Contains a 32-bit value defined by the query handler. This value is passed to the query form extension as the *lParam* parameter in the [IQueryForm::AddForms](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-iqueryform-addforms) call.

### `pForm`

Pointer to a [CQFORM](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-cqform) structure that defines the form to add.

## Return value

Returns an **HRESULT** value that indicates the success, or failure, of the form add operation. The following list lists possible return values.

## See also

[CQFORM](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-cqform)

[IQueryForm::AddForms](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-iqueryform-addforms)