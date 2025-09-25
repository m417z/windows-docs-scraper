# ISyncMgrEvent::GetLevel

## Description

Gets the log level of the event.

## Parameters

### `pnLevel` [out]

Type: **[SYNCMGR_EVENT_LEVEL](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_event_level)***

When this method returns, contains a pointer to a member of the [SYNCMGR_EVENT_LEVEL](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_event_level) enumeration that indicates the log level.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.