# ISyncMgrEvent::GetHandlerID

## Description

Gets the ID of the handler for which the event was logged.

## Parameters

### `ppszHandlerID` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to a handler ID as a Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The handler ID can have a maximum length of MAX_SYNCMGR_ID, including the terminating null character. The event is expected to allocate the string buffer using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), which Sync Center uses to deallocate the string buffer.