# ISyncMgrSyncItemContainer::GetSyncItem

## Description

Gets a specified sync item.

## Parameters

### `pszItemID` [in]

Type: **LPCWSTR***

A pointer to a buffer containing the item ID representing the desired item. The ID is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `ppItem` [out]

Type: **[ISyncMgrSyncItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsyncitem)****

When this method returns, contains the address of a pointer to an [ISyncMgrSyncItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsyncitem) instance representing the sync item.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. Returns E_INVALIDARG if the handler does not recognize the ID specified at *ppszItemID*.