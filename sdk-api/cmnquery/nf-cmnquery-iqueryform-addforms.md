# IQueryForm::AddForms

## Description

The **IQueryForm::AddForms** method is called to allow a query form extension object to add forms to the query dialog box.

## Parameters

### `pAddFormsProc` [in]

Pointer to a callback function of the form [CQAddFormsProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqaddformsproc). The query form extension calls this function with the supplied *lParam* one time for each form to be added.

### `lParam` [in]

Contains a 32-bit value that is defined by the query handler. This value must be passed as the *lParam* parameter in the [CQAddFormsProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqaddformsproc) call.

## Return value

Returns **S_OK** if successful or a standard **HRESULT** failure code otherwise.

## See also

[CQAddFormsProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqaddformsproc)

[IQueryForm](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-iqueryform)