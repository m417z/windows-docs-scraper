# ISyncMgrConflict::GetConflictIdInfo

## Description

Gets information that identifies a conflict within a conflict store.

## Parameters

### `pConflictIdInfo` [out]

Type: **[SYNCMGR_CONFLICT_ID_INFO](https://learn.microsoft.com/windows/desktop/api/syncmgr/ns-syncmgr-syncmgr_conflict_id_info)***

A pointer to a conflict ID info structure. See [SYNCMGR_CONFLICT_ID_INFO](https://learn.microsoft.com/windows/desktop/api/syncmgr/ns-syncmgr-syncmgr_conflict_id_info).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** Each member should be allocated using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). Free each member using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

This method contains two opaque blobs: One is the ID uniquely identifying a conflict within a conflict store. The other is optional extra information stored with the conflict that may be used by the implementation when creating conflict objects in [BindToConflict](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictstore-bindtoconflict) and [RemoveConflicts](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrconflictstore-removeconflicts).

The size of of the ID blob must be kept short so that the ID may be embedded inside the conflict's pointer to an item identifier list (PIDL) or parsing name.