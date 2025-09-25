# ISyncMgrSynchronizeCallback::SynchronizeCompleted

## Description

Called by an application when its [Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) method is complete.

## Parameters

### `hr` [in]

Type: **HRESULT**

The returned result from the [Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) method.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The call is completed successfully. |

## Remarks

A registered handler of an application should return from the
[Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) method as soon as possible, and then call this method to notify the synchronization manager that the synchronization process is complete.

It is acceptable for a registered handler of an application to call this method before returning from the [Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) method.

However, the registered handler of an application should not call this method if the [Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) method returns any value that is different from S_OK.

## See also

[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)

[Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize)