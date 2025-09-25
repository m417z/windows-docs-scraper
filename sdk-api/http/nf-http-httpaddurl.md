# HttpAddUrl function

## Description

The
**HttpAddUrl** function registers a given URL so that requests that match it are routed to a specified HTTP Server API request queue. An application can register multiple URLs to a single request queue using repeated calls to
**HttpAddUrl**. For more information about how HTTP Server API matches request URLs to registered URLs, see
[UrlPrefix Strings](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings).

Starting with HTTP Server API Version 2.0, applications should call [HttpAddUrlToUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurltourlgroup) to register a URL; **HttpAddUrl** should not be used.

## Parameters

### `RequestQueueHandle` [in]

The handle to the request queue to which requests for the specified URL are to be routed. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

**Windows Server 2003 with SP1 and Windows XP with SP2:** The handle to the request queue is created by the [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

### `FullyQualifiedUrl` [in]

A pointer to a Unicode string that contains a properly formed
[UrlPrefix string](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings) that identifies the URL to be registered.

### `Reserved`

Reserved; must be **NULL**.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have permission to register the URL. |
| **ERROR_DLL_INIT_FAILED** | The calling application did not call [HttpInitialize](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpinitialize) before calling this function. |
| **ERROR_INVALID_PARAMETER** | One of the parameters are invalid. |
| **ERROR_ALREADY_EXISTS** | The specified UrlPrefix conflicts with an existing registration. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## Remarks

As stated in the [UrlPrefix Strings](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings) topic, the scheme specification of the UrlPrefix to be registered must be either lower-case "http" or lower-case "https". No other substring is valid.

Also, it is not possible to register URLs having different schemes on the same port. That is, "http" and "https" schemes cannot coexist on a port.

Also be aware that
**HttpAddUrl** registers any UrlPrefix passed to it as long as the string is well-formed. Any validation of existence, accessibility, ownership, or other characteristic of the specified URL namespace must be handled by the application.

To release the resources allocated as a result of the registration performed by
**HttpAddUrl**, make a matching call to the
[HttpRemoveUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurl) function when your application has finished with the namespace involved.

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HttpAddUrlToUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurltourlgroup)

[HttpRemoveUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurl)