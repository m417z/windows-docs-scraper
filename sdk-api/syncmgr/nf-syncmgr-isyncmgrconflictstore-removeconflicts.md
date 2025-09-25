# ISyncMgrConflictStore::RemoveConflicts

## Description

Deletes a set of conflicts, specified by conflict ID, from the store.

## Parameters

### `rgConflictIdInfo` [in]

Type: **const [SYNCMGR_CONFLICT_ID_INFO](https://learn.microsoft.com/windows/desktop/api/syncmgr/ns-syncmgr-syncmgr_conflict_id_info)***

A pointer to a [SYNCMGR_CONFLICT_ID_INFO](https://learn.microsoft.com/windows/desktop/api/syncmgr/ns-syncmgr-syncmgr_conflict_id_info) structure.

### `cConflicts` [in]

Type: **DWORD**

The conflict set.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The conflicts are removed when the user selects the conflicts in the conflicts folder and chooses to delete them.