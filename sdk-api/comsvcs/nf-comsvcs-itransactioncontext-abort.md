# ITransactionContext::Abort

## Description

Aborts the work of all COM objects participating in the current transaction. The transaction ends on return from this method.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The transaction was aborted. |
| **E_FAIL** | The [TransactionContext](https://learn.microsoft.com/windows/desktop/cossdk/transactioncontext) object is not running under a COM+ process, possibly indicating a corrupted registry entry for the **TransactionContext** component. |

## Remarks

Calling **Abort** ends the transaction on return of the method and automatically deactivates all participating objects. Each resource manager enlisted in the transaction rolls back the operations performed on behalf of those objects.

## See also

[ITransactionContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactioncontext)