# ISyncMgrSyncCallback::CommitItem

## Description

Confirms a specified item as a member of the handler's sync set and confirms that it should be shown in the UI.

## Parameters

### `pszItemID` [in]

Type: **LPCWSTR***

A pointer to a buffer containing the unique ID of the item to confirm. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. Returns E_INVALIDARG if the item has not been first submitted through [ISyncMgrSyncCallback::ProposeItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-proposeitem) or if the item is already part of the current session.