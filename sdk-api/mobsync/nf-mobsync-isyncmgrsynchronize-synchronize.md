# ISyncMgrSynchronize::Synchronize

## Description

Called by the synchronization manager once for each selected group after the user has chosen the registered applications to be synchronized.

## Parameters

### `hWndParent` [in]

Type: **HWND**

A handle to the parent **HWND** the registered application should use for any user interface elements that it displays. This value may be **NULL**.

## Return value

Type: **HRESULT**

This method supports the standard return values, E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Synchronization was successful. |
| **E_FAIL** | Synchronization failed. |

## Remarks

If the user does not select any item choices for the registered application, the **ISyncMgrSynchronize::Synchronize** method is not called and the interface is released. If this method is called, the application must synchronize the items that were specified in the [ISyncMgrSynchronize::PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) method.

The registered application's handler should return from the **ISyncMgrSynchronize::Synchronize** method as soon as possible and then call the
[SynchronizeCompleted](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-synchronizecompleted) method. It is acceptable for the handler to call the **SynchronizeCompleted** call before returning from the **ISyncMgrSynchronize::Synchronize** method.

The application must give progress feedback and check whether the synchronization should be canceled by using the *pSyncCallBack* interface pointer that was set up in the [ISyncMgrSynchronize::SetProgressCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-setprogresscallback) method.

Applications must provide progress information even if the
[SYNCMGRFLAG_MAYBOTHERUSER](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag) flag was not specified in [ISyncMgrSynchronize::Initialize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-initialize).

Applications should try not to show user interface elements from within the
**ISyncMgrSynchronize::Synchronize** method. Any user interface elements should be shown in the [ISyncMgrSynchronize::PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) and [ISyncMgrSynchronize::ShowError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showerror) methods so the end user experiences a consistent user interface which is limited to logon and to specifying shares to be synchronized. Subsequently, the synchronization can be performed without any user intervention. After the synchronization is complete, conflicts or other error messages can be shown.

The [ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback) methods can be called on any thread in your application.

## See also

[ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize)

[ISyncMgrSynchronize::Initialize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-initialize)

[ISyncMgrSynchronize::PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync)

[ISyncMgrSynchronize::SetProgressCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-setprogresscallback)

[ISyncMgrSynchronize::ShowError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showerror)

[SynchronizeCompleted](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-synchronizecompleted)