# ISyncMgrHandler::GetName

## Description

Gets the display name of the handler.

## Parameters

### `ppszName` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to a **null**-terminated buffer that receives the handler name. The name can be of maximum length MAX_SYNCMGR_NAME, including the terminating **null** character. If the name exceeds that length, it is truncated.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The handler name is accessed as the System.DisplayName (PKEY_DisplayName) property in the Sync Center folder.

Sync Center calls this method any time that [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) or [UpdateHandlerCollection](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandlercollection) is called. If **ISyncMgrHandler::GetName** fails or returns an empty string, the handler is not shown in the Sync Center folder and Sync Center will not attempt to invoke it.

It is the responsibility of the handler to allocate the string buffer using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). Sync Center deallocates the buffer through [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

**ISyncMgrHandler::GetName** replaces the use of [GetHandlerInfo](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-gethandlerinfo) to retrieve the handler name.