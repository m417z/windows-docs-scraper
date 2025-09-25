# ObjectContext::EnableCommit

## Description

Declares that the current object's work is not necessarily finished but that its transactional updates are consistent and could be committed in their present form.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully and the object's transactional updates can now be committed. |
| **E_UNEXPECTED** | An unexpected error has occurred. This can happen if one object passes its [ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext) pointer to another object and the other object calls [EnableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-enablecommit) using this pointer. An **ObjectContext** pointer is not valid outside the context of the object that originally obtained it. |

## Remarks

When an object calls **EnableCommit**, it allows the transaction in which it's participating to be committed but it maintains its internal state across calls from its clients until it calls [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setcomplete) or [SetAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setabort) or until the transaction completes.

**EnableCommit** is the default state when an object is activated. Therefore, an object should always call [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setcomplete) or [SetAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setabort) before returning from a method, unless you want the object to maintain its internal state for the next call from a client.

## See also

[ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext)