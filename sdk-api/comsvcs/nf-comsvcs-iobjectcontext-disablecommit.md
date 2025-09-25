# IObjectContext::DisableCommit

## Description

Declares that the object's transactional updates are in an inconsistent state and cannot be committed in their present state.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. The object's transactional updates cannot be committed until the object calls either [EnableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-enablecommit) or [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setcomplete). |
| **E_UNEXPECTED** | An unexpected error occurred. This can happen if one object passes its [IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext) pointer to another object and the other object calls [DisableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-disablecommit) using this pointer. An **IObjectContext** pointer is not valid outside the context of the object that originally obtained it. |
| **CONTEXT_E_NOCONTEXT** | The current object does not have a context associated with it. This is probably because it was not created with one of the COM+ CreateInstance methods. |

## Remarks

You can use the **DisableCommit** method to prevent a transaction from committing prematurely between method calls in a stateful object. When an object invokes **DisableCommit**, it indicates that its work is inconsistent and that it cannot complete its work until it receives further method invocations from the client. It also indicates that it needs to maintain its state to perform that work. This prevents COM+ from deactivating the object and reclaiming its resources on return from a method call. When an object has called **DisableCommit**, if a client attempts to commit the transaction before the object has called [EnableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-enablecommit) or [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setcomplete), the transaction aborts.

For example, suppose you have a GeneralLedger component that updates a database. A client makes multiple calls to a GeneralLedger object to post entries to various accounts. There's an integrity constraint that says the debits must equal the credits when the final method invocation returns, or the transaction must abort. The GeneralLedger object has an initialization method in which the client informs it of the sequence of calls the client is going to make, and the GeneralLedger object calls **DisableCommit**. The object maintains its state between calls so that, after the final call in the sequence is made, the object can make sure the integrity constraint is satisfied before allowing its work to be committed.

## See also

[IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext)