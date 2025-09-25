# IClassFactory::LockServer

## Description

Locks an object application open in memory. This enables instances to be created more quickly.

## Parameters

### `fLock` [in]

If **TRUE**, increments the lock count; if **FALSE**, decrements the lock count.

## Return value

This method can return the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

**IClassFactory::LockServer** controls whether an object's server is kept in memory. Keeping the application alive in memory allows instances to be created more quickly.

### Notes to Callers

Most clients do not need to call this method. It is provided only for those clients that require special performance in creating multiple instances of their objects.

### Notes to Implementers

If the lock count is zero, there are no more objects in use, and the application is not under user control, the server can be closed. One way to implement **LockServer** is to call the [CoLockObjectExternal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-colockobjectexternal) function.

The process that locks the object application is responsible for unlocking it. After the class object is released, there is no mechanism that guarantees the caller connection to the same class later (as in the case where a class object is registered as single-use). It is important to count all calls, not just the last one, to **LockServer**, because calls must be balanced before attempting to release the pointer to the [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) interface on the class object or an error results. For every call to **LockServer** with *fLock* set to **TRUE**, there must be a call to **LockServer** with *fLock* set to **FALSE**. When the lock count and the class object reference count are both zero, the class object can be freed.

## See also

[CoLockObjectExternal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-colockobjectexternal)

[IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory)