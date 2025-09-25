# HttpReceiveHttpRequest function

## Description

The
**HttpReceiveHttpRequest** function retrieves the next available HTTP request from the specified request queue either synchronously or asynchronously.

## Parameters

### `RequestQueueHandle` [in]

A handle to the request queue from which to retrieve the next available request. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

**Windows Server 2003 with SP1 and Windows XP with SP2:** The handle to the request queue is created by the [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

### `RequestId` [in]

On the first call to retrieve a request, this parameter should be **HTTP_NULL_ID**. Then, if more than one call is required to retrieve the entire request,
**HttpReceiveHttpRequest** or
[HttpReceiveRequestEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiverequestentitybody) can be called with *RequestID* set to the value returned in the **RequestId** member of the
[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure pointed to by *pRequestBuffer*.

### `Flags` [in]

A parameter that can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0 (zero)** | Only the request headers are retrieved; the entity body is not copied. |
| **HTTP_RECEIVE_REQUEST_FLAG_COPY_BODY** | The available entity body is copied along with the request headers. The **pEntityChunks** member of the [HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure points to the entity body. |
| **HTTP_RECEIVE_REQUEST_FLAG_FLUSH_BODY** | All of the entity bodies are copied along with the request headers. The **pEntityChunks** member of the [HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure points to the entity body. |

### `RequestBuffer` [out]

A pointer to a buffer into which the function copies an
[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure and entity body for the HTTP request. **HTTP_REQUEST.RequestId** contains the identifier for this HTTP request, which the application can use in subsequent calls [HttpReceiveRequestEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiverequestentitybody),
[HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse), or
[HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody).

### `RequestBufferLength` [in]

Size, in bytes, of the *pRequestBuffer* buffer.

### `BytesReturned` [out, optional]

Optional. A pointer to a variable that receives the size, in bytes, of the entity body, or of the remaining part of the entity body.

When making an asynchronous call using *pOverlapped*, set *pBytesReceived* to **NULL**. Otherwise, when *pOverlapped* is set to **NULL**, *pBytesReceived* must contain a valid memory address, and not be set to **NULL**.

### `Overlapped` [in, optional]

For asynchronous calls, set *pOverlapped* to point to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure; for synchronous calls, set it to **NULL**.

A synchronous call blocks until a request has arrived in the specified queue and some or all of it has been retrieved, whereas an asynchronous call immediately returns **ERROR_IO_PENDING** and the calling application then uses
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or I/O completion ports to determine when the operation is completed. For more information about using
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structures for synchronization, see
[Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function is being used asynchronously, a return value of **ERROR_IO_PENDING** indicates that the next request is not yet ready and will be retrieved later through normal overlapped I/O completion mechanisms.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters is in an unusable form. |
| **ERROR_NOACCESS** | One or more of the supplied parameters points to an invalid or unaligned memory buffer. The *pRequestBuffer* parameter must point to a valid memory buffer with a memory alignment equal or greater to the memory alignment requirement for an **HTTP_REQUEST** structure. |
| **ERROR_MORE_DATA** | The value of *RequestBufferLength* is greater than or equal to the size of the request header received, but is not as large as the combined size of the request structure and entity body. The buffer size required to read the remaining part of the entity body is returned in the *pBytesReceived* parameter if this is non-**NULL** and if the call is synchronous. Call the function again with a large enough buffer to retrieve all data. |
| **ERROR_HANDLE_EOF** | The specified request has already been completely retrieved; in this case, the value pointed to by *pBytesReceived* is not meaningful, and *pRequestBuffer* should not be examined. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## Remarks

More than one call can be required to retrieve a given request. When the *Flags* parameter is set to zero, for example,
**HttpReceiveHttpRequest** only copies the request header structure into the buffer, and does not attempt to copy any of the entity body. In this case, the
[HttpReceiveRequestEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiverequestentitybody) function can be used to retrieve the entity body, or a second call can be made to
**HttpReceiveHttpRequest**.

Alternatively, the buffer provided by the application may be insufficiently large to receive all or part of the request. To be sure of receiving at least part of the request, it is recommended that an application provide at least a buffer of 4 KB, which accommodates most HTTP requests. Alternately, authentication headers, parsed as unknown headers, can add up to 12 KB to that, so if authentication/authorization is used, a buffer size of at least 16 KB is recommended.

If
**HttpReceiveHttpRequest** returns **ERROR_MORE_DATA**, the application continues to make additional calls, identifying the request in each additional call by passing in the **HTTP_REQUEST.RequestId** value returned by the first call until **ERROR_HANDLE_EOF** is returned.

**Note** The application must examine all relevant request headers, including content-negotiation headers if used, and fail the request as appropriate based on the header content. **HttpReceiveHttpRequest** ensures only that the header line is properly terminated and does not contain illegal characters.

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))

[HttpReceiveRequestEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiverequestentitybody)

[HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse)

[HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody)