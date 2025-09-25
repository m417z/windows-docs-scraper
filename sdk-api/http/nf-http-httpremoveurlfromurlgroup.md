# HttpRemoveUrlFromUrlGroup function

## Description

The **HttpRemoveUrlFromUrlGroup** function removes the specified URL from the group identified by the URL Group ID. This function removes one, or all, of the URLs from the group.

This function replaces the HTTP version 1.0 [HttpRemoveUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurl) function.

## Parameters

### `UrlGroupId` [in]

The ID of the URL group from which the URL specified in *pFullyQualifiedUrl* is removed.

### `pFullyQualifiedUrl` [in]

A pointer to a Unicode string that contains a properly formed [UrlPrefix String](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings) that identifies the URL to be removed.

When **HTTP_URL_FLAG_REMOVE_ALL** is passed in the *Flags* parameter, all of the existing URL registrations for the URL Group identified in *UrlGroupId* are removed from the group. In this case, *pFullyQualifiedUrl* must be **NULL**.

### `Flags` [in]

The URL flags qualifying the URL that is removed. This can be one of the following flags:

| URL Flag | Meaning |
| --- | --- |
| **HTTP_URL_FLAG_REMOVE_ALL** | Removes all of the URLs currently registered with the URL Group. |

## Return value

If the function succeeds, it returns NO_ERROR.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The URL Group does not exist.<br><br>The Flags parameter contains an invalid combination of flags.<br><br>The HTTP_URL_FLAG_REMOVE_ALL flag was set and the *pFullyQualifiedUrl* parameter was not set to **NULL**.<br><br>The application does not have permission to remove URLs from the Group. Only the application that created the URL Group can remove URLs. |
| **ERROR_ACCESS_DENIED** | The calling process does not have permission to deregister the URL. |
| **ERROR_FILE_NOT_FOUND** | The specified URL is not registered with the URL Group. |

## Remarks

The HTTP Server API supports existing applications using the version 1.0 URL registrations, however, new development with the HTTP Server API should use **HttpRemoveUrlFromUrlGroup**; do not use [HttpRemoveUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurl).

Applications should remove the URL added to the group by [HttpAddUrlToUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurltourlgroup), when the URL is no longer required.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpAddUrlToUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurltourlgroup)

[HttpCloseUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseurlgroup)

[HttpCreateUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateurlgroup)

[HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty)

[HttpRemoveUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurl)

[HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty)