# IOpLockStatus::GetOplockEventHandle

## Description

Gets the event handle of the opportunistic lock (OpLock). The event object is set to the signaled state when the OpLock is broken, enabling the indexer to stop all operations on the underlying [IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor) object.

## Parameters

### `phOplockEv` [out]

Type: **HANDLE***

Receives a pointer to the handle of the event associated with the OpLock, or **NULL** if no OpLock was taken.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.