# WsAbortChannel function

## Description

Cancels all pending I/O for a specified channel

## Parameters

### `channel` [in]

A pointer to a [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) structure representing the channel for which
to cancel I/O.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_E_NOT_SUPPORTED** | See the Remarks section for platform limitations. |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

**Windows Server 2003 and before:** On Windows platforms before Windows Vista, this function is not supported for WS_UDP_CHANNEL_BINDING or WS_HTTP_CHANNEL_BINDING if the channel is in the WS_CHANNEL_STATE_ACCEPTING state and the listener has not already been aborted.

(For information on channel bindings and channel states, see the [WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) and [WS_CHANNEL_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) enumerations.)

This function is also not supported for WS_HTTP_CHANNEL_BINDING with WS_CHANNEL_TYPE_REPLY when aborting a channel in the WS_CHANNEL_STATE_OPEN or WS_CHANNEL_STATE_FAULTED state. (For information on channel types, see the [WS_CHANNEL_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type) enumeration.

**WsAbortChannel** can be called for a channel in any state, and does not wait for pending I/O to complete before aborting the channel.

If the channel is in the **WS_CHANNEL_STATE_OPEN** state, **WsAbortChannel** causes the channel to fault to the **WS_CHANNEL_STATE_FAULTED** state.

**Note** See
[WsAbandonMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabandonmessage) for information on how to skip a particular
message and keep the channel open.

If called with valid parameters, this function will not fail for reasons such as a lack of system resources. However, note the limitations on some operating systems versions at the beginning of Remarks.