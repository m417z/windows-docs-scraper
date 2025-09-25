# ISyncMgrConflictStore::EnumConflicts

## Description

Enumerates conflicts scoped to the provided sync handler and sync item.

## Parameters

### `pszHandlerID` [in]

Type: **LPCWSTR**

A pointer to the sync handler ID as a Unicode string.

### `pszItemID` [in]

Type: **LPCWSTR**

A pointer to the sync item ID as a Unicode string.

### `ppEnum` [out]

Type: **[IEnumSyncMgrConflict](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-ienumsyncmgrconflict)****

The address of an [IEnumSyncMgrConflict](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-ienumsyncmgrconflict) interface pointer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the sync handler, sync item, or partner name is **NULL**, the conflict store ignores that parameter.