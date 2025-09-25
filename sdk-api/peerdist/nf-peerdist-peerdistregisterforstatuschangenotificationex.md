# PeerDistRegisterForStatusChangeNotificationEx function

## Description

The **PeerDistRegisterForStatusChangeNotificationEx** function requests the Peer Distribution service status change notification.

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `hCompletionPort` [in, optional]

A handle to the completion port that can be used for retrieving the completion notification of the asynchronous function. To create a completion port, use the [CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport) function. This parameter can be **NULL**.

### `ulCompletionKey` [in, optional]

Value to be returned through the *lpCompletionKey* parameter of the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function. This parameter is ignored when *hCompletionPort* is **NULL**.

### `lpOverlapped` [in]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. If the **hEvent** member of the structure is not **NULL**, it will be signaled via SetEvent() used in order to signal the notification. This can occur even if the completion port is specified via the *hCompletionPort* argument.

### `pPeerDistStatus` [in, out]

A pointer to a [PEERDIST_STATUS_INFO](https://learn.microsoft.com/windows/desktop/api/peerdist/ns-peerdist-peerdist_status_info) structure that contains the current status and capabilities of the Peer Distribution service.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

## Remarks

This function optionally registers a completion port and an [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure for status change notification. Upon successful completion, the *pPeerDistStatus* parameter will contain a valid **PEERDIST_STATUS** value.

Only one active registration for each session is allowed. The caller must register for notification each time after it signals. The notification will be sent only if the current status is changed from the previous notification. After the first call of the [PeerDistRegisterForStatusChangeNotification](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistregisterforstatuschangenotification) function for the Peer Distribution session, the first notification will trigger only if the status is no longer equal to **PEERDIST_STATUS_DISABLED**.

A Peer Distribution status change can result in the Peer Distribution service moving to an available, unavailable, or disabled state. If the new status is disabled or unavailable, the content, content information, or stream handles the caller has access to will no longer function. In this case, any API that uses these handles will fail with error **PEERDIST_ ERROR_INVALIDATED**. The caller must explicitly close the handles by calling the appropriate Peer Distribution API.

## See also

[CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[PEERDIST_STATUS](https://learn.microsoft.com/windows/desktop/api/peerdist/ne-peerdist-peerdist_status)

[PeerDistServerCloseContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverclosecontentinformation)

[PeerDistServerRetrieveContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverretrievecontentinformation)

[PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup)