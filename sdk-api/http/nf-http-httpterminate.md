# HttpTerminate function

## Description

The
**HttpTerminate** function cleans up resources used by the HTTP Server API to process calls by an application. An application should call
**HttpTerminate** once for every time it called
[HttpInitialize](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpinitialize), with matching flag settings.

## Parameters

### `Flags` [in]

Termination options. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **HTTP_INITIALIZE_CONFIG** | Release all resources used by applications that modify the HTTP configuration. |
| **HTTP_INITIALIZE_SERVER** | Release all resources used by server applications. |

### `pReserved` [in, out]

This parameter is reserved and must be **NULL**.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters is in an unusable form. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## Remarks

Every call to
[HttpInitialize](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpinitialize) should be matched by a corresponding call to
**HttpTerminate**. For example, if you call
**HttpInitialize** with HTTP_INITIALIZE_SERVER, you must call
**HttpTerminate** with HTTP_INITIALIZE_SERVER. If you call
**HttpInitialize** twice, once with HTTP_INITIALIZE_SERVER and the second time with HTTP_INITIALIZE_CONFIG, you can call
**HttpTerminate** one time with both flags.

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HttpInitialize](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpinitialize)