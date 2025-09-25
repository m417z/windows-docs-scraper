# HttpWaitForDemandStart function

## Description

The **HttpWaitForDemandStart** function waits for the arrival of a new request that can be served by a new request queue process.

## Parameters

### `RequestQueueHandle` [in]

A handle to the request queue on which demand start is registered. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

### `Overlapped` [in, optional]

For asynchronous calls, set *pOverlapped* to point to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure; for synchronous calls, set it to **NULL**.

A synchronous call blocks until a request has arrived in the specified queue, whereas an asynchronous call immediately returns **ERROR_IO_PENDING** and the calling application then uses
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or I/O completion ports to determine when the operation is completed. For more information about using
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structures for synchronization, see
[Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

## Return value

If the function succeeds, it returns **NO_ERROR**.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *ReqQueueHandle* parameter does not contain a valid request queue. |
| **ERROR_INVALID_ID_AUTHORITY** | The calling process is not the controller process for this request queue. |
| **ERROR_INVALID_HANDLE** | The calling process has already initiated a shutdown on the request queue or has closed the request queue handle. |
| **ERROR_ALREADY_EXISTS** | A demand start registration already exists for the request queue. |

## Remarks

Only the controller process can call **HttpWaitForDemandStart** to register a demand start notification. The controller process is the process that created the request queue and indicated that it is a controller process by passing the **HTTP_CREATE_REQUEST_QUEUE_FLAG_CONTROLLER** flag. If a process other than the controlling process calls **HttpWaitForDemandStart**, the HTTP Server API returns **ERROR_INVALID_ID_AUTHORITY**.

**HttpWaitForDemandStart** completes when a new request arrives for the specified request queue. At this time, a controller process can use this API to start a new worker process to server pending requests. Delayed start of the worker process allows applications to avoid consuming resources until they are required.

The HTTP Server API allows only one outstanding notification registered on a request queue at any time. The HTTP Server API does not enforce limitations on the number of times that **HttpWaitForDemandStart** can be called on the same request queue consecutively. There is no limit on the number of outstanding processes that are working on the same request queue.

The HTTP Server API supports canceling asynchronous **HttpWaitForDemandStart** calls. Applications can use [CancelIoEx](https://learn.microsoft.com/windows/desktop/FileIO/cancelioex-func) with the overlapped structure supplied in the *pOverlapped* parameter, to cancel an outstanding **HttpWaitForDemandStart** call.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpCloseRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloserequestqueue)

[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue)

[HttpQueryRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryrequestqueueproperty)

[HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty)

[HttpShutdownRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpshutdownrequestqueue)