# IObjectContextInfo::GetTransactionId

## Description

Retrieves the identifier of the current transaction.

## Parameters

### `pGuid` [out]

A GUID that identifies the current transaction.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **S_FALSE** | The object is not executing in a transaction. |

## Remarks

Objects in the same transaction share the same transaction identifier.

## See also

[IObjectContextInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontextinfo)