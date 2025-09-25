# ITransactionContextEx::Commit

## Description

Attempts to commit the work of all COM objects participating in the current transaction. The transaction ends on return from this method.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The transaction was committed. |
| **E_FAIL** | The [TransactionContextEx](https://learn.microsoft.com/windows/desktop/cossdk/transactioncontextex) object is not running under a COM+ process, possibly indicating a corrupted registry entry for the **TransactionContextEx** component. |
| **CONTEXT_E_ABORTED** | The transaction was aborted. |

## Remarks

Calling [Commit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-itransactioncontext-commit) attempts to commit a transaction. However, the transaction aborts under the following conditions:

* If a participating object returns from a method after calling [SetAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setabort).
* If an object calls [DisableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-disablecommit) and returns without calling [EnableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-enablecommit) or [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setcomplete).
* If an error causes the Microsoft Distributed Transaction Coordinator (DTC) to abort.

When the method returns, whether the transaction commits or aborts, the transaction ends.

#### Examples

See the example in [ITransactionContextEx::Abort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-itransactioncontextex-abort).

## See also

[ITransactionContextEx](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactioncontextex)