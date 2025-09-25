# ISyncMgrSynchronize::Initialize

## Description

Called by the synchronization manager in a registered application handler to determine whether the handler processes the synchronization event.

## Parameters

### `dwReserved` [in]

Type: **DWORD**

Reserved; must be 0 (zero).

### `dwSyncMgrFlags` [in]

Type: **DWORD**

The [SYNCMGRFLAG](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag) enumeration values that describe how a synchronization event is initiated.

### `cbCookie` [in]

Type: **DWORD**

The size of the *lpCookie* data, in bytes.

### `lpCookie` [in]

Type: **BYTE const***

A pointer to the token that identifies an application. This token is passed when an application invokes the synchronization manager programmatically.

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, and the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Initialization is successful. |
| **S_FALSE** | Application handler does not process a synchronization event. |

## Remarks

The [SYNCMGRFLAG](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag) enumeration values apply through the lifetime of the [ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize) interface, and are used by the other
**ISyncMgrSynchronize** methods.

If an application does not recognize the [SYNCMGRFLAG](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag) event, the application should treat the event as a manual synchronization.

A registered application handler cannot display a user interface within this call unless it is the first time the initialization method is called. An application can display any one-time initialization it needs to set up items and introduce a user to an application feature. If you need to display a user interface for a different reason as part of the synchronization process, you can use the [ISyncMgrSynchronize::PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) method.

The *lpCookie* parameter is **NULL** unless a handling application invokes the synchronization manager programmatically by using [UpdateItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizeinvoke-updateitems). In this scenario, the class identifier (CLSID) identifies the handling application, and the value of *lpCookie* is passed in by the handling application, and then passed back by the synchronization manager during synchronization for context. The *lpCookie* parameter is only meaningful when [SYNCMGRFLAG_INVOKE](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag) is set.

## See also

[ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize)

[ISyncMgrSynchronize::PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync)

[SYNCMGRFLAG](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag)

[UpdateItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizeinvoke-updateitems)