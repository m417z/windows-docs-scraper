# XHR_PROPERTY enumeration

## Description

Defines properties that you can assign to an outgoing HTTP request by calling the [SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setproperty) method.

## Constants

### `XHR_PROP_NO_CRED_PROMPT:0`

Sets a flag in the HTTP request that suppresses automatic prompts for credentials.

### `XHR_PROP_NO_AUTH:0x1`

Sets a flag in the HTTP request that configures the HTTP request that disables authentication for the request.

### `XHR_PROP_TIMEOUT:0x2`

Sets the connect, send, and receive timeouts for HTTP socket operations.

**Note** This value will not affect the timeout behavior of the entire request process.

### `XHR_PROP_NO_DEFAULT_HEADERS:0x3`

Suppresses adding default headers to the HTTP request.

### `XHR_PROP_REPORT_REDIRECT_STATUS:0x4`

Causes the HTTP stack to call the [OnHeadersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onheadersavailable) callback method with an interim redirecting status code. The **OnHeadersAvailable** will be called again for additional redirects and the final destination status code.

### `XHR_PROP_NO_CACHE:0x5`

Suppresses cache reads and writes for the HTTP request.

### `XHR_PROP_EXTENDED_ERROR:0x6`

Causes the HTTP stack to provide **HRESULTS** with the underlying Win32 error code to the [OnError](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onerror) callback method in case of failure.

### `XHR_PROP_QUERY_STRING_UTF8:0x7`

Causes the query string to be encoded in UTF8 instead of ACP for HTTP request.

### `XHR_PROP_IGNORE_CERT_ERRORS:0x8`

Suppresses certain certificate errors.

### `XHR_PROP_ONDATA_THRESHOLD:0x9`

### `XHR_PROP_SET_ENTERPRISEID:0xa`

### `XHR_PROP_MAX_CONNECTIONS:0xb`

## See also

[OnError](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onerror)

[OnHeadersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onheadersavailable)

[SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setproperty)