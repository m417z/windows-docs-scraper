# HttpReceiveRequestEntityBody function

## Description

The
**HttpReceiveRequestEntityBody** function receives additional entity body data for a specified HTTP request.

## Parameters

### `RequestQueueHandle` [in]

The handle to the request queue from which to retrieve the specified entity body data. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

**Windows Server 2003 with SP1 and Windows XP with SP2:** The handle to the request queue is created by the [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

### `RequestId` [in]

The identifier of the HTTP request that contains the retrieved entity body. This value is returned in the **RequestId** member of the
[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure by a call to the
[HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest) function. This value cannot be **HTTP_NULL_ID**.

### `Flags` [in]

This parameter can be the following flag value.

**Windows Server 2003 with SP1 and Windows XP with SP2:** This parameter is reserved and must be zero.

| Value | Meaning |
| --- | --- |
| **HTTP_RECEIVE_REQUEST_ENTITY_BODY_FLAG_FILL_BUFFER** | Specifies that the buffer will be filled with one or more entity bodies, unless there are no remaining entity bodies to copy. |

### `EntityBuffer` [out]

A pointer to a buffer that receives entity-body data.

### `EntityBufferLength` [in]

The size, in bytes, of the buffer pointed to by the *pBuffer* parameter.

### `BytesReturned` [out, optional]

Optional. A pointer to a variables that receives the size, in bytes, of the entity body data returned in the *pBuffer* buffer.

When making an asynchronous call using *pOverlapped*, set *pBytesReceived* to **NULL**. Otherwise, when *pOverlapped* is set to **NULL**, *pBytesReceived* must contain a valid memory address, and not be set to **NULL**.

### `Overlapped` [in, optional]

For asynchronous calls, set *pOverlapped* to point to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure; for synchronous calls, set it to **NULL**.

A synchronous call blocks until the entity-body data has been retrieved, whereas an asynchronous call immediately returns **ERROR_IO_PENDING** and the calling application then uses
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or I/O completion ports to determine when the operation is completed. For more information about using
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structures for synchronization, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function is used asynchronously, a return value of **ERROR_IO_PENDING** indicates that the next request is not yet ready and is retrieved later through normal overlapped I/O completion mechanisms.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters are in an unusable form. |
| **ERROR_HANDLE_EOF** | The specified entity body has already been completely retrieved; in this case, the value pointed to by *pBytesReceived* is not meaningful, and *pBuffer* should not be examined. |
| **ERROR_DLL_INIT_FAILED** | The calling application did not call [HttpInitialize](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpinitialize) before calling this function. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## Remarks

To retrieve an entire entity body, an application is expected to call
**HttpReceiveRequestEntityBody**, passing in new buffers, until the function returns **ERROR_HANDLE_EOF**. As long as a buffer full of entity-body data is copied successfully and there is still more entity-body data waiting to be retrieved, the function returns **NO_ERROR**.

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HTTP Server Sample Application](https://learn.microsoft.com/windows/desktop/Http/http-server-sample-application)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))

[HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest)

[HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse)

[HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody)