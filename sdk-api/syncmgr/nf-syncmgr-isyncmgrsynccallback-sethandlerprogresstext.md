# ISyncMgrSyncCallback::SetHandlerProgressText

## Description

Sets the content of an information field for the handler while that handler is performing a synchronization.

## Parameters

### `pszProgressText` [in]

Type: **LPCWSTR**

Pointer to a buffer containing the comment text.

### `pnCancelRequest` [in, out]

Type: **[SYNCMGR_CANCEL_REQUEST](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_cancel_request)***

A value from the [SYNCMGR_CANCEL_REQUEST](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_cancel_request) enumeration specifying the nature of a cancel request, if any.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.