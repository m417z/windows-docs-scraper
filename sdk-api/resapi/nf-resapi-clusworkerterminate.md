## Description

Terminates a worker thread. The [PCLUSAPI_CLUS_WORKER_TERMINATE](https://learn.microsoft.com/windows/win32/api/resapi/nc-resapi-pclusapi_clus_worker_terminate) type defines a pointer to this function.

## Parameters

### `lpWorker`

Pointer to a [CLUS_WORKER](https://learn.microsoft.com/windows/win32/api/resapi/ns-resapi-clus_worker) structure describing the thread to terminate.

## Remarks

This function has no return values.

The **ClusWorkerTerminate** utility function checks the *hThread* and *Terminate* members of the **CLUS_WORKER** structure pointed to by *lpWorker*. If *hThread* is not NULL and *Terminate* is set to FALSE, indicating that this is your first call to **ClusWorkerTerminate**, the function waits for the thread to exit before returning. Otherwise, if you have called **ClusWorkerTerminate** previously, indicated by *Terminate* being set to TRUE, the function may return before the thread has terminated.

## See also

[CLUS_WORKER](https://learn.microsoft.com/windows/win32/api/resapi/ns-resapi-clus_worker)
[ClusWorkerCreate](https://learn.microsoft.com/windows/win32/api/resapi/nf-resapi-clusworkercreate)
[ClusWorkerCheckTerminate](https://learn.microsoft.com/windows/win32/api/resapi/nf-resapi-clusworkercheckterminate)
[ClusWorkerTerminateEx](https://learn.microsoft.com/windows/win32/api/resapi/nf-resapi-clusworkerterminateex)
[ClusWorkersTerminate](https://learn.microsoft.com/windows/win32/api/resapi/nf-resapi-clusworkersterminate)