# HttpFlushResponseCache function

## Description

The
**HttpFlushResponseCache** function removes from the HTTP Server API cache associated with a given request queue all response fragments that have a name whose site portion matches a specified UrlPrefix. The application must previously have called [HttpAddUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurl), or [HttpAddUrlToUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurltourlgroup) to add this UrlPrefix or a valid prefix of it to the request queue in question, and then called [HttpAddFragmentToCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddfragmenttocache) to cache the associated response fragment or fragments.

## Parameters

### `RequestQueueHandle` [in]

Handle to the request queue with which this cache is associated. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

**Windows Server 2003 with SP1 and Windows XP with SP2:** The handle to the request queue is created by the [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

### `UrlPrefix` [in]

Pointer to a
[UrlPrefix string](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings) to match against the site portion of fragment names. The application must previously have called [HttpAddUrl](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurl) to add this UrlPrefix or a valid prefix of it to the request queue in question, and then called [HttpAddFragmentToCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddfragmenttocache) to cache the associated response fragment.

### `Flags` [in]

This parameter can contain the following flag:

#### HTTP_FLUSH_RESPONSE_FLAG_RECURSIVE

Causes response fragments that have names in which the site portion is a hierarchical descendant of the specified UrlPrefix to be removed from the fragment cache, in addition to those fragments having site portions that directly match.

### `Overlapped` [in]

For asynchronous calls, set *pOverlapped* to point to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure, or for synchronous calls, set it to **NULL**.

A synchronous call blocks until the cache operation is complete, whereas an asynchronous call immediately returns ERROR_IO_PENDING and the calling application then uses
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or I/O completion ports to determine when the operation is completed. For more information about using
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structures for synchronization, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function is used asynchronously, a return value of ERROR_IO_PENDING indicates that the cache request is queued and completes later through normal overlapped I/O completion mechanisms.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters are invalid. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HttpAddFragmentToCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddfragmenttocache)

[HttpReadFragmentFromCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreadfragmentfromcache)