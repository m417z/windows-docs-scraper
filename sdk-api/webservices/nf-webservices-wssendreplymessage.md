# WsSendReplyMessage function

## Description

Sends a message which is a reply to a received message.

## Parameters

### `channel` [in]

A pointer to the **Channel** object on which to send the reply Message. The pointer must reference a valid [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) object.

### `replyMessage` [in]

A pointer to the **Message** object for sending the reply. The pointer must reference a valid [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) object.
Message object state must be set to **WS_MESSAGE_STATE_EMPTY** or **WS_MESSAGE_STATE_INITIALIZED**.

**Note** If an initialized message is provided it must be initialized using **WS_REPLY_MESSAGE** or **WS_FAULT_MESSAGE**.

### `replyMessageDescription` [in]

A pointer to a [WS_MESSAGE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_description) object. The **action** field of **WS_MESSAGE_DESCRIPTION** is used as the **action** header for the reply message. This field can be **NULL** if no action is required.

The **bodyElementDescription** field of the [WS_MESSAGE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_description) is used to serialize the body of the reply message. This field may be **NULL** if no body element is desired. See [WsWriteBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebody) for information about how the **bodyElementDescription** is used to serialize a value.

### `writeOption` [in]

Determines whether the body element is required, and how the value is allocated.

See [WS_WRITE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) for more information.

### `replyBodyValue`

A void pointer to the value to serialize in the reply message.

### `replyBodyValueSize` [in]

The size in bytes of the reply value being serialized.

### `requestMessage` [in]

A pointer to a WS_MESSAGE object encapsulating the request message text. This is used to obtain correlation information used in formulating the reply message.

**Note** The message can be in any state except **WS_MESSAGE_STATE_EMPTY**.

### `asyncContext` [in, optional]

A pointer to a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) data structure with information about invoking the function asynchronously. A **NULL** value indicates a request for synchronous operation.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_OPERATION_ABORTED** | The operation was aborted. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_ENDPOINT_DISCONNECTED** | The connection with the remote endpoint was terminated. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **WS_E_SECURITY_VERIFICATION_FAILURE** | Security verification was not successful for the received data. |
| **WS_E_SECURITY_SYSTEM_FAILURE** | A security operation failed in the Windows Web Services framework. |
| **WS_E_SECURITY_TOKEN_EXPIRED** | A security token was rejected by the server because it has expired. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The reply message will including correlation information as appropriate
to the [WS_ADDRESSING_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version). See [Channel Layer Overview](https://learn.microsoft.com/windows/desktop/wsw/channel-layer-overview)
for more information about correlating request reply messages.