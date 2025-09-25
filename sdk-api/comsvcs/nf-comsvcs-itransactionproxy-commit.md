# ITransactionProxy::Commit

## Description

Commits the transaction.

## Parameters

### `guid` [in]

A GUID that identifies the transaction to commit.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The transaction was committed. |
| **CONTEXT_E_ABORTED** | The transaction was aborted. |

## Remarks

Calling **ITransactionProxy::Commit** attempts to commit a transaction. However, the transaction aborts under the following conditions:

* If a participating object returns from a method after calling [SetAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setabort).
* If an object calls [DisableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-disablecommit) and returns without calling [EnableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-enablecommit) or [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setcomplete).
* If an error causes the Microsoft Distributed Transaction Coordinator (DTC) to abort.

When the method returns, whether the transaction commits or aborts, the transaction ends.

## See also

[ITransactionProxy](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionproxy)