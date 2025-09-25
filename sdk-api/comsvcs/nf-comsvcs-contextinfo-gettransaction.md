# ContextInfo::GetTransaction

## Description

Retrieves the object context's transaction object.

## Parameters

### `ppTx` [out]

A reference to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the transaction object for the currently executing transaction.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **S_FALSE** | The object is not executing in a transaction. The *ppTx* parameter is **NULL**. |

## See also

[ContextInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-contextinfo)