# HttpSetRequestProperty function

## Description

The **HttpSetRequestProperty** function sets a new property or modifies an existing property on the specified request.

## Parameters

### `RequestQueueHandle` [in]

The handle to the request queue on which the request was received. A request queue is created and its handle returned by a call to the [HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

### `Id` [in]

The opaque ID of the request. This ID is located in the *RequestId* member of the [HTTP\_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure returned by [HttpReceiveHttpRequest](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpreceivehttprequest).

### `PropertyId` [in]

A member of the [HTTP\_REQUEST\_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_request_property) enumeration describing the property type that is set. This must be one of the following:

| **Property** | **Meaning** |
| HttpRequestPropertyStreamError | Sets a stream error on the request. |

### `Input` [in]

A pointer to the buffer that contains the property information.

It must point to one of the following property information types based on the property that is set.

| **Property** | **Configuration Type** |
| HttpRequestPropertyStreamError | [HTTP\_REQUEST\_PROPERTY\_STREAM\_ERROR](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_property_stream_error) structure |

### `InputPropertySize` [in]

The length, in bytes, of the buffer pointed to by the *Input* parameter.

### `Overlapped` [in]

For asynchronous calls, set *pOverlapped* to point to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure; for synchronous calls, set it to **NULL**.

A synchronous call blocks until the operation is complete, whereas an asynchronous call immediately returns **ERROR\_IO\_PENDING** and the calling application then uses [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or I/O completion ports to determine when the operation is completed. For more information about using [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structures for synchronization, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

## Return value

If the function succeeds, it returns **ERROR\_SUCCESS**.

If the function fails, it returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty)