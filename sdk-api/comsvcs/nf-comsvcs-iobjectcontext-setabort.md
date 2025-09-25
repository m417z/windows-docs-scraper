# IObjectContext::SetAbort

## Description

Declares that the transaction in which the object is executing must be aborted and that the object should be deactivated when it returns from the currently executing method call.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error occurred. This can happen if one object passes its [IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext) pointer to another object and the other object calls [SetAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setabort) using this pointer. An **IObjectContext** pointer is not valid outside the context of the object that originally obtained it. |

## Remarks

The object is deactivated automatically on return from the method in which it called **SetAbort**. If the object is the root of an automatic transaction, COM+ aborts the transaction. If the object is transactional but not the root of an automatic transaction, the transaction in which it's participating is doomed to abort.

You can call **SetAbort** in error handlers to ensure that a transaction aborts when an error occurs. You can also call **SetAbort** at the beginning of a method to prevent your object from committing prematurely in the event of an unexpected return and then, if all goes well, call [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setcomplete) just before the method returns.

## See also

[IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext)