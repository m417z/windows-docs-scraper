# IEnumSyncMgrSyncItems::Next

## Description

Gets the next batch of sync items from the handler.

## Parameters

### `celt` [in]

Type: **ULONG**

This value must be 1.

### `rgelt` [out]

Type: **[ISyncMgrSyncItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsyncitem)****

The address of an [ISyncMgrSyncItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsyncitem) interface pointer.

### `pceltFetched` [out]

Type: **ULONG***

A pointer to the number of items fetched.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.