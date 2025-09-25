# ClusWorkersTerminate function

## Description

Waits for multiple worker threads to terminate up to the specified timeout. This function can signal the thread to terminate before wait starts, or just wait passively if specified.

## Parameters

### `ClusWorkers` [in, out]

Pointer to an array of [CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker) structures describing the
threads to terminate.

### `ClusWorkersCount` [in]

The number of structures in the *ClusWorkers* parameter.

### `TimeoutInMilliseconds` [in]

The timeout in milliseconds.

### `WaitOnly` [in]

If set **TRUE**, the function will wait for up to specified timeout without signaling the thread to terminate; otherwise it will signal the thread to terminate before waiting for the thread.

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | All worker threads are terminated. |
| **WAIT_TIMEOUT** | At least one worker thread is not terminated within the specified timeout. |

Returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) on failure.

## See also

[CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker)

[ClusWorkerCheckTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercheckterminate)

[ClusWorkerCreate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercreate)

[ClusWorkerTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkerterminate)

[ClusWorkerTerminateEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-clusworkerterminateex)

[Thread Management Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/thread-management-utility-functions)