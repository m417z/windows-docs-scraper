# ISyncMgrSynchronize::PrepareForSync

## Description

Allows a registered application to display any user interface, and perform any necessary initialization before the [ISyncMgrSynchronize::Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) method is called. For example, an application such as the Microsoft Outlook email client may need to display the password dialog box to enable a user to log on to a mail server.

## Parameters

### `cbNumItems` [in]

Type: **ULONG**

The number of items in the array pointed to by *pItemIDs*.

### `pItemIDs` [in]

Type: **GUID***

An array of item IDs that a user chooses to synchronize.

### `hWndParent` [in]

Type: **HWND**

A handle to the parent **HWND** that a registered application should use for any user interface element displayed. This value may be **NULL**.

### `dwReserved` [in]

Type: **DWORD**

Reserved. Registered applications should ignore this value.

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, and the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Preparation is successful. |

## Remarks

A registered application handler should return from this method as soon as possible, and then call the [PrepareForSyncCompleted](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-prepareforsynccompleted) method. A registered application handler can call the **PrepareForSyncCompleted** method before returning from this method.

Registered applications should only show a user interface if the
[SYNCMGRFLAG_MAYBOTHERUSER](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag) flag is set in the *dwSyncFlags* parameter of the
[ISyncMgrSynchronize::Initialize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-initialize) method. If a registered application cannot prepare for synchronization without showing a user interface when the [SYNCMGRFLAG_MAYBOTHERUSER](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag) flag is not set, it should return S_FALSE from this method.

The array of item IDs that are passed into this method are relevant to the [ISyncMgrSynchronize::Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) method also.

The [ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback) methods can be called on any thread in a registered application.

## See also

[ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize)

[ISyncMgrSynchronize::Initialize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-initialize)

[ISyncMgrSynchronize::Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize)

[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)

[PrepareForSyncCompleted](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-prepareforsynccompleted)

[SYNCMGRFLAG](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag)