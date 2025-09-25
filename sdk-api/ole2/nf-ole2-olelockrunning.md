# OleLockRunning function

## Description

Locks an already running object into its running state or unlocks it from its running state.

## Parameters

### `pUnknown` [in]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the object, which the function uses to query for a pointer to [IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject).

### `fLock` [in]

**TRUE** locks the object into its running state. **FALSE** unlocks the object from its running state.

### `fLastUnlockCloses` [in]

**TRUE** specifies that if the connection being released is the last external lock on the object, the object should close. **FALSE** specifies that the object should remain open until closed by the user or another process.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

The **OleLockRunning** function saves you the trouble of calling the [IRunnableObject::LockRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-lockrunning) method. You can use **OleLockRunning** and **IRunnableObject::LockRunning** interchangeably. With the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer passed in with the *pUnknown* parameter, **OleLockRunning** queries for an [IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject) pointer. If successful, it calls **IRunnableObject::LockRunning** and returns the results of the call.

For more information on using this function, see [IRunnableObject::LockRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-lockrunning).

## See also

[CoLockObjectExternal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-colockobjectexternal)

[IRunnableObject::LockRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-lockrunning)

[OleNoteObjectVisible](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olenoteobjectvisible)