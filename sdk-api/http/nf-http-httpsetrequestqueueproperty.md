# HttpSetRequestQueueProperty function

## Description

The **HttpSetRequestQueueProperty** function sets a new property or modifies an existing property on the request queue identified by the specified handle.

## Parameters

### `RequestQueueHandle` [in]

The handle to the request queue on which the property is set. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

### `Property` [in]

A member of the [HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) enumeration describing the property type that is set. This must be one of the following:

| Property | Meaning |
| --- | --- |
| **HttpServer503VerbosityProperty** | Modifies or sets the current verbosity level of 503 responses generated for the request queue. |
| **HttpServerQueueLengthProperty** | Modifies or sets the limit on the number of outstanding requests in the request queue. |
| **HttpServerStateProperty** | Modifies or sets the state of the request queue. The state must be either active or inactive. |

### `PropertyInformation` [in]

A pointer to the buffer that contains the property information.

*pPropertyInformation* points to one of the following property information types based on the property that is set.

| Property | Configuration Type |
| --- | --- |
| HttpServerStateProperty | [HTTP_ENABLED_STATE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_enabled_state) enumeration |
| HttpServerQueueLengthProperty | ULONG |
| HttpServer503VerbosityProperty | [HTTP_503_RESPONSE_VERBOSITY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_503_response_verbosity) enumeration |

### `PropertyInformationLength` [in]

The length, in bytes, of the buffer pointed to by the *pPropertyInformation* parameter.

### `Reserved1` [in]

Reserved. Must be zero.

### `Reserved2` [in]

Reserved. Must be **NULL**.

## Return value

If the function succeeds, it returns **NO_ERROR**.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *Reserved* parameter is not zero or the *pReserved* parameter is not **NULL**.<br><br>The property type specified in the *Property* parameter is not supported for request queues.<br><br>The *pPropertyInformation* parameter is **NULL**.<br><br>The *PropertyInformationLength* parameter is zero.<br><br>The application does not have permission to set properties on the request queue. Only the application that created the request queue can set the properties. |
| **ERROR_NOT_SUPPORTED** | The handle to the request queue is an HTTP version 1.0 handle. Property management is only supported on HTTP version 2.0 or later request queues. |

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpCloseRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloserequestqueue)

[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue)

[HttpQueryRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryrequestqueueproperty)

[HttpShutdownRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpshutdownrequestqueue)