# WsReceiveMessage function

## Description

Receive a message and deserialize the body of the message as a value.

## Parameters

### `channel` [in]

The channel to receive from.

### `message` [in]

The message object used to receive.

The message should be in [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state) state.

### `messageDescriptions`

An array of pointers to message descriptions that specifies the metadata for
the expected types of messages.

### `messageDescriptionCount` [in]

The number of items in the messageDescriptions array.

### `receiveOption` [in]

Whether the message is required. See [WS_RECEIVE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_receive_option) for more information.

### `readBodyOption` [in]

Whether the body element is required, and how to allocate the value.
See [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) for more information.

### `heap` [in, optional]

The heap to store the deserialized values in. If the heap is
not required for the given type, then this parameter can be **NULL**.

### `value`

The interpretation of this parameter depends on the [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

If [WS_RECEIVE_OPTIONAL_MESSAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_receive_option) is specified for the receiveOption
parameter, and no more messages are available on the channel,
this parameter is not touched. In this case, the function returns **WS_S_END**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

If the bodyElementDescription of the [WS_MESSAGE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_description) that
matched is **NULL**, then this parameter is not touched. In this case, the
parameter does not need to be specified.

### `valueSize` [in]

The interpretation of this parameter depends on the [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `index`

If [WS_RECEIVE_OPTIONAL_MESSAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_receive_option) is specified for the receiveOption
parameter, and no more messages are available on the channel,
this parameter is untouched. In this case, the function will
return **WS_S_END**.

Otherwise, if the function succeeds this will contain the zero-based
index into the array of message descriptions indicating which one matched.

This parameter may be **NULL** if the caller is not interested in the value
(for example, if there is only one message description).

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_S_END** | The receive option [WS_RECEIVE_OPTIONAL_MESSAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_receive_option) was specified and there are no more messages available for the channel. |
| **WS_E_ENDPOINT_FAULT_RECEIVED** | The received message contained a fault. The fault can be extracted from the [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) using [WsGetErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgeterrorproperty). |
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

This function uses metadata about the expected message types in order to deserialize the body.
The metadata is an array of pointers to [WS_MESSAGE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_description)s.
Each message description contains an action value, which is used to match against
the action of the message, and an [WS_ELEMENT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_element_description) which provides the metadata for the body element.

When the message headers have been received, the function will scan the array
in order to find a match against the action. The first message description
that matches is used to deserialize the body, and the zero-based index
of this message description in the array is returned in the index out parameter.
If the function succeeds, the index out parameter will always be set to indicate which
message description was used.

In order for a message description to match, the action value must match that of
the message exactly. If the action in the [WS_MESSAGE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_description)
is **NULL**, then the action always matches. This can be used in the case where there
is no action header in the received message, or if the body is always the same no matter
what the action is.

If the body is expected to be empty, the bodyElementDescription field of the
[WS_MESSAGE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_description) may be **NULL**.

If the bodyElementDescription is non-**NULL**, then this function deserializes the
body as described in [WsReadBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadbody).

After a message has been received, its headers can be inspected using [WsGetHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetheader) or [WsGetCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetcustomheader).