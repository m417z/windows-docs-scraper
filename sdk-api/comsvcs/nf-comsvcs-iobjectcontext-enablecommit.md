# IObjectContext::EnableCommit

## Description

Declares that the object's work is not necessarily finished but that its transactional updates are in a consistent state and could be committed in their present form.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully and the object's transactional updates can now be committed. |
| **E_UNEXPECTED** | An unexpected error occurred. This can happen if one object passes its [IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext) pointer to another object and the other object calls [EnableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-enablecommit) using this pointer. An **IObjectContext** pointer is not valid outside the context of the object that originally obtained it. |

## Remarks

When an object calls **EnableCommit**, it allows the transaction in which it's participating to be committed but it maintains its internal state across calls from its clients until it calls [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setcomplete) or [SetAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setabort) or until the transaction completes.

**EnableCommit** is the default state when an object is activated. Therefore, an object should always call [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setcomplete) or [SetAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setabort) before returning from a method, unless you want the object to maintain its internal state for the next call from a client.

## See also

[IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext)