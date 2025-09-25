# ITransactionProxy::GetIsolationLevel

## Description

Retrieves the isolation level of the non-DTC transaction.

## Parameters

### `__MIDL__ITransactionProxy0000` [out, retval]

A pointer to an [ISOLATIONLEVEL](https://learn.microsoft.com/previous-versions/windows/desktop/ms679234(v=vs.85)) value that specifies the isolation level of the non-DTC transaction.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## See also

[ITransactionProxy](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionproxy)