# ISyncMgrConflictStore::BindToConflict

## Description

Binds to a particular conflict specified by IID.

## Parameters

### `pConflictIdInfo` [in]

Type: **const [SYNCMGR_CONFLICT_ID_INFO](https://learn.microsoft.com/windows/desktop/api/syncmgr/ns-syncmgr-syncmgr_conflict_id_info)***

A pointer to a [SYNCMGR_CONFLICT_ID_INFO](https://learn.microsoft.com/windows/desktop/api/syncmgr/ns-syncmgr-syncmgr_conflict_id_info) structure.

### `riid` [in]

Type: **REFIID**

A reference to a desired conflict IID.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is used when the conflict folder binds to a conflict, given its pointer to an item identifier list (PIDL) or parsing name. The ID is obtained from a conflict that was previously extracted from the store. See [ISyncMgrConflict](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflict).