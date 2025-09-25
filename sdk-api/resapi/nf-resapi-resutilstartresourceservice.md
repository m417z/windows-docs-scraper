# ResUtilStartResourceService function

## Description

Starts a [service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly). The **PRESUTIL_START_RESOURCE_SERVICE** type defines a pointer to this function.

## Parameters

### `pszServiceName` [in]

Null-terminated Unicode string containing the name of the service to start.

### `phServiceHandle` [out]

Optional pointer to a handle in which the handle to the started service is returned. This handle must be closed either by a call to the cluster utility function [ResUtilStopService](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilstopservice) or the function [CloseServiceHandle](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-closeservicehandle).

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_SERVICE_NEVER_STARTED** | The service was not started. |

## Remarks

The **ResUtilStartResourceService** utility function encapsulates the necessary calls to the service control manager, providing a convenient way to start services in the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). Using **ResUtilStartResourceService** is optional. If the service to be started requires specific access restrictions or other special handling, use the service control manager functions instead.

## See also

[ResUtilStopService](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilstopservice)