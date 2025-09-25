# IOpLockStatus::IsOplockValid

## Description

Checks the status of the opportunistic lock (OpLock) on the item being indexed.

## Parameters

### `pfIsOplockValid` [out]

Type: **BOOL***

Receives a pointer to a **BOOL** value that indicates whether the OpLock is successfully taken.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An OpLock is an opportunistic lock that allows the indexer to lock the item when another process is not accessing it. The indexer releases the item, invalidating or breaking the lock, when another process requests an incompatible access mode. This enables the indexer to run in the background and not impede access to these items by other processes.

An OpLock is never taken after the underlying [IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor) object is initialized, and any call to this method yields the same output value on the same object.