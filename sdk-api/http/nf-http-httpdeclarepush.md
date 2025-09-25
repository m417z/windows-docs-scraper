# HttpDeclarePush function

## Description

Declares a resource-to-subresource relationship to use for an HTTP server push. HTTP.sys then performs an HTTP 2.0 server push for the given resource, if the underlying protocol, connection, client, and policies allow the push operation.

## Parameters

### `RequestQueueHandle` [in]

The handle to an HTTP.sys request queue that the [HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function returned.

### `RequestId` [in]

The opaque identifier of the request that is declaring the push operation. The request must be from the specified queue handle.

### `Verb` [in]

The HTTP verb to use for the push operation. The HTTP.sys push operation only supports **HttpVerbGET** and **HttpVerbHEAD**.

### `Path` [in]

The path portion of the URL for the resource being pushed.

### `Query` [in, optional]

The query portion of the URL for the resource being pushed. This string should not include the leading question mark (?).

### `Headers` [in, optional]

The request headers for the push operation.

You should not provide a Host header, because HTTP.sys automatically generates the correct Host information. HTTP.sys does not support cross-origin push operations, so HTTP.sys enforces and generates Host information that matches the original client-initiated request.

The push request is not allowed to have an entity body, so you cannot include a non-zero Content-Length header or any Transfer-Encoding header.

## Return value

If the function succeeds, it returns **NO_ERROR**.

If the function fails, it returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

## Remarks

You should call **HttpDeclarePush** before you send any response bytes that would cause the client to discover the subresource itself. Failure to observe this order results in a race between the server that is pushing the resource and the client that is retrieving the resources, which can waste bandwidth.
The server application should only use **HttpDeclarePush** to push resources that the server application is highly confident are needed and not already cached by the client. If the server application pushes other resources, unnecessary use of bandwidth and CPU may occur.

## See also

[HTTP_REQUEST_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_headers)

[HTTP_VERB](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_verb)

[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue)