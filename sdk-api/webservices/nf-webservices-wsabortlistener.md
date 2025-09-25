# WsAbortListener function

## Description

Cancels any pending I/O for the specified [listener](https://learn.microsoft.com/windows/desktop/wsw/ws-listener).

## Parameters

### `listener` [in]

Pointer to a [WS_LISTENER](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) structure representing the listener for which to cancel I/O.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

## Remarks

**WsAbortListener** can be called when the listener is in any state. (See the [WS_LISTENER_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_state) enumeration for possible states.) If the listener is in the WS_LISTENER_STATE_OPEN state, this function will force the listener to fault (reset to the WS_LISTENER_STATE_FAULTED state). When a listener is faulted, all attempts to accept a message from it fail immediately with the WS_E_OBJECT_FAULTED error code.

This function does not wait for pending I/O to complete.

If called with valid parameters, this function will not fail for reasons such as a lack of system resources.