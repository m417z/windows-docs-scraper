# HttpSendResponseEntityBody function

## Description

The
**HttpSendResponseEntityBody** function sends entity-body data associated with an HTTP response.

## Parameters

### `RequestQueueHandle` [in]

A handle to the request queue from which the specified request was retrieved. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

**Windows Server 2003 with SP1 and Windows XP with SP2:** The handle to the request queue is created by the [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

### `RequestId` [in]

An identifier of the HTTP request to which this response corresponds. This value is returned in the **RequestId** member of the
[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure by a call to the
[HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest) function. It cannot be **HTTP_NULL_ID**.

### `Flags` [in]

A parameter that can include one of the following mutually exclusive flag values.

| Flags | Meaning |
| --- | --- |
| **HTTP_SEND_RESPONSE_FLAG_DISCONNECT** | The network connection should be disconnected after sending this response, overriding any persistent connection features associated with the version of HTTP in use. Applications should use this flag to indicate the end of the entity in cases where neither content length nor chunked encoding is used. |
| **HTTP_SEND_RESPONSE_FLAG_MORE_DATA** | Additional entity body data for this response is sent by the application through one or more subsequent calls to **HttpSendResponseEntityBody**. The last call then sets this flag to zero. |
| **HTTP_SEND_RESPONSE_FLAG_BUFFER_DATA** | This flag enables buffering of data in the kernel on a per-response basis.<br><br>It should be used by an application doing synchronous I/O, or by a an application doing asynchronous I/O with no more than one send outstanding at a time.<br><br>Applications using asynchronous I/O which may have more than one send outstanding at a time should not use this flag.<br><br>When this flag is set, it should be used consistently in calls to the [HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse) function as well.<br><br>**Windows Server 2003:** This flag is not supported. This flag is new for Windows Server 2003 with SP1. |
| **HTTP_SEND_RESPONSE_FLAG_ENABLE_NAGLING** | Enables the TCP nagling algorithm for this send only.<br><br>**Windows Vista and later:** This flag is not supported. |
| **HTTP_SEND_RESPONSE_FLAG_PROCESS_RANGES** | Specifies that for a range request, the full response content is passed and the caller wants the HTTP API to process ranges appropriately.<br><br>**Note** This flag is only supported for responses to HTTP *GET* requests and offers a limited subset of functionality. Applications that require full range processing should perform it in user mode and not rely on HTTP.sys. It's usage is discouraged.<br><br>Windows Server 2008 R2 and Windows 7 or later.<br><br>**Note** This flag is supported. |
| **HTTP_SEND_RESPONSE_FLAG_OPAQUE** | Specifies that the request/response is not HTTP compliant and all subsequent bytes should be treated as entity-body. Applications specify this flag when it is accepting a Web Socket upgrade request and informing HTTP.sys to treat the connection data as opaque data.<br><br>This flag is only allowed when the **StatusCode** member of *pHttpResponse* is **101**, switching protocols. **HttpSendResponseEntityBody** returns **ERROR_INVALID_PARAMETER** for all other HTTP response types if this flag is used.<br><br>**Windows 8 and later:** This flag is supported. |

**Caution** Combining both flags in a single call to the [HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse) function produces undefined results.

### `EntityChunkCount` [in]

A number of structures in the array pointed to by *pEntityChunks*. This count cannot exceed 9999.

### `EntityChunks` [in]

A pointer to an array of
[HTTP_DATA_CHUNK](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_data_chunk) structures to be sent as entity-body data.

### `BytesSent` [out]

Optional. A pointer to a variable that receives the number, in bytes, sent if the function operates synchronously.

When making an asynchronous call using *pOverlapped*, set *pBytesSent* to **NULL**. Otherwise, when *pOverlapped* is set to **NULL**, *pBytesSent* must contain a valid memory address, and not be set to **NULL**.

### `Reserved1` [in]

This parameter is reserved and must be **NULL**.

### `Reserved2` [in]

This parameter is reserved and must be zero.

### `Overlapped` [in]

For asynchronous calls, set *pOverlapped* to point to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure; for synchronous calls, set it to **NULL**.

A synchronous call blocks until all response data specified in the *pEntityChunks* parameter is sent, whereas an asynchronous call immediately returns **ERROR_IO_PENDING** and the calling application then uses
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or I/O completion ports to determine when the operation is completed. For more information about using
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structures for synchronization, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

### `LogData` [in, optional]

A pointer to the [HTTP_LOG_DATA](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_log_data) structure used to log the response. Pass a pointer to the [HTTP_LOG_FIELDS_DATA](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_log_fields_data) structure and cast it to **PHTTP_LOG_DATA**.

Be aware that even when logging is enabled on a URL Group, or server session, the response will not be logged unless the application supplies the log fields data structure.

**Windows Server 2003 and Windows XP with SP2:** This parameter is reserved and must be **NULL**.

**Windows Vista and Windows Server 2008:** This parameter is new for Windows Vista, and Windows Server 2008

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function is used asynchronously, a return value of **ERROR_IO_PENDING** indicates that the next request is not yet ready and is retrieved later through normal overlapped I/O completion mechanisms.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters is in an unusable form. |
| **ERROR_BAD_COMMAND** | There is a call pending to [HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse) or [HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody) having the same **RequestId**. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## Remarks

If neither a Content-length header nor a Transfer-encoding header is included in the response headers, the application must indicate the end of the response by explicitly closing the connection using the **HTTP_SEND_RESPONSE_DISCONNECT** flag.

**Note** **HttpSendResponseEntityBody** (or [HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse)) and **HttpSendResponseEntityBody** must not be called simultaneously from different threads on the same *RequestId*.

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HTTP_DATA_CHUNK](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_data_chunk)

[HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest)

[HttpReceiveRequestEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiverequestentitybody)

[HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse)