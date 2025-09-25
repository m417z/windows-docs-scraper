# ISynchronizeEvent::SetEventHandle

## Description

Assigns an event handle to a synchronization object.

## Parameters

### `ph` [in]

A pointer to the event handle.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

If the method is successful,
the object assumes ownership of the event handle,
and the caller should not close the handle.

## See also

[ISynchronizeEvent](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isynchronizeevent)