# WsSendMessage function

## Description

Send a message on a channel using serialization to write the body element.

## Parameters

### `channel` [in]

The channel to send the message on.

### `message` [in]

The message object to use for sending.

The message object must be in [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state) or
**WS_MESSAGE_STATE_INITIALIZED**.

### `messageDescription` [in]

The action field of the [WS_MESSAGE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_description) is used as the
action header for the message. This field may be **NULL** if no action
is required.

The bodyElementDescription field of the [WS_MESSAGE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_description) is used to serialize the body of the message. This field may be
**NULL** if no body element is desired. See [WsWriteBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebody) for
information about how the bodyElementDescription is used to serialize
the value.

### `writeOption` [in]

 Whether the body element is required, and how the value is allocated. This is used
only when a body element is desired. For more information, see [WS_WRITE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) and
[WsWriteBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebody).

### `bodyValue`

The value to serialize in the body of the message.

### `bodyValueSize` [in]

The size of the value being serialized, in bytes.

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
| **WS_E_SECURITY_TOKEN_EXPIRED** | A security token was rejected by the server because it has expired. |
| **WS_E_PROXY_REQUIRES_BASIC_AUTH** | The HTTP proxy server requires HTTP authentication scheme 'basic'. |
| **WS_E_PROXY_REQUIRES_DIGEST_AUTH** | The HTTP proxy server requires HTTP authentication scheme 'digest'. |
| **WS_E_PROXY_REQUIRES_NEGOTIATE_AUTH** | The HTTP proxy server requires HTTP authentication scheme 'negotiate'. |
| **WS_E_PROXY_REQUIRES_NTLM_AUTH** | The HTTP proxy server requires HTTP authentication scheme 'NTLM'. |
| **WS_E_SERVER_REQUIRES_BASIC_AUTH** | The remote endpoint requires HTTP authentication scheme 'basic'. |
| **WS_E_SERVER_REQUIRES_DIGEST_AUTH** | The remote endpoint requires HTTP authentication scheme 'digest'. |
| **WS_E_SERVER_REQUIRES_NEGOTIATE_AUTH** | The remote endpoint requires HTTP authentication scheme 'negotiate'. |
| **WS_E_SERVER_REQUIRES_NTLM_AUTH** | The remote endpoint requires HTTP authentication scheme 'NTLM'. |
| **CERT_E_EXPIRED** | A required certificate is not within its validity period when verifying against the current system clock or the timestamp in the signed file. |
| **CERT_E_CN_NO_MATCH** | The certificates CN name does not match the passed value. |
| **CERT_E_UNTRUSTEDROOT** | A certificate chain processed, but terminated in a root certificate which is not trusted by the trust provider. |
| **CERT_E_WRONG_USAGE** | The certificate is not valid for the requested usage. |
| **CRYPT_E_REVOCATION_OFFLINE** | The revocation function was unable to check revocation because the revocation server was offline. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

To include custom headers with the message, initialize the message [WsInitializeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsinitializemessage) with [WS_BLANK_MESSAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_initialization) and then add the headers using [WsAddCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsaddcustomheader)
before calling this function.