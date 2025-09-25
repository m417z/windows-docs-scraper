# PeerDistServerCancelAsyncOperation function

## Description

The **PeerDistServerCancelAsyncOperation** function cancels the asynchronous operation associated with the content identifier and [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `cbContentIdentifier`

The length, in bytes, of the content identifier.

### `pContentIdentifier` [in]

Pointer to an array that contains the content identifier.

### `pOverlapped` [in]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure that contains the canceling asynchronous operation data.

## Return value

The function will return **ERROR_SUCCESS** value if the operation associated with [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure is successfully canceled. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* handle is invalid. |
| **PEERDIST_ERROR_OPERATION_NOT_FOUND** | The operation for [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure cannot be found. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

This function will synchronously cancel the operation, but will not return until the cancelation result is posted to the completion port or wait event is set to the 'signaled' state. Any threads in waiting can receive the completion notice for the operation before or after the **PeerDistServerCancelAsyncOperation** function returns.

This function does not guarantee that the operation will complete as canceled. The cancellation result will be posted only if no other results have been posted.

To confirm successfully canceled operations, a call should be made to [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult) with an expected return of **FALSE**.

Additionally, calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) immediately after a successful **PeerDistServerCancelAsyncOperation** will return the **ERROR_OPERATION_ABORTED** error code.

## See also

[PeerDistClientCancelAsyncOperation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientcancelasyncoperation)

[PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent)