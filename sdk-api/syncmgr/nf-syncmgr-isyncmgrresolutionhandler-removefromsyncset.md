# ISyncMgrResolutionHandler::RemoveFromSyncSet

## Description

Deletes the conflict and removes the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) from synchronization.

## Parameters

### `pFeedback` [out]

Type: **[SYNCMGR_RESOLUTION_FEEDBACK](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_resolution_feedback)***

A pointer to a [SYNCMGR_RESOLUTION_FEEDBACK](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_resolution_feedback) value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that is in conflict will no longer be synchronized and the conflict should be deleted.

The [SYNCMGR_RESOLUTION_FEEDBACK](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_resolution_feedback) value returned in *pFeedback* determines how the next conflict is resolved. If this method fails, an error message is displayed and the user is asked how to proceed.