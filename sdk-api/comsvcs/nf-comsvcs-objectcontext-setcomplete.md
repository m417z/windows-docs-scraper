# ObjectContext::SetComplete

## Description

Declares that the transaction in which the object is executing can be committed and that the object should be deactivated on return.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. This can happen if one object passes its [ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext) pointer to another object and the other object calls [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setcomplete) using this pointer. An **ObjectContext** pointer is not valid outside the context of the object that originally obtained it. |

## Remarks

The object is deactivated automatically on return from the method in which it called **SetComplete**. If the object is the root of an automatic transaction, COM+ attempts to commit the transaction. However, if any object that was participating in the transaction has called [SetAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setabort), or has called [DisableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-disablecommit) and has not subsequently called [EnableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-enablecommit) or **SetComplete**, the transaction is aborted.

If an object does not need to maintain its state after it returns from a method call, it should call **SetComplete** so that it can be automatically deactivated as soon as it returns and its resources can be reclaimed.

## See also

[ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext)