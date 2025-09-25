# ISyncMgrSyncResult::Result

## Description

Gets the result of a [StartHandlerSync](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-starthandlersync) or [StartItemSync](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-startitemsync) call.

## Parameters

### `nStatus` [in]

Type: **[SYNCMGR_PROGRESS_STATUS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_progress_status)**

The current status of the progress report. See [SYNCMGR_PROGRESS_STATUS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_progress_status).

### `cError` [in]

Type: **UINT**

An error.

### `cConflicts` [in]

Type: **UINT**

Specifies conflicts.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.