# PWORKER_START_ROUTINE callback function

## Description

Initializes a worker thread with the specified callback routine. The **PWORKER_START_ROUTINE** type defines a pointer to this function.

## Parameters

### `pWorker` [in]

A pointer to the [CLUS_WORKER](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clus_worker) structure that represents the worker thread.

### `lpThreadParameter` [in]

A pointer to the callback routine to use to initialize the worker thread.

## Return value

Returns **ERROR_SUCCESS** (0), if the operation succeeds; otherwise returns a system error code.

## Remarks

The pointer to this callback function is used as an input parameter for the [ClusWorkerCreate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercreate) function.

## See also

[ClusWorkerCreate](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-clusworkercreate)

[Resource DLL Callback Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-callback-functions)