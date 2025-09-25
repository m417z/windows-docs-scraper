# ISyncMgrConflictItems::GetItem

## Description

Gets a specified conflict data item.

## Parameters

### `iIndex` [in]

Type: **UINT**

The index of the conflict item to retrieve.

### `pItemInfo` [out]

Type: **[CONFIRM_CONFLICT_ITEM](https://learn.microsoft.com/windows/desktop/api/syncmgr/ns-syncmgr-confirm_conflict_item)***

When this method returns successfully, contains a pointer to a [CONFIRM_CONFLICT_ITEM](https://learn.microsoft.com/windows/desktop/api/syncmgr/ns-syncmgr-confirm_conflict_item) structure that contains information about the conflict.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.