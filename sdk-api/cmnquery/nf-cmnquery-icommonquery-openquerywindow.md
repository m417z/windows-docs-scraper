# ICommonQuery::OpenQueryWindow

## Description

The **ICommonQuery::OpenQueryWindow** method displays the directory service query dialog. This method does not return until the dialog box has been closed by the user.

## Parameters

### `hwndParent` [in]

Contains the handle of the window to use as the parent to the query dialog box. This parameter can be **NULL** if no parent is specified.

### `pQueryWnd` [in]

Address of an
[OPENQUERYWINDOW](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-openquerywindow) structure that defines the query to perform and the characteristics of the query dialog.

### `ppDataObject` [out]

Address of an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface pointer that receives the results of the query. This parameter only receives valid data if this method returns **S_OK**. This **IDataObject** supports the following clipboard formats.

#### CFSTR_DSOBJECTNAMES

Contains data about objects selected in the directory service query dialog box.

#### CFSTR_DSQUERYPARAMS

Contains data about the query performed by the directory service query dialog box.

#### CFSTR_DSQUERYSCOPE

Contains data about the scope of the query performed by the directory service query dialog box.

## Return value

Returns a standard **HRESULT** value including the following.

## See also

[CFSTR_DSOBJECTNAMES](https://learn.microsoft.com/windows/desktop/AD/cfstr-dsobjectnames)

[CFSTR_DSQUERYPARAMS](https://learn.microsoft.com/windows/desktop/AD/cfstr-dsqueryparams)

[CFSTR_DSQUERYSCOPE](https://learn.microsoft.com/windows/desktop/AD/cfstr-dsqueryscope)

[DSQUERYINITPARAMS](https://learn.microsoft.com/windows/desktop/api/dsquery/ns-dsquery-dsqueryinitparams)

[DSQUERYPARAMS](https://learn.microsoft.com/windows/desktop/api/dsquery/ns-dsquery-dsqueryparams)

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[ICommonQuery](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-icommonquery)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[OPENQUERYWINDOW](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-openquerywindow)