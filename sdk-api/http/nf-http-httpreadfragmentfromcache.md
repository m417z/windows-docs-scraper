# HttpReadFragmentFromCache function

## Description

The
**HttpReadFragmentFromCache** function retrieves a response fragment having a specified name from the HTTP Server API cache.

## Parameters

### `RequestQueueHandle` [in]

Handle to the request queue with which the specified response fragment is associated. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

**Windows Server 2003 with SP1 and Windows XP with SP2:** The handle to the request queue is created by the [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

### `UrlPrefix` [in]

Pointer to a [UrlPrefix string](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings) that contains the name of the fragment to be retrieved. This must match a UrlPrefix string used in a previous successful call to [HttpAddFragmentToCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddfragmenttocache).

### `ByteRange` [in]

Optional pointer to an
[HTTP_BYTE_RANGE](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_byte_range) structure that indicates a starting offset in the specified fragment and byte-count to be returned. **NULL** if not used, in which case the entire fragment is returned.

### `Buffer` [out]

Pointer to a buffer into which the function copies the requested fragment.

### `BufferLength` [in]

Size, in bytes, of the *pBuffer* buffer.

### `BytesRead` [out]

Optional pointer to a variable that receives the number of bytes to be written into the output buffer. If *BufferLength* is less than this number, the call fails with a return of ERROR_INSUFFICIENT_BUFFER, and the value pointed to by *pBytesRead* can be used to determine the minimum length of buffer required for the call to succeed.

When making an asynchronous call using *pOverlapped*, set *pBytesRead* to **NULL**. Otherwise, when *pOverlapped* is set to **NULL**, *pBytesRead* must contain a valid memory address, and not be set to **NULL**.

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
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters is in an unusable form. |
| **ERROR_MORE_DATA** | The buffer pointed to by *pBuffer* is too small to receive all the requested data; the size of buffer required is pointed to by *pBytesRead* unless it was **NULL** or the call was asynchronous. In the case of an asynchronous call, the value pointed to by the *lpNumberOfBytesTransferred* parameter of the [GetOverLappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function is set to the buffer size required. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HttpAddFragmentToCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddfragmenttocache)

[HttpFlushResponseCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpflushresponsecache)