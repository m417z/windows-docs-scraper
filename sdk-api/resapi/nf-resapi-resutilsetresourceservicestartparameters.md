# ResUtilSetResourceServiceStartParameters function

## Description

Adjusts the start parameters of a specified [service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly) so that it will operate correctly as a cluster [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). It must be called from a [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls). The **PRESUTIL_SET_RESOURCE_SERVICE_START_PARAMETERS** type defines a pointer to this function.

## Parameters

### `pszServiceName` [in]

Pointer to a null-terminated Unicode string specifying the name of the service.

### `schSCMHandle` [in]

Handle to the Service Control Manager (SCM) or **NULL**. If **NULL**, the function will attempt to open a handle to the SCM.

### `phService` [in, out]

On input, a **NULL** service handle. On output, handle to the specified service if the call was successful, otherwise **NULL**.

### `pfnLogEvent` [in]

Pointer to the [LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) entry point function of the resource DLL managing the service.

### `hResourceHandle` [in]

Resource handle required by the [LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) entry point function. Use the handle passed to the DLL in the [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine) entry point function.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

**ResUtilSetResourceServiceStartParameters** verifies that the service is not disabled, changes the service configuration to manual start and prevents the service from restarting in response to failure. This allows the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and the resource DLL to control the service.

If your resource DLL manages a service, use **ResUtilSetResourceServiceStartParameters** and [ResUtilSetResourceServiceEnvironment](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetresourceserviceenvironment) before bringing the service online.

## See also

[LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine)

[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)

[Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)

[ResUtilSetResourceServiceEnvironment](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetresourceserviceenvironment)