# ISyncMgrSyncItemInfo::GetComment

## Description

Gets a string that contains commentary regarding the item.

## Parameters

### `ppszComment` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to a buffer containing the comment string. This string is of maximum length MAX_SYNCMGR_NAME including the terminating null character.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. If the method fails, *ppszComment* contains an empty string.

## Remarks

This string could be provided by an item to display a summary of its contents, for example, "32 contacts" or "13 songs". The string can have a maximum length of MAX_SYNCMGR_NAME including the terminating null character.

The comment value is displayed as the System.Sync.Comments (PKEY_Sync_Comments) property in the folder UI when a synchronization is not being performed.

Sync Center calls this method whenever the [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) method is called.

The item is responsible for allocating the string buffer pointed to by *ppszComment* through [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). Sync Center deallocates the string buffer through [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).