# HttpShutdownRequestQueue function

## Description

The **HttpShutdownRequestQueue** function stops queuing requests for the specified request queue process. Outstanding calls to [HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest) are canceled.

## Parameters

### `RequestQueueHandle` [in]

The handle to the request queue that is shut down. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

## Return value

If the function succeeds, it returns **NO_ERROR**

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *ReqQueueHandle* parameter does not contain a valid request queue.<br><br>The application does not have permission to shut down the request queue. |

## Remarks

**HttpShutdownRequestQueue** cancels outstanding requests and stops all processing on the request queue process. The following steps are performed when this function is called:

1. The request queue process is marked for cleanup and no new requests are routed to the request queue process.
2. If the calling process is a controller, outstanding [HttpWaitForDemandStart](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpwaitfordemandstart) calls are canceled.
3. Pending [HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest) calls from the calling process are canceled.
4. Requests that are already bound to the calling process are canceled.
5. The unreceived pending requests that are queued to the request queue process rerouted to another request queue process. If no other request queue process is available, the pending requests are saved until the request queue is closed, or another non-controller request queue process launches.
6. Pending [HttpWaitForDisconnect](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpwaitfordisconnect) calls initiated by the calling process are canceled.
7. Outstanding responses indicated by the calling process are not affected, they are properly completed.

Be aware that if the request queue handle is shared by multiple processes, **HttpShutdownRequestQueue** limits cleanup to the calling process. Other processes currently working on the request queue are not affected.

**HttpShutdownRequestQueue** can be used by applications to recycle request queue processes. For this purpose, **HttpShutdownRequestQueue** is called prior to terminating a process that shares the request queue with other processes. After **HttpShutdownRequestQueue** returns, the process can be safely terminated or recycled.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpCloseRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloserequestqueue)

[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue)

[HttpQueryRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryrequestqueueproperty)

[HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty)