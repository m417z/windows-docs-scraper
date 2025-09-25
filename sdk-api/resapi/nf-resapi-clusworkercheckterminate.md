# ClusWorkerCheckTerminate function

## Description

Determines whether a worker thread should exit as soon as possible. The **PCLUSAPIClusWorkerCheckTerminate** type defines a pointer to this function.

## Parameters

### `lpWorker` [in]

Pointer to a [CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker) structure describing the
thread to check.

## Return value

**ClusWorkerCheckTerminate** returns one of
the following values.

| Return code/value | Description |
| --- | --- |
| **TRUE**<br><br>1 | The thread should terminate. |
| **FALSE**<br><br>0 | The thread should not terminate. |

## Remarks

The **ClusWorkerCheckTerminate** utility
function checks the **Terminate** member of the
[CLUS_WORKER](https://learn.microsoft.com/windows/desktop/api/resapi/ns-resapi-clus_worker) structure to determine whether the thread
pointed to by Worker should exit. The **Terminate** member is used to prevent problems from occurring when multiple threads call
[ClusWorkerTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkerterminate) on the same worker thread.

## See also

[CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker)

[ClusWorkerCreate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercreate)

[ClusWorkerTerminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclusapi_clus_worker_terminate)

[Thread Management Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/thread-management-utility-functions)