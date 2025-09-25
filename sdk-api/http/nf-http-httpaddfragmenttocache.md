# HttpAddFragmentToCache function

## Description

The
**HttpAddFragmentToCache** function caches a data fragment with a specified name by which it can be retrieved, or updates data cached under a specified name. Such cached data fragments can be used repeatedly to construct dynamic responses without the expense of disk reads. For example, a response composed of text and three images could be assembled dynamically from four or more cached fragments at the time a request is processed.

## Parameters

### `RequestQueueHandle` [in]

Handle to the request queue with which this cache is associated. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

**Windows Server 2003 with SP1 and Windows XP with SP2:** The handle to the request queue is created by the [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

### `UrlPrefix` [in]

Pointer to a [UrlPrefix string](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings) that the application uses in subsequent calls to
[HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse) to identify this cache entry. The application must have called **HttpAddUrl** previously with the same handle as in the *ReqQueueHandle* parameter, and with either this identical UrlPrefix string or a valid prefix of it.

Like any UrlPrefix, this string must take the form "scheme://host:port/relativeURI"; for example, `http://www.mysite.com:80/image1.gif`.

### `DataChunk` [in]

Pointer to an
[HTTP_DATA_CHUNK](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_data_chunk) structure that specifies an entity body data block to cache under the name pointed to by *pUrlPrefix*.

### `CachePolicy` [in]

Pointer to an
[HTTP_CACHE_POLICY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_cache_policy) structure that specifies how this data fragment should be cached.

### `Overlapped` [in, optional]

For asynchronous calls, set *pOverlapped* to point to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure, or for synchronous calls, set it to **NULL**.

A synchronous call blocks the calling thread until the cache operation is complete, whereas an asynchronous call immediately returns ERROR_IO_PENDING and the calling application then uses
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or I/O completion ports to determine when the operation is completed. For more information about using
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structures for synchronization, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function is used asynchronously, a return value of ERROR_IO_PENDING indicates that the cache request is queued and will complete later through normal overlapped I/O completion mechanisms.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters is in an unusable form. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HttpFlushResponseCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpflushresponsecache)

[HttpReadFragmentFromCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreadfragmentfromcache)