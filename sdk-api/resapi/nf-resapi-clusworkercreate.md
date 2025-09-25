# ClusWorkerCreate function

## Description

Creates a worker thread. The **PCLUSAPI_CLUS_WORKER_CREATE** type defines a pointer to this function.

## Parameters

### `lpWorker` [out]

Pointer to a
zero-initialized [CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker) structure that on return is filled in with a handle to the created thread and a flag that indicates whether the handle should be terminated. The caller should never need to refer to or change the members of this structure.

### `lpStartAddress` [in]

Pointer to the address of a function that should be called by the worker thread.

### `lpParameter` [in]

A parameter to pass to the function whose address is pointed to by *lpStartAddress*.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker)

[ClusWorkerCheckTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercheckterminate)

[ClusWorkerTerminate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkerterminate)