# WsOpenChannel function

## Description

Open a channel to an endpoint.

## Parameters

### `channel` [in]

The channel to open.

### `endpointAddress` [in]

The address of the endpoint.

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_OPERATION_ABORTED** | The operation was aborted. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_ENDPOINT_NOT_FOUND** | The remote endpoint does not exist or could not be located. |
| **WS_E_ENDPOINT_ACCESS_DENIED** | Access was denied by the remote endpoint. |
| **WS_E_ENDPOINT_DISCONNECTED** | The connection with the remote endpoint was terminated. |
| **WS_E_ENDPOINT_FAILURE** | The remote endpoint could not process the request. |
| **WS_E_ENDPOINT_NOT_AVAILABLE** | The remote endpoint is not currently in service at this location. |
| **WS_E_ENDPOINT_TOO_BUSY** | The remote endpoint is unable to process the request due to being overloaded. |
| **WS_E_ENDPOINT_UNREACHABLE** | The remote endpoint was not reachable. |
| **WS_E_INVALID_ENDPOINT_URL** | The endpoint address URL is invalid. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **WS_E_PROXY_ACCESS_DENIED** | Access was denied by the HTTP proxy server. |
| **WS_E_PROXY_FAILURE** | The HTTP proxy server could not process the request. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **WS_E_SECURITY_VERIFICATION_FAILURE** | Security verification was not successful for the received data. |
| **WS_E_SECURITY_SYSTEM_FAILURE** | A security operation failed in the Windows Web Services framework. |
| **WS_E_PROXY_REQUIRES_BASIC_AUTH** | The HTTP proxy server requires HTTP authentication scheme 'basic'. |
| **WS_E_PROXY_REQUIRES_DIGEST_AUTH** | The HTTP proxy server requires HTTP authentication scheme 'digest'. |
| **WS_E_PROXY_REQUIRES_NEGOTIATE_AUTH** | The HTTP proxy server requires HTTP authentication scheme 'negotiate'. |
| **WS_E_PROXY_REQUIRES_NTLM_AUTH** | The HTTP proxy server requires HTTP authentication scheme 'NTLM'. |
| **WS_E_SERVER_REQUIRES_BASIC_AUTH** | The remote endpoint requires HTTP authentication scheme 'basic'. |
| **WS_E_SERVER_REQUIRES_DIGEST_AUTH** | The remote endpoint requires HTTP authentication scheme 'digest'. |
| **WS_E_SERVER_REQUIRES_NEGOTIATE_AUTH** | The remote endpoint requires HTTP authentication scheme 'negotiate'. |
| **WS_E_SERVER_REQUIRES_NTLM_AUTH** | The remote endpoint requires HTTP authentication scheme 'NTLM'. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

If the open is successful, then the channel must be closed using [WsCloseChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsclosechannel) before it can be freed.

Use [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) to create the channel.

Once a channel has been opened to an endpoint, then all communication
occurs with that endpoint.

The endpoint address and its contents are not required after the
function returns, even if the function is invoked asynchronously
(for example, it can safely be declared on the stack).

Whether any IO actually happens during this call will depend on the
type of channel and its settings.