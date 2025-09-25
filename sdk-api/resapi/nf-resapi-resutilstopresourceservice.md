# ResUtilStopResourceService function

## Description

Stops a named [service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly). The **PRESUTIL_STOP_RESOURCE_SERVICE** type defines a pointer to this function.

## Parameters

### `pszServiceName` [in]

Null-terminated Unicode string containing the name of the service to stop.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_TIMEOUT** | Service did not stop after a reasonable number of retries. |

## See also

[ResUtilStartResourceService](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilstartresourceservice)