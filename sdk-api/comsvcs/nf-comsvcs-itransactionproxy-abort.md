# ITransactionProxy::Abort

## Description

Aborts the transaction.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## Remarks

Calling **ITransactionProxy::Abort** ends the transaction on return of the method and automatically deactivates all participating objects. Each resource manager enlisted in the transaction rolls back the operations performed on behalf of those objects.

## See also

[ITransactionProxy](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionproxy)