# ISyncMgrSynchronize::ShowError

## Description

Called by the synchronization manager in a registered application handler when a user double-clicks an associated message in the error tab.

## Parameters

### `hWndParent` [in]

Type: **HWND**

A handle to the parent **HWND** that a registered application should use to display a user interface. This value can be **NULL**.

### `ErrorID` [in]

Type: **REFGUID**

An error identifier that is associated with this error message. This value is passed in the [LogError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-logerror) method.

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, and the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The call is completed successfully. |

## Remarks

Handlers should return as soon as possible from this method, and call the [ShowErrorCompleted](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-showerrorcompleted) method. A handler can make a call to
**ShowErrorCompleted** before returning from this method. If a handler returns a failure code from this method, it should not call the
**ShowErrorCompleted** method.

Applications can display user interface elements in this method even if the
[SYNCMGRFLAG_MAYBOTHERUSER](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag) flag is not set in the *dwSyncFlags* parameter of the
[ISyncMgrSynchronize::Initialize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-initialize) method. Applications must still call [EnableModeless](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-enablemodeless), and check the return code before showing a user interface.

## See also

[EnableModeless](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-enablemodeless)

[ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize)

[ISyncMgrSynchronize::Initialize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-initialize)

[LogError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-logerror)

[SYNCMGRFLAG](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag)

[ShowErrorCompleted](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-showerrorcompleted)