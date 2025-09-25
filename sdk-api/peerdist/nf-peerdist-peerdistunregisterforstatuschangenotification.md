# PeerDistUnregisterForStatusChangeNotification function

## Description

The **PeerDistUnregisterForStatusChangeNotification** function unregisters the status change notification for the session associated with the specified handle.

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* handle is invalid. |

## Remarks

This function cancels any registered notification previously set by a [PeerDistRegisterForStatusChangeNotification](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistregisterforstatuschangenotification) function call.

To confirm successfully canceled operations, a call should be made to [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult) using the **OVERLAPPED** structure returned by [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) with an expected return of **FALSE**.

Additionally, calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) immediately after a successful [PeerDistRegisterForStatusChangeNotification](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistregisterforstatuschangenotification) will return the **ERROR_OPERATION_ABORTED** error code.

## See also

[PeerDistRegisterForStatusChangeNotification](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistregisterforstatuschangenotification)