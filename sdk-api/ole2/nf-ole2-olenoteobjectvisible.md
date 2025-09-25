# OleNoteObjectVisible function

## Description

Increments or decrements an external reference that keeps an object in the running state.

## Parameters

### `pUnknown` [in]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the object that is to be locked or unlocked.

### `fVisible` [in]

Whether the object is visible. If **TRUE**, OLE increments the reference count to hold the object visible and alive regardless of external or internal [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) and [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) operations, registrations, or revocation. If **FALSE**, OLE releases its hold (decrements the reference count) and the object can be closed.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

The **OleNoteObjectVisible** function calls the [CoLockObjectExternal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-colockobjectexternal) function. It is provided as a separate function to reinforce the need to lock an object when it becomes visible to the user and to release the object when it becomes invisible. This creates a strong lock on behalf of the user to ensure that the object cannot be closed by its container while it is visible.

## See also

[CoLockObjectExternal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-colockobjectexternal)