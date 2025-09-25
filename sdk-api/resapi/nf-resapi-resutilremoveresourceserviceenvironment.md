# ResUtilRemoveResourceServiceEnvironment function

## Description

Removes the environment data from a [service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly). This function must be called from a [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls). The **PRESUTIL_REMOVE_RESOURCE_SERVICE_ENVIRONMENT** type defines a pointer to this function.

## Parameters

### `pszServiceName` [in]

Pointer to a null-terminated Unicode string that contains the name of the service.

### `pfnLogEvent` [in]

Pointer to the [LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) entry point function of the resource DLL that manages the service.

### `hResourceHandle` [in]

Resource handle that the [LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) entry point function requires. Use the handle passed to the DLL in the [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine) entry point function.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[ResUtilGetEnvironmentWithNetName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetenvironmentwithnetname)