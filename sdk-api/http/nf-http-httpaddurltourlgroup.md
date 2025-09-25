# HttpAddUrlToUrlGroup function

## Description

The **HttpAddUrlToUrlGroup** function adds the specified URL to the URL Group identified by the URL Group ID.

 This function replaces the HTTP version 1.0 [HttpAddUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurl) function.

## Parameters

### `UrlGroupId` [in]

The group ID for the URL group to which requests for the specified URL are routed. The URL group is created by the [HttpCreateUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateurlgroup) function.

### `pFullyQualifiedUrl` [in]

A pointer to a Unicode string that contains a properly formed [UrlPrefix String](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings) that identifies the URL to be registered. If you are not running as an administrator, specify a port number greater than 1024, otherwise you may get an ERROR_ACCESS_DENIED error.

### `UrlContext` [in, optional]

The context that is associated with the URL registered in this call. The URL context is returned in the [HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure with every request received on the URL specified in the *pFullyQualifiedUrl* parameter.

### `Reserved` [in]

Reserved. Must be zero.

## Return value

If the function succeeds, it returns **NO_ERROR**

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *UrlGroupId* does not exist.<br><br> The *Reserved* parameter is not zero.<br><br>The application does not have permission to add URLs to the Group. Only the application that created the URL Group can add URLs. |
| **ERROR_ACCESS_DENIED** | The calling process does not have permission to register the URL. |
| **ERROR_ALREADY_EXISTS** | The specified URL conflicts with an existing registration. |

## Remarks

The HTTP Server API supports existing applications using version 1.0 URL registrations, however, new development with the HTTP Server API should use **HttpAddUrlToUrlGroup**; [HttpAddUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurl) should not be used.

An application can add multiple URLs to a URL group using repeated calls to **HttpAddUrlToUrlGroup**. Requests that match the specified URL are routed to the request queue associated with the URL group. For more information about how the HTTP Server API matches request URLs to registered URLs, see [UrlPrefix Strings](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings).

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpAddUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurl)

[HttpCloseUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseurlgroup)

[HttpCreateUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateurlgroup)

[HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty)

[HttpRemoveUrlFromUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurlfromurlgroup)

[HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty)

[UrlPrefix Strings](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings)