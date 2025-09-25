# ResUtilVerifyService function

## Description

Checks if a [service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly) identified by a handle is starting or currently running. The **PRESUTIL_VERIFY_SERVICE** type defines a pointer to this function.

## Parameters

### `hServiceHandle` [in]

Handle of the service to verify.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_SERVICE_NOT_ACTIVE** | The service is not operational. |