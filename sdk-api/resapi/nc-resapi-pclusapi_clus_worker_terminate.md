# PCLUSAPI_CLUS_WORKER_TERMINATE callback function

## Description

Terminates a worker thread. The **PCLUSAPI_CLUS_WORKER_TERMINATE** type defines a pointer to this function.

## Parameters

### `lpWorker` [in]

Pointer to a [CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker) structure describing the
thread to terminate.

## Remarks

The *ClusWorkerTerminate* utility function checks
the **hThread** and **Terminate** members of the
[CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker) structure pointed to by
*lpWorker*. If **hThread** is not **NULL**
and **Terminate** is set to **FALSE**, indicating that this is your
first call to *ClusWorkerTerminate*, the function
waits for the thread to exit before returning. Otherwise, if you have called
*ClusWorkerTerminate* previously, indicated by
**Terminate** being set to **TRUE**, the function may return before
the thread has terminated.

## See also

[CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker)

[ClusWorkerCheckTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercheckterminate)

[ClusWorkerCreate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercreate)

[ClusWorkerTerminateEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-clusworkerterminateex)

[ClusWorkersTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkersterminate)

[Thread Management Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/thread-management-utility-functions)