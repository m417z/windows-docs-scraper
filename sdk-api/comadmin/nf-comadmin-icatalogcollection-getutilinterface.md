# ICatalogCollection::GetUtilInterface

## Description

[This method is for use with MTS 2.0 administration interfaces and objects and should not be used with COM+ administration interfaces and objects. It works as before with MTS 2.0 administration interfaces and objects, with the exception of IRemoteComponentUtil, which is no longer supported.]

Retrieves the utility interface for the collection.

## Parameters

### `ppIDispatch` [out, retval]

The utility interface.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_OBJECTERRORS** | Errors occurred while accessing one or more objects. |

## See also

[ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection)