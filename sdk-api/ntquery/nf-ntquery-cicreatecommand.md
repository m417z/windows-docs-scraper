# CICreateCommand function

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Creates a Command object.

## Parameters

### `ppCommand`

A pointer to a variable that receives the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer requested in *riid*.

### `pUnkOuter`

A pointer to an optional outer [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. This parameter can be zero for no aggregation, in which case *riid* can contain a value other than IID_IUnknown.

### `riid`

The interface identifier (IID) of the interface returned in *ppCommand*. This parameter must be IID_IUnknown unless *pUnkOuter* is **NULL**. Pass IID_ICommand to get an [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface if aggregation isn't needed and *pUnkOuter* is **NULL**.

### `pwcsCatalog`

The name of the catalog to be used to execute queries. This is the value for the DBPROP_CI_CATALOG_NAME property of the [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface.

### `pwcsMachine`

The name of the computer on which the query is to be executed. This is the value for the DBPROP_CI_MACHINE_NAME property of the [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface. Use L"." for the local computer.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **CLASS_E_NOAGGREGATION** | Aggregation exists (*pUnkOuter* is not **NULL**) and *riid* is not IID_IUnknown. |
| **E_INVALIDARG** | The function received an invalid parameter. |

## Remarks

The **CICreateCommand** function simplifies the task of connecting to the Indexing Service content and property indexes as an OLE DB provider data source object (DSO) and creating a session object. Queries made with the resulting [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface default to the scope "\" and search everywhere under that hierarchy (a "deep" search). To specify a scope, use [CIMakeICommand](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-cimakeicommand).

If interface aggregation isn't required, pass IID_ICommand for riid and **NULL** for *pUnkOuter*. Otherwise, call [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the returned object to get an [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface.

The **CICreateCommand** function does not return an error if the catalog or computer do not exist or are not available. The connection to the catalog and computer are established when the **ICommand::Execute** method is called, and connection errors are returned at that time.

Additional catalog, computer, and scope parameters can be specified after an [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface is created using the [ICommandProperties](https://learn.microsoft.com/previous-versions/windows/desktop/ms723044(v=vs.85)) interface.

A pointer to a null-terminated string that specifies the name of the machine on which the query is executed. This is the value for the DBPROP_CI_MACHINE_NAME property of the [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface. Use L"." for the local computer.

#### Examples

This example creates an [ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface for the system catalog on the local machine.

```
ICommand * pICommand;
HRESULT hr = CICreateCommand( (IUnknown **) &pICommand, 0, IID_ICommand, L"system", L"." );
if ( SUCCEEDED( hr ) )
{
    // ...
    // execute one or more queries with the ICommand
    // ...
    pICommand->Release();
}

```

## See also

[CIMakeICommand](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-cimakeicommand)

[ICommand](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85))

[ICommandProperties](https://learn.microsoft.com/previous-versions/windows/desktop/ms723044(v=vs.85))

