# ISyncMgrSynchronizeCallback::PrepareForSyncCompleted

## Description

Called by a registered handler of an application after the
[PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) method is complete.

## Parameters

### `hr` [in]

Type: **HRESULT**

The return value of the [PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) method. If S_OK is returned, the synchronization manager calls [Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) for the item. If the **HRESULT** is set to anything other than S_OK, the synchronization manager releases the handler without calling the **Synchronize** method.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The call is completed successfully. |

## Remarks

A registered handler of an application should return as soon as possible from the
[PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) method, and then call this method to notify the synchronization manager that the registered application is preparing for synchronization.

It is acceptable for the registered handler of an application to call this method before returning from the [PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) method.

The registered handler of an application should not call this method if the
[PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) method returns any value that is different from S_OK.

## See also

[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)

[PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync)

[Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize)