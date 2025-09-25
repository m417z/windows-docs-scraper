# ISyncMgrConflictResolutionItems::GetItem

## Description

Gets result information for a specified item, when successful.

## Parameters

### `iIndex` [in]

Type: **UINT**

The index of the item.

### `pItemInfo` [out]

Type: **[CONFIRM_CONFLICT_RESULT_INFO](https://learn.microsoft.com/windows/desktop/api/syncmgr/ns-syncmgr-confirm_conflict_result_info)***

On success, contains a pointer to a [CONFIRM_CONFLICT_RESULT_INFO](https://learn.microsoft.com/windows/desktop/api/syncmgr/ns-syncmgr-confirm_conflict_result_info) structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.