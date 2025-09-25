# WsSendFaultMessageForError function

## Description

Sends a fault message given a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object.

## Parameters

### `channel` [in]

The channel to send the message on.

### `replyMessage` [in]

A message object to use to send the reply message.

The message object should be in [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state) or
**WS_MESSAGE_STATE_INITIALIZED**. If an initialized message is provided,
it should have been initialized using [WS_FAULT_MESSAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_initialization).

### `faultError` [in]

The error object to use to construct the fault.

### `faultErrorCode` [in]

The error code associated with the fault. This cannot
be a success code.

This error code is never included in the fault message directly, but
instead is used as a fallback mechanism for creating a fault string in the case that
the [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object does not contain any error strings.

### `faultDisclosure` [in]

Controls how much of the error information is included in the fault message.

### `requestMessage` [in]

The request message. This is used to obtain correlation information used
in formulating the reply message.

The message can be in any state but [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

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
| **WS_E_ENDPOINT_DISCONNECTED** | The connection with the remote endpoint was terminated. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **WS_E_SECURITY_VERIFICATION_FAILURE** | Security verification was not successful for the received data. |
| **WS_E_SECURITY_SYSTEM_FAILURE** | A security operation failed in the Windows Web Services framework. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The [WS_FAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault) that is sent in the body of the message
is constructed using the same rules as defined by [WsCreateFaultFromError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatefaultfromerror).

The value of the [WS_ACTION_HEADER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type) used for
the reply message is computed as follows:

* If the [WS_CHANNEL_PROPERTY_ADDRESSING_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) of the
  channel is [WS_ADDRESSING_VERSION_TRANSPORT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version), then no
  action is included in the message because the addressing
  version does not permit an action value for faults.
* If the error object contains an action string (the
  length of the string returned by [WS_FAULT_ERROR_PROPERTY_ACTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_fault_error_property_id) is greater than zero), then the action string is used.
* If the error object does not contain an action, then
  a default action value is supplied.

If the error object contains a header used to describe the
fault as specified by [WS_FAULT_ERROR_PROPERTY_HEADER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_fault_error_property_id),
then the header is added to the headers of the fault message.

The fault message will include correlation information as appropriate
to the [WS_ADDRESSING_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version). See [Channel Layer Overview](https://learn.microsoft.com/windows/desktop/wsw/channel-layer-overview) for more information about correlating request reply messages.

If sending a fault without a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object, use
[WsSendReplyMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssendreplymessage).

To add custom headers to the message, initialize the message [WsInitializeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsinitializemessage) with [WS_FAULT_MESSAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_initialization) and then add the headers using
[WsAddCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsaddcustomheader) before calling this function.