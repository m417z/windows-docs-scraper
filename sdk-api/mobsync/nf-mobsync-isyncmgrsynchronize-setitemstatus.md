# ISyncMgrSynchronize::SetItemStatus

## Description

Called by the synchronization manager in a registered application's handler to change the status of an item in the following two cases: between the time the handler has returned from the [ISyncMgrSynchronize::PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) method and called the
[PrepareForSyncCompleted](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-prepareforsynccompleted) callback method, or after the handler has returned from the [ISyncMgrSynchronize::Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) method but has not yet called the [SynchronizeCompleted](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-synchronizecompleted) callback method.

## Parameters

### `pItemID` [in]

Type: **REFGUID**

Identifies the item with changed status.

### `dwSyncMgrStatus` [in]

Type: **DWORD**

The new status for the specified item taken from the
[SYNCMGRSTATUS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrstatus) enumeration.

## Return value

Type: **HRESULT**

This method supports the standard return values, E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Status was set. |

## Remarks

Currently, the only [SYNCMGRSTATUS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrstatus) status value supported by the SyncMgr is SYNCMGRSTATUS_SKIPPED. The registered application's handler should skip the item specified in *pItemID* when it receives this status value.

## See also

[ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize)

[ISyncMgrSynchronize::PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync)

[ISyncMgrSynchronize::SetProgressCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-setprogresscallback)

[ISyncMgrSynchronize::Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize)

[PrepareForSyncCompleted](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-prepareforsynccompleted)

[SYNCMGRSTATUS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrstatus)

[SynchronizeCompleted](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-synchronizecompleted)