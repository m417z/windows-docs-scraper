# IEnumSyncMgrConflict::Next

## Description

Gets the next batch of conflicts from the conflicts store.

## Parameters

### `celt` [in]

Type: **ULONG**

The value must be 1.

### `rgelt` [out]

Type: **[ISyncMgrConflict](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflict)****

The address of an [ISyncMgrConflict](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflict) interface pointer.

### `pceltFetched` [out]

Type: **ULONG***

A pointer to the number of conflicts fetched.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.