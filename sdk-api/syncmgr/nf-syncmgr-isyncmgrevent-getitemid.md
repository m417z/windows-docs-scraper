# ISyncMgrEvent::GetItemID

## Description

Gets the ID of the item for which the event was logged.

## Parameters

### `ppszItemID` [out]

Type: **LPWSTR***

Contains a pointer to an item ID as a Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The item ID can have a maximum length of MAX_SYNCMGR_ID, including the terminating null character. The event is expected to allocate the string buffer using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), which Sync Center uses to deallocate the string buffer.