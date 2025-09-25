# WsOpenListener function

## Description

Initiates "listening" on a specified address.
Once a listener is opened channels can be accepted
from it.
If the open is successful the Listener must be closed using
the [WsCloseListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscloselistener) function before Listener resources can be released.

## Parameters

### `listener` [in]

A pointer to the **Listener** object to open. The pointer must reference a valid [WS_LISTENER](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) object and the referenced value may not be **NULL**.

### `url` [in]

A pointer to a object containing the URL address string for the Listener.

**Note** The URL is always in escaped form..
The URL may not contain a query string or fragment.
This URL can include the '+' or '*' wildcards
in the host name portion, or a host name, or a literal IP address.
See Remarks for more information on the URL.

### `asyncContext` [in, optional]

A pointer to A WS_ASYNC_CONTEXT object that has information about how to invoke the function asynchronously. The value is set to **NULL** if invoking synchronously.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_OPERATION_ABORTED** | The listener was aborted during the open, or before the open. |
| **WS_E_INVALID_OPERATION** | The listener is in the incorrect state. |
| **WS_E_ADDRESS_IN_USE** | The address is already being used. |
| **WS_E_ADDRESS_NOT_AVAILABLE** | The address is not valid for this context. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **WS_E_OPERATION_ABORTED** | The operation was aborted. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

When using IPv6 addresses, they must be enclosed in brackets in
the host name portion.

For more information, see [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

For [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding), the path portion of the URL is
ignored. If a literal IP address is specified, then it is used to listen, otherwise
a wildcard IP address is used.

For [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding), the path portion of the URL is
is matched as a prefix against the received URL.
If a literal IP address is specified, then it is used to listen,
otherwise a wildcard IP address is used.