# ResUtilSetResourceServiceEnvironment function

## Description

Adjusts the environment data for a [service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly) so that the service uses a cluster network name to identify its location. This function must be called from a [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls). The **PRESUTIL_SET_RESOURCE_SERVICE_ENVIRONMENT** type defines a pointer to this function.

## Parameters

### `pszServiceName` [in]

Pointer a null-terminated Unicode string containing the name of the service.

### `hResource` [in]

Resource handle for the service obtained from [OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource).

### `pfnLogEvent` [in]

Pointer to the [LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) entry point function of the resource DLL managing the service.

### `hResourceHandle` [in]

Resource handle required by the [LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) entry point function. Use the handle passed to the DLL in the [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine) entry point function.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

**ResUtilSetResourceServiceEnvironment** calls [ResUtilGetEnvironmentWithNetName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetenvironmentwithnetname) and stores the resulting environment block in a registry entry for the service. For more information about the effects of the environment block, see **ResUtilGetEnvironmentWithNetName**.

If your resource DLL manages a service, create a worker thread and use [ResUtilSetResourceServiceStartParameters](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetresourceservicestartparameters) and **ResUtilSetResourceServiceEnvironment** when bringing the service online.

Do not call **ResUtilSetResourceServiceEnvironment** from any resource DLL entry point function. **ResUtilSetResourceServiceEnvironment** can safely be called from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[ResUtilGetEnvironmentWithNetName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetenvironmentwithnetname)