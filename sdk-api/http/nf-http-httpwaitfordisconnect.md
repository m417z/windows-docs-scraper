# HttpWaitForDisconnect function

## Description

The
**HttpWaitForDisconnect** function notifies the application when the connection to an HTTP client is broken for any reason.

## Parameters

### `RequestQueueHandle` [in]

A handle to the request queue that handles requests from the specified connection. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

**Windows Server 2003 with SP1 and Windows XP with SP2:** The handle to the request queue is created by the [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

### `ConnectionId` [in]

Identifier for the connection to the client computer. This value is returned in the **ConnectionID** member of the
[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure by a call to the
[HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest) function.

### `Overlapped` [in]

For asynchronous calls, set *pOverlapped* to point to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure; for synchronous calls, set it to **NULL**.

A synchronous call blocks until the connection is broken, whereas an asynchronous call immediately returns ERROR_IO_PENDING and the calling application then uses
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or I/O completion ports to determine when the operation is completed. For information about using
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structures for synchronization, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function is used asynchronously, a return value of ERROR_IO_PENDING indicates that the next request is not yet ready and is retrieved later through normal overlapped I/O completion mechanisms.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters is in an unusable form. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))