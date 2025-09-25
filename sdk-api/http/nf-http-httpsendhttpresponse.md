# HttpSendHttpResponse function

## Description

The
**HttpSendHttpResponse** function sends an HTTP response to the specified HTTP request.

## Parameters

### `RequestQueueHandle` [in]

A handle to the request queue from which the specified request was retrieved. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

**Windows Server 2003 with SP1 and Windows XP with SP2:** The handle to the request queue is created by the [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

### `RequestId` [in]

An identifier of the HTTP request to which this response corresponds. This value is returned in the **RequestId** member of the
[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure by a call to the
[HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest) function. This value cannot be **HTTP_NULL_ID**.

### `Flags` [in]

This parameter can be a combination of some of the following flag values. Those that are mutually exclusive are marked accordingly.

| Flags | Meaning |
| --- | --- |
| **HTTP_SEND_RESPONSE_FLAG_DISCONNECT** | The network connection should be disconnected after sending this response, overriding any persistent connection features associated with the version of HTTP in use.<br><br>**Caution** Combining **HTTP_SEND_RESPONSE_FLAG_DISCONNECT** and **HTTP_SEND_RESPONSE_FLAG_MORE_DATA** in a single call to the **HttpSendHttpResponse** function produces undefined results. |
| **HTTP_SEND_RESPONSE_FLAG_MORE_DATA** | Additional entity body data for this response is sent by the application through one or more subsequent calls to [HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody). The last call sending entity-body data then sets this flag to zero.<br><br>**Caution** Combining **HTTP_SEND_RESPONSE_FLAG_DISCONNECT** and **HTTP_SEND_RESPONSE_FLAG_MORE_DATA** in a single call to the **HttpSendHttpResponse** function produces undefined results. |
| **HTTP_SEND_RESPONSE_FLAG_BUFFER_DATA** | This flag enables buffering of data in the kernel on a per-response basis.<br><br>It should be used by an application doing synchronous I/O or by an application doing asynchronous I/O with no more than one outstanding send at a time.<br><br>Applications that use asynchronous I/O and that may have more than one send outstanding at a time should not use this flag.<br><br>When this flag is set, it should also be used consistently in calls to the [HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody) function.<br><br>**Windows Server 2003:** This flag is not supported. This flag is new for Windows Server 2003 with SP1. |
| **HTTP_SEND_RESPONSE_FLAG_ENABLE_NAGLING** | Enables the TCP nagling algorithm for this send only.<br><br>**Windows Server 2003 with SP1 and Windows XP with SP2:** This flag is not supported. |
| **HTTP_SEND_RESPONSE_FLAG_PROCESS_RANGES** | Specifies that for a range request, the full response content is passed and the caller wants the HTTP API to process ranges appropriately.<br><br>**Note** This flag is only supported for responses to HTTP *GET* requests and offers a limited subset of functionality. Applications that require full range processing should perform it in user mode and not rely on HTTP.sys. Its usage is discouraged.<br><br>Windows Server 2008 R2 and Windows 7 or later.<br><br>**Note** This flag is supported. |
| **HTTP_SEND_RESPONSE_FLAG_OPAQUE** | Specifies that the request/response is not HTTP compliant and all subsequent bytes should be treated as entity-body. Applications specify this flag when it is accepting a Web Socket upgrade request and informing HTTP.sys to treat the connection data as opaque data.<br><br>This flag is only allowed when the **StatusCode** member of *pHttpResponse* is **101**, switching protocols. **HttpSendHttpResponse** returns **ERROR_INVALID_PARAMETER** for all other HTTP response types if this flag is used.<br><br>**Windows 8 and later:** This flag is supported. |

### `HttpResponse` [in]

A pointer to an
[HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response) structure that defines the HTTP response.

### `CachePolicy` [in, optional]

A pointer to the [HTTP_CACHE_POLICY](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_cache_policy) structure used to cache the response.

**Windows Server 2003 with SP1 and Windows XP with SP2:** This parameter is reserved and must be **NULL**.

### `BytesSent` [out]

Optional. A pointer to a variable that receives the number, in bytes, sent if the function operates synchronously.

When making an asynchronous call using *pOverlapped*, set *pBytesSent* to **NULL**. Otherwise, when *pOverlapped* is set to **NULL**, *pBytesSent* must contain a valid memory address and not be set to **NULL**.

### `Reserved1` [in]

This parameter is reserved and must be **NULL**.

### `Reserved2` [in]

This parameter is reserved and must be zero.

### `Overlapped` [in]

For asynchronous calls, set *pOverlapped* to point to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure; for synchronous calls, set to **NULL**.

A synchronous call blocks until all response data specified in the *pHttpResponse* parameter is sent, whereas an asynchronous call immediately returns **ERROR_IO_PENDING** and the calling application then uses
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or I/O completion ports to determine when the operation is completed. For more information about using
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structures for synchronization, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

### `LogData` [in, optional]

A pointer to the [HTTP_LOG_DATA](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_log_data) structure used to log the response. Pass a pointer to the [HTTP_LOG_FIELDS_DATA](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_log_fields_data) structure and cast it to **PHTTP_LOG_DATA**.

Be aware that even when logging is enabled on a URL Group, or server session, the response will not be logged unless the application supplies the log fields data structure.

**Windows Server 2003 and Windows XP with SP2:** This parameter is reserved and must be **NULL**.

**Windows Vista and Windows Server 2008:** This parameter is new for Windows Vista, and Windows Server 2008

## Return value

If the function succeeds, the function returns **NO_ERROR**.

If the function is used asynchronously, a return value of **ERROR_IO_PENDING** indicates that the next request is not yet ready and is retrieved later through normal overlapped I/O completion mechanisms.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters is in an unusable form. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h. |

## Remarks

The
**HttpSendHttpResponse** function is used to create and send a response header, and the
[HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody) function can be used to send entity-body data as required.

If neither a content-length header nor a transfer-encoding header is included with the response, the application must indicate the end of the response by explicitly closing the connection by using the **HTTP_SEND_RESPONSE_DISCONNECT** flag.

 If an application specifies a "Server:" header in a response, using the **HttpHeaderServer** identifier in the [HTTP_KNOWN_HEADER](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_known_header) structure, that specified value is placed as the first part of the header, followed by a space and then "Microsoft-HTTPAPI/1.0". If no server header is specified, **HttpSendHttpResponse** supplies "Microsoft-HTTPAPI/1.0" as the server header.

**Note** The **HttpSendHttpResponse** and [HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody) function must not be called simultaneously from different threads on the same *RequestId*.

## See also

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response)

[HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest)

[HttpReceiveRequestEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiverequestentitybody)

[HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody)