# ResUtilTerminateServiceProcessFromResDll function

## Description

Attempts to terminate the process of a service being managed as a cluster resource by a resource DLL. The **PRESUTIL_TERMINATE_SERVICE_PROCESS_FROM_RES_DLL** type defines a pointer to this function.

## Parameters

### `dwServicePid` [in]

The process ID of the service process to terminate.

### `bOffline` [in]

Indicates whether the resource is being taken offline or is being terminated. Specify
**TRUE** if calling from the Offline entry point or from a worker thread created to take
the resource offline. Otherwise specify **FALSE** and the function will assume you are
terminating the resource.

### `pdwResourceState` [out, optional]

Optional pointer to a **DWORD** which returns the resulting state of the resource,
which will be either **ClusterResourceFailed** or
**ClusterResourceOffline** (for a complete list of resource states see
[GetClusterResourceState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterresourcestate)). Pass
**NULL** if you don't need this information.

### `pfnLogEvent` [in]

Pointer to the [LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) function used by your resource
DLL. This pointer is passed to your resource DLL in the
[Startup](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pstartup_routine) entry point.

### `hResourceHandle` [in]

The Resource Monitor's handle to the resource. This handle is passed to your resource DLL in the
[Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine) entry point and must be saved as part of the resource's
[instance data](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/instance-data).

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the
operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

Note that
**ResUtilTerminateServiceProcessFromResDll**
uses *pfnLogEvent* and *hResourceHandle* to write to your
resource DLL's event log, which may help troubleshoot failures.

## Remarks

You should only call
**ResUtilTerminateServiceProcessFromResDll**
when terminating a resource or when taking a resource offline.

## See also

[Service Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/service-utility-functions)