# CLUS_WORKER structure

## Description

Contains information about a worker thread.

## Members

### `hThread`

Handle to the worker thread.

### `Terminate`

Flag that indicates whether the thread is to be terminated.

## Remarks

A worker thread is a thread that is created to offload work from a main thread so that the main thread is not blocked.

A **CLUS_WORKER** structure is returned as output from [ClusWorkerCreate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercreate) and passed as input to [ClusWorkerCheckTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercheckterminate) and [ClusWorkerTerminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclusapi_clus_worker_terminate). There is never any reason for an application or [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) to alter the members of a **CLUS_WORKER** structure. This structure should always be treated as read-only.

The
**Terminate** member prevents a potential race condition that can occur if multiple threads call the [ClusWorkerTerminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclusapi_clus_worker_terminate) function to end the same worker thread. The first call sets
**Terminate** to **TRUE**. Subsequent calls return immediately after checking the value of
**Terminate** without waiting for the thread to exit.

## See also

[ClusWorkerCheckTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercheckterminate)

[ClusWorkerCreate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercreate)

[ClusWorkerTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkerterminate)