# IQueryForm::AddPages

## Description

The **IQueryForm::AddPages** method is called to allow a query form object to add pages to an existing form.

## Parameters

### `pAddPagesProc` [in]

Pointer to a callback function of the form [CQAddPagesProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqaddpagesproc). The query form extension calls this function with the supplied *lParam* one time for each page to be added to a form.

### `lParam` [in]

Contains a 32-bit value that is defined by the query handler. This value must be passed as the *lParam* parameter in the [CQAddPagesProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqaddpagesproc) call.

## Return value

Returns **S_OK** if successful or a standard **HRESULT** failure code otherwise.

## See also

[CQAddPagesProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqaddpagesproc)

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IQueryForm](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-iqueryform)