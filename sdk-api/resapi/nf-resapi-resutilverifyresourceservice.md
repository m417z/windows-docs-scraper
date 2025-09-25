# ResUtilVerifyResourceService function

## Description

Verifies that a named [service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly) is starting or currently running. The **PRESUTIL_VERIFY_RESOURCE_SERVICE** type defines a pointer to this function.

## Parameters

### `pszServiceName` [in]

Null-terminated Unicode string containing the name of the service to verify.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_SERVICE_NOT_ACTIVE** | The service is not operational. |