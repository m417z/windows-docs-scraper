# CIMakeICommand function

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Creates a Command object, specifying computers, catalogs, and scopes.

## Parameters

### `ppCommand`

A pointer to an output variable that receives the [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface pointer.

### `cScope`

The number of scopes in the *awcsScope* array.

### `aDepths`

A pointer to an array of values that represent the type of search (deep or shallow, virtual or physical) for each scope in *awcsScope*. For the possible values for each scope, see [QUERY_*](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/query-scope-constants) scope constants.

### `awcsScope`

A pointer to a an array of null-terminated strings that specify the names of the file path(s) over which the query is processed. This is the value for the DBPROP_CI_INCLUDE_SCOPE property of the [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface. Use L"\" for the entire catalog. Use L"\" for the entire Internet Information Services (IIS) virtual-path namespace, but set QUERY_VIRTUAL_PATH in the *aDepths* parameter to indicate that the path is virtual.

### `awcsCatalogs`

A pointer to a an array of null-terminated strings that specify the names of the catalogs used to execute queries. This is the value for the DBPROP_CI_CATALOG_NAME property of the [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface.

### `awcsMachine`

A pointer to a null-terminated string that specifies the name of the computer on which the query is to be executed. This is the value for the DBPROP_CI_MACHINE_NAME property of the [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface. Use L"." for the local computer.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **E_ACCESSDENIED** | The function was denied access to a specified path. |
| **E_HANDLE** | The function encountered an invalid handle, probably due to a low-memory situation. |
| **E_INVALIDARG** | The function received an invalid parameter. |
| **E_OUTOFMEMORY** | The function did not have sufficient memory or other resources to complete the operation. |
| **E_FAIL** | An unknown error has occurred. |

## Remarks

The **CIMakeICommand** function does not return an error if the catalog or computer does not exist or is unavailable. The connection to the catalog and computer is established when the **ICommand::Execute** method is called, and connection errors are returned at that time.

## See also

[CICreateCommand](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-cicreatecommand)

[ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85))

