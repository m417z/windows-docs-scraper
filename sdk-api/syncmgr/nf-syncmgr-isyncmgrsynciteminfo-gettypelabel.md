# ISyncMgrSyncItemInfo::GetTypeLabel

## Description

Gets a label for the item type. This typically provides the model of the device or an equivalent item-specific identity string.

## Parameters

### `ppszTypeLabel` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to a buffer containing the label string.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. If the method fails, *ppszTypeLabel* contains an empty string.

## Remarks

The label value is displayed as the System.Sync.ItemTypeLabel (PKEY_Sync_ItemTypeLabel) property in the folder UI. Sync Center calls this method whenever the [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) or [UpdateItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updateitem) method is called.

The item is responsible for allocating the string buffer pointed to by *ppszTypeLabel* through [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). Sync Center deallocates the string buffer through [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).