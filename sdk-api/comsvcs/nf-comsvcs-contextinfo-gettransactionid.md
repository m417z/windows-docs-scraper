# ContextInfo::GetTransactionId

## Description

Retrieves the transaction identifier associated with the object context. Objects in the same transaction share the same transaction identifier.

## Parameters

### `pbstrTxId` [out]

A reference to the transaction identifier.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CONTEXT_E_NOTRANSACTION** | The object is not executing within a transaction. |

## See also

[ContextInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-contextinfo)