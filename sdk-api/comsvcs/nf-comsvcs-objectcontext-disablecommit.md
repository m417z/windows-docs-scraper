# ObjectContext::DisableCommit

## Description

Declares that the object's transactional updates are inconsistent and cannot be committed in their present state.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. The object's transactional updates cannot be committed until the object calls either [EnableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-enablecommit) or [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setcomplete). |
| **E_UNEXPECTED** | An unexpected error has occurred. This can happen if one object passes its [ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext) pointer to another object and the other object calls [DisableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-disablecommit) using this pointer. An **ObjectContext** pointer is not valid outside the context of the object that originally obtained it. |
| **CONTEXT_E_NOCONTEXT** | The current object doesn't have a context associated with it. This is probably because it was not created with one of the COM+ **CreateInstance** methods. |

## Remarks

You can use the **DisableCommit** method to prevent a transaction from committing prematurely between method calls in a stateful object. When an object invokes **DisableCommit**, it indicates that its work is inconsistent and that it cannot complete its work until it receives further method invocations from the client. It also indicates that it needs to maintain its state to perform that work. This prevents COM+ from deactivating the object and reclaiming its resources on return from a method call. When an object has called **DisableCommit**, if a client attempts to commit the transaction before the object has called [EnableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-enablecommit) or [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setcomplete), the transaction aborts.

## See also

[ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext)