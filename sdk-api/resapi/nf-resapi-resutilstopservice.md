# ResUtilStopService function

## Description

Stops a [service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly) identified by a handle. The **PRESUTIL_STOP_SERVICE** type defines a pointer to this function.

## Parameters

### `hServiceHandle` [in]

Handle of the service to stop.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_TIMEOUT** | Service did not stop after a reasonable number of retries. |

## Remarks

The **ResUtilStopService** utility function closes the handle specified in *hServiceHandle* when it stops the service.