# HTTP_503_RESPONSE_VERBOSITY enumeration

## Description

The **HTTP_503_RESPONSE_VERBOSITY** enumeration defines the verbosity levels for a 503, service unavailable, error responses.

This structure must be used when setting or querying the [HttpServer503ResponseProperty](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) on a request queue.

## Constants

### `Http503ResponseVerbosityBasic`

A 503 response is not sent; the connection is reset.
This is the default HTTP Server API behavior.

### `Http503ResponseVerbosityLimited`

The HTTP Server API sends a 503 response with a "Service Unavailable" reason phrase. The HTTP Server closes the TCP connection after sending the response, so the client has to re-connect.

### `Http503ResponseVerbosityFull`

The HTTP Server API sends a 503 response with a detailed reason phrase. The HTTP Server closes the TCP connection after sending the response, so the client has to re-connect.

## Remarks

This enumeration is used in [HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty), and [HttpQueryrequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryrequestqueueproperty) to set and query the 503 response verbosity. The *pPropertyInformation* parameter points to a member of the **HTTP_503_RESPONSE_VERBOSITY** enumeration when the *Property* parameter is **HttpServer503VerbosityProperty**.

This enumeration defines the verbosity level for a request queue when sending 503 (Service Unavailable) error responses. Note that the 503 response level set using the **HTTP_503_RESPONSE_VERBOSITY** enumeration only affects the error responses generated internally
by the HTTP Server API.

**Note** Disclosing information about the state of the service to potentially unsafe clients may pose a security risk.

## See also

[HTTP Server API Version 2.0 Enumeration Types](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-enumeration-types)

[HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property)

[HttpQueryRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryrequestqueueproperty)

[HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty)