# ISynchronizeHandle::GetHandle

## Description

Retrieves a handle to the synchronization object.

## Parameters

### `ph` [out]

A pointer to the variable that receives a handle to the synchronization object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

Do not close the handle returned in the *ph* parameter.
The lifetime of the handle is controlled by the object that implements the ISynchronizeHandle interface.

## See also

[ISynchronizeEvent::SetEventHandle](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isynchronizeevent-seteventhandle)

[ISynchronizeHandle](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isynchronizehandle)