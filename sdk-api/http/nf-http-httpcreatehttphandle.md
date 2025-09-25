# HttpCreateHttpHandle function

## Description

The
**HttpCreateHttpHandle** function creates an HTTP request queue for the calling application and returns a handle to it.

Starting with HTTP Server API Version 2.0, applications should call [HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) to create the request queue; **HttpCreateHttpHandle** should not be used.

## Parameters

### `RequestQueueHandle` [out]

A pointer to a variable that receives a handle to the request queue.

### `Reserved` [in]

Reserved. This parameter must be zero.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_DLL_INIT_FAILED** | The calling application did not call [HttpInitialize](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpinitialize) before calling this function. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## Remarks

The request queue enables the calling application to receive requests for particular URLs. The calling application uses the
[HttpAddUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurl) function to specify the URL for which it should receive requests.

An application should use a single request queue to receive requests. Using multiple request queues from a single process does not increase response time or throughput.

When an application has finished receiving requests, it should call the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle.

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HttpAddUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurl)

[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue)