# HttpCreateServerSession function

## Description

The **HttpCreateServerSession** function creates a server session for the specified version.

## Parameters

### `Version` [in]

An HTTPAPI_VERSION structure that indicates the version of the server session. For version 2.0, declare an instance of the structure and set it to the predefined value **HTTPAPI_VERSION_2** before passing it to **HttpCreateServerSession**.

The version must be 2.0; **HttpCreateServerSession** does not support version 1.0 request queues.

### `ServerSessionId` [out]

A pointer to the variable that receives the ID of the server session.

### `Reserved` [in]

Reserved. Must be zero.

## Return value

If the function succeeds, it returns **NO_ERROR**.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_REVISION_MISMATCH** | The version passed is invalid or unsupported. |
| **ERROR_INVALID_PARAMETER** | The *pServerSessionId* parameter is null or the *Reserved* is non zero. |

## Remarks

Server sessions own a set of URL Groups. They are top-level configuration containers for configuration information that applies to all of the URL Groups created under them. For more information about configuring a server session, see [HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty).

The HTTP Server API does not support asynchronous I/O for server sessions.

 When the server session is no longer required, or before the application terminates, application must delete the server session by calling [HttpCloseServerSession](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseserversession). When a server session is deleted all of the associated URL Groups are also automatically deleted.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpCloseServerSession](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseserversession)

[HttpCreateServerSession](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateserversession)

[HttpQueryServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserversessionproperty)

[HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty)