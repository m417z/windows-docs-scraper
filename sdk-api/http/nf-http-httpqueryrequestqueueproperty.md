# HttpQueryRequestQueueProperty function

## Description

The **HttpQueryRequestQueueProperty** function queries a property of the request queue identified by the specified handle.

## Parameters

### `RequestQueueProperty` [in]

The handle to the request queue for which the property setting is returned. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

### `Property` [in]

A member of the [HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) enumeration that describes the property type that is set. This can be one of the following:

| Property | Meaning |
| --- | --- |
| **HttpServer503VerbosityProperty** | Queries the current verbosity level of 503 responses generated for the requests queue. |
| **HttpServerQueueLengthProperty** | Queries the limit on the number of outstanding requests in the request queue. |
| **HttpServerStateProperty** | Queries the current state of the request queue. The state must be either active or inactive. |

### `PropertyInformation` [out]

A pointer to the buffer that receives the property information.

*pPropertyInformation* points to one of the following property information values based on the property that is set.

| Property | Value |
| --- | --- |
| HttpServerStateProperty | [HTTP_ENABLED_STATE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_enabled_state) (enumeration member) |
| HttpServerQueueLengthProperty | ULONG |
| HttpServer503VerbosityProperty | [HTTP_503_RESPONSE_VERBOSITY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_503_response_verbosity) (enumeration member) |

### `PropertyInformationLength` [in]

The length, in bytes, of the buffer pointed to by the *pPropertyInformation* parameter.

### `Reserved1` [in]

Reserved. Must be zero.

### `ReturnLength` [out, optional]

The number, in bytes, returned in the *pPropertyInformation* buffer if not **NULL**.

If the output buffer is too small, the call fails with a return value of **ERROR_MORE_DATA**. The value pointed to by *pReturnLength* can be used to determine the minimum length of the buffer required for the call to succeed.

### `Reserved2` [in]

This parameter is reserved and must be **NULL**.

## Return value

If the function succeeds, it returns **NO_ERROR**.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *Reserved* parameter is not zero or the *pReserved* parameter is not **NULL**.<br><br>The property type specified in the *Property* parameter is not supported on request queues.<br><br>The *pPropertyInformation* parameter is **NULL**.<br><br>The *PropertyInformationLength* parameter is zero.<br><br>The application does not have permission to open the request queue. |
| **ERROR_MORE_DATA** | The size, in bytes, of the buffer pointed to by the *pPropertyInformation* parameter is too small to receive the property information. Call the function again with a buffer at least as large as the size pointed to by *pReturnLength* on exit. |
| **ERROR_NOT_SUPPORTED** | The handle to the request queue is an HTTP version 1.0 handle. Property management is only supported for HTTP version 2.0 and later request queues. |

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpCloseRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloserequestqueue)

[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue)

[HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty)

[HttpShutdownRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpshutdownrequestqueue)