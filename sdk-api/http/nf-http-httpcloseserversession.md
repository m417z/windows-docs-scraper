# HttpCloseServerSession function

## Description

The **HttpCloseServerSession** function deletes the server session identified by the server session ID. All remaining URL Groups associated with the server session will also be closed.

## Parameters

### `ServerSessionId` [in]

The ID of the server session that is closed.

## Return value

If the function succeeds, it returns **NO_ERROR**

If the function fails, it can return one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The Server Session does not exist.<br><br>The application does not have permission to close the server session. Only the application that created the server session can close the session. |

## Remarks

Applications must call [HttpCloseUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseurlgroup) before calling **HttpCloseServerSession** to close the all the URL Groups associated with the server session.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpCloseServerSession](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseserversession)

[HttpCreateServerSession](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateserversession)

[HttpQueryServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserversessionproperty)

[HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty)