# ISyncMgrSynchronizeCallback::ShowErrorCompleted

## Description

Called by the registered application's handler before or after its [PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) operation has been completed.

## Parameters

### `hr` [in]

Type: **HRESULT**

Whether [ShowError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showerror) was successful. This value is S_SYNCMGR_RETRYSYNC if the registered application's handler requires SyncMgr to retry the synchronization. When this value is returned to SyncMgr both the
[PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) and [Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) methods are called again.

### `cItems` [in]

Type: **ULONG**

The number of items in the array pointed to by the *pItemIDs* parameter. This parameter is ignored unless *hrResult* is S_SYNCMGR_RETRYSYNC.

### `pItemIDs` [in]

Type: **const GUID***

A pointer to the array of item IDs to pass to
[PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) in the event of a retry. This parameter is ignored unless *hrResult* is S_SYNCMGR_RETRYSYNC.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |

## Remarks

The *pItemIDs* parameter is an [in] parameter and the calling function owns the memory pointed to by it. SyncMgr makes a copy of the array before returning.

The registered application's handler should return from the [ShowError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showerror) method as soon as possible and then call this method to notify SyncMgr that it has completed processing the **ShowError** call.

It is acceptable for the registered application's handler to call this method
before returning from the [ShowError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showerror) method.

The registered application's handler should not call this method unless a success code is returned from the [ShowError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showerror) method.

## See also

[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)

[ShowError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showerror)