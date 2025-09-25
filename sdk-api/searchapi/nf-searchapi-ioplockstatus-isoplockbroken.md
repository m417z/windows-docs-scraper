# IOpLockStatus::IsOplockBroken

## Description

Checks the status of the opportunistic lock (OpLock) on the item being indexed.

## Parameters

### `pfIsOplockBroken` [out]

Type: **BOOL***

Receives a pointer to a **BOOL** value that indicates whether the OpLock is broken: **TRUE** if OpLock was taken and then broken, **FALSE** otherwise (including the case when OpLock was not taken).

## Return value

Type: **HRESULT**

Returns S_OK if the OpLock is broken, S_FALSE otherwise.

## Remarks

An OpLock is an opportunistic lock that allows the indexer to lock the item when another process isn't accessing it. The indexer releases the item, invalidating or breaking the lock, when another process requests an incompatible access mode. This enables the indexer to run in the background and not impede access to these items by other processes.