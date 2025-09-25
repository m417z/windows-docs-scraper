# ISyncMgrEvent::GetFlags

## Description

Gets event flags.

## Parameters

### `pnFlags` [out]

Type: **[SYNCMGR_EVENT_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_event_flags)***

When this method returns, contains a pointer to a value that indicates the currently set flags, taken from members of the [SYNCMGR_EVENT_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_event_flags) enumeration.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.