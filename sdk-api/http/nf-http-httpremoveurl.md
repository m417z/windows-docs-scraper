# HttpRemoveUrl function

## Description

The
**HttpRemoveUrl** function causes the system to stop routing requests that match a specified
[UrlPrefix string](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings) to a specified request queue.

Starting with HTTP Server API Version 2.0, applications should call [HttpRemoveUrlFromUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurlfromurlgroup) to register a URL; **HttpRemoveUrl** should not be used.

## Parameters

### `RequestQueueHandle` [in]

The handle to the request queue from which the URL registration is to be removed. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

**Windows Server 2003 with SP1 and Windows XP with SP2:** The handle to the request queue is created by the [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

### `FullyQualifiedUrl` [in]

A pointer to a
[UrlPrefix string](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings) registered to the specified request queue. This string must be identical to the one passed to
[HttpAddUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurl) to register the UrlPrefix; even a nomenclature change in an IPv6 address is not accepted.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have permission to remove the URL. |
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters is in an unusable form. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_FILE_NOT_FOUND** | The specified UrlPrefix could not be found in the registration database. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HttpAddUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurl)

[HttpRemoveUrlFromUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurlfromurlgroup)