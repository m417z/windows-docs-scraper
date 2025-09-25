# ObjectContext::SetAbort

## Description

Declares that the transaction in which the object is executing must be aborted and that the object should be deactivated on return.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. This can happen if one object passes its [ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext) pointer to another object and the other object calls [SetAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setabort) using this pointer. An **ObjectContext** pointer is not valid outside the context of the object that originally obtained it. |

## Remarks

The object is deactivated automatically on return from the method in which it called **SetAbort**. If the object is the root of an automatic transaction, COM+ aborts the transaction. If the object is transactional but not the root of an automatic transaction, the transaction in which it is participating is doomed to abort.

You can call **SetAbort** in error handlers to ensure that a transaction aborts when an error occurs. You can also call **SetAbort** at the beginning of a method to prevent your object from committing prematurely in the event of an unexpected return and then, if all goes well, call [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-setcomplete) just before the method returns.

## See also

[ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext)