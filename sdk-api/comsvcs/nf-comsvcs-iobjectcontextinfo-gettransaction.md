# IObjectContextInfo::GetTransaction

## Description

Retrieves a reference to the current transaction. You can use this reference to manually enlist a resource manager that does not support automatic transactions.

## Parameters

### `pptrans` [out]

A reference to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the transaction that is currently executing. You can then [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to get the **ITransaction** interface for the current transaction.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The object is executing in a transaction. |
| **S_FALSE** | The object is not executing in a transaction. The *pptrans* parameter is **NULL**. |

## See also

[IObjectContextInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontextinfo)