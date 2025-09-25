# IEnumSyncMgrEvents::Next

## Description

Gets the next batch of events from the event store.

## Parameters

### `celt` [in]

Type: **ULONG**

This value must be 1.

### `rgelt` [out]

Type: **[ISyncMgrEvent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrevent)****

The address of an [ISyncMgrEvent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrevent) interface pointer.

### `pceltFetched` [out]

Type: **ULONG***

A pointer to the number of events fetched.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.