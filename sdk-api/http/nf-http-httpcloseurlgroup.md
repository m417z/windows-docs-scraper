# HttpCloseUrlGroup function

## Description

The **HttpCloseUrlGroup** function closes the URL Group identified by the URL Group ID. This call also removes all of the URLs that are associated with the URL Group.

## Parameters

### `UrlGroupId` [in]

The ID of the URL Group that is deleted.

## Return value

If the function succeeds, it returns **NO_ERROR**.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The ID of the URL Group does not exist.<br><br>The application does not have permission to close the URL Group. Only the application that created the URL Group can close the group. |

## Remarks

Applications must call **HttpCloseUrlGroup** before calling [HttpCloseServerSession](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseserversession) to close the all URL Groups associated with the server session.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpAddUrlToUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurltourlgroup)

[HttpCreateUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateurlgroup)

[HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty)

[HttpRemoveUrlFromUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurlfromurlgroup)

[HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty)