# ClusWorkerTerminateEx function

## Description

Waits for a worker thread to terminate up to the specified timeout. This function can signal the thread to terminate before wait starts, or just wait passively if specified.

## Parameters

### `ClusWorker` [in, out]

Pointer to a [CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker) structure describing the
worker thread to terminate.

### `TimeoutInMilliseconds` [in]

The timeout in milliseconds.

### `WaitOnly` [in]

If set **TRUE**, the function will wait for up to specified timeout without signaling the thread to terminate; otherwise it will signal the thread to terminate before waiting for the thread.

## Return value

Returns a system error code on failure.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | All worker threads are terminated. |
| **WAIT_TIMEOUT** | The worker thread is not terminated within the specified timeout. |

## See also

[CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker)

[ClusWorkerCheckTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercheckterminate)

[ClusWorkerCreate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercreate)

[ClusWorkerTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkerterminate)

[ClusWorkersTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkersterminate)

[Thread Management Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/thread-management-utility-functions)