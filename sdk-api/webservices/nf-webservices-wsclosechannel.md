# WsCloseChannel function

## Description

Closes a specified [channel](https://learn.microsoft.com/windows/desktop/wsw/ws-channel).

## Parameters

### `channel` [in]

Pointer to a [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) structure representing the channel to close.

### `asyncContext` [in, optional]

Pointer to a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) data structure containing information for invoking the function asynchronously. Pass a **NULL**
value to call the function synchronously.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure where additional error information is stored if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_OPERATION_ABORTED** | The channel closure was aborted by a call to [WsAbortChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortchannel) while the channel was closing. |
| **WS_E_INVALID_OPERATION** | The channel was in an inappropriate state (see the Remarks section). |
| **WS_E_ENDPOINT_DISCONNECTED** | The connection with the remote endpoint was terminated. |
| **WS_E_ENDPOINT_FAILURE** | The remote endpoint could not process the request. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

If you open a channel or successfully accept a channel, you must close it when it is no longer needed. After a channel has been closed, the associated resources can safely be freed.

The channel-closing process will wait for any already initiated, pending I/O to complete.

If there are no messages currently being read or written for the channel, the channel attempts a graceful shutdown. Otherwise, all I/O still pending on the channel itself is aborted and the channel does a rude shutdown.

If the channel attempts a graceful shutdown but encounters an error, **WsCloseChannel** will return an error, but the channel will still be closed.

This operation is allowed only if the channel is in WS_CHANNEL_STATE_OPEN or WS_CHANNEL_STATE_FAULTED states.

Closing a channel automatically disassociates any messages that are in the
process of being read or written. Therefore, it is not necessary to call
[WsAbandonMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabandonmessage) before calling **WsCloseChannel**).