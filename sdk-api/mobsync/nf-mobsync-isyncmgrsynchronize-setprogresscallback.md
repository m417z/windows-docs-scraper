# ISyncMgrSynchronize::SetProgressCallback

## Description

Sets the [ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback) interface. Registered applications use this callback interface to give status information from within the [ISyncMgrSynchronize::PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) and [ISyncMgrSynchronize::Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) methods.

## Parameters

### `lpCallBack` [in]

Type: **[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)***

A pointer to [ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback) interface the registered application uses to provide feedback to SyncMgr about the synchronization status and to notify SyncMgr when the synchronization is complete.

## Return value

Type: **HRESULT**

This method supports the standard return values, E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Synchronization callback interface was successfully set. |

## Remarks

Registered applications must call the [ISyncMgrSynchronizeCallback::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method and use it when calling SyncMgr to provide status text and progress indicator feedback.

If the registered application already has an [ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback) interface when the method is called, the old interface must be released and the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method of the new interface must be called. The new interface must be maintained by the registered application.

Before the [ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize) interface is released, SyncMgr calls this method with the *pSyncCallBack* parameter set to **NULL**. The registered application should then release the **ISyncMgrSynchronize** interface previously passed.

## See also

[ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize)

[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)