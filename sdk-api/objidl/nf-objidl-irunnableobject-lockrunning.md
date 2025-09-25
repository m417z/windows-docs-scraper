# IRunnableObject::LockRunning

## Description

Locks an already running object into its running state or unlocks it from its running state.

## Parameters

### `fLock` [in]

**TRUE** locks the object into its running state. **FALSE** unlocks the object from its running state.

### `fLastUnlockCloses` [in]

**TRUE** specifies that if the connection being released is the last external lock on the object, the object should close. **FALSE** specifies that the object should remain open until closed by the user or another process.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Most implementations of **IRunnableObject::LockRunning** call [CoLockObjectExternal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-colockobjectexternal).

[OleLockRunning](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olelockrunning) is a helper function that conveniently repackages the functionality offered by **IRunnableObject::LockRunning**. With the release of OLE 2.01, the implementation of **OleLockRunning** was changed to call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)), ask for [IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject), and then call **IRunnableObject::LockRunning**. In other words, you can use the interface and the helper function interchangeably.

## See also

[CoLockObjectExternal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-colockobjectexternal)

[IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject)

[OleLockRunning](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olelockrunning)