# PFN_WSK_RECEIVE_EVENT callback function

## Description

The
*WskReceiveEvent* event callback function notifies a WSK application that data has been received on a
connection-oriented socket.

## Parameters

### `SocketContext` [in, optional]

A pointer to the socket context for the connection-oriented socket that has received the data. The
WSK application provided this pointer to the WSK subsystem in one of the following ways:

* It called the
  [WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create the socket.
* It called the
  [WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function to create
  the socket.
* It called the
  [WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept) function to accept the socket as an
  incoming connection.
* Its
  [WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event) event callback function
  was called to accept the socket as an incoming connection.

### `Flags` [in]

A ULONG value that contains a bitwise OR of a combination of the following flags:

| Value | Meaning |
| --- | --- |
| **WSK_FLAG_RELEASE_ASAP** | The data buffers that contain the received data should not be retained by the WSK application if at all possible. If the WSK application retains the buffers, it should release them as soon as possible by calling the [WskRelease](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff571144(v=vs.85)) function. |
| **WSK_FLAG_ENTIRE_MESSAGE** | The data buffers contain either an entire message or the final portion of a message. The interpretation of what constitutes an entire message is transport protocol-specific. For TCP, this flag indicates that the push bit was set for one or more of the TCP segments that constitute the data in the data buffers. |
| **WSK_FLAG_AT_DISPATCH_LEVEL** | The WSK subsystem called the *WskReceiveEvent* event callback function at IRQL = DISPATCH_LEVEL. If this flag is not set, the WSK subsystem might have called the *WskReceiveEvent* event callback function at any IRQL <= DISPATCH_LEVEL. |

### `DataIndication` [in, optional]

A pointer to a linked list of
[WSK_DATA_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_data_indication) structures that
describe the received data. If this parameter is **NULL**, the socket is no longer functional and the WSK
application must call the
[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the
socket as soon as possible.

### `BytesIndicated` [in]

The number of bytes of received data described by the linked list of
[WSK_DATA_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_data_indication) structures.

### `BytesAccepted` [in, out]

A pointer to a SIZE_T-typed variable which receives the number of bytes of received data that is
accepted by the WSK application. This variable needs to be set only if the WSK application accepts a
portion of the total number of bytes of received data. If the WSK application accepts all of the
received data, it does not have to set this variable. If the
*WskReceiveEvent* event callback function returns a status other than STATUS_SUCCESS, the WSK
subsystem ignores the value of this variable.

## Return value

A WSK application's
*WskReceiveEvent* event callback function can return one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The WSK application accepted at least some of the received data. If the WSK application accepted all of the received data, the WSK subsystem can call the *WskReceiveEvent* event callback function again when new data is received on the socket. However, if the WSK application accepted only a portion of the received data, the WSK subsystem will not call the *WskReceiveEvent* event callback function again until after the WSK application calls the [WskReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive) function. After the WSK application calls the **WskReceive** function, the WSK subsystem will resume calling the *WskReceiveEvent* event callback function with any remaining buffered data and when new data is received on the socket. A WSK application can call the **WskReceive** function with a zero-length buffer, which will cause the WSK subsystem to resume calling the *WskReceiveEvent* event callback function without calling **WskReceive** to receive any data from the socket. |
| **STATUS_PENDING** | The WSK application accepted the data but did not retrieve all of the data contained in the linked list of [WSK_DATA_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_data_indication) structures. The WSK application retains the linked list of WSK_DATA_INDICATION structures until all of the data has been retrieved. After the WSK application has retrieved all of the data it calls the [WskRelease](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff571144(v=vs.85)) function to release the linked list of WSK_DATA_INDICATION structures back to the WSK subsystem. The WSK subsystem can call the *WskReceiveEvent* event callback function again when new data is received on the socket. |
| **STATUS_DATA_NOT_ACCEPTED** | The WSK application did not accept the data. In this situation, the WSK subsystem will have the underlying transport buffer the data if possible or if otherwise required by the protocol. The WSK subsystem will not call the *WskReceiveEvent* event callback function again until after the WSK application calls the [WskReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive) function. After the WSK application calls the **WskReceive** function, the WSK subsystem will resume calling the *WskReceiveEvent* event callback function with any remaining buffered data and when new data is received on the socket. A WSK application can call the **WskReceive** function with a zero-length buffer, which will cause the WSK subsystem to resume calling the *WskReceiveEvent* event callback function without calling **WskReceive** to receive any data from the socket. |

## Remarks

The WSK subsystem calls a WSK application's
*WskReceiveEvent* event callback function when new data is received on a connection-oriented socket
only if the event callback function was previously enabled with the
[SO_WSK_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback) socket option.
For more information about enabling a socket's event callback functions, see
[Enabling and
Disabling Event Callback Functions](https://learn.microsoft.com/windows/win32/api/evntprov/nc-evntprov-penablecallback).

If a WSK application's
*WskReceiveEvent* event callback function is enabled on a connection-oriented socket and the
application also has a pending call to the
[WskReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive) function on the same
connection-oriented socket, then, when data arrives, the pending call to the
**WskReceive** function will take precedence over the
*WskReceiveEvent* event callback function. The WSK subsystem calls the application's
*WskReceiveEvent* event callback function only if there are no IRPs queued from pending calls to the
**WskReceive** function. However, a WSK application should not assume that the WSK subsystem will not
call the application's
*WskReceiveEvent* event callback function for a connection-oriented socket that has a pending call to
the
**WskReceive** function. Race conditions exist where the WSK subsystem could still call the WSK
application's
*WskReceiveEvent* event callback function for the socket. The only way for a WSK application to
ensure that the WSK subsystem will not call the application's
*WskReceiveEvent* event callback function for a connection-oriented socket is to disable the
application's
*WskReceiveEvent* event callback function on the socket.

> [!NOTE]
> Winsock Kernel (WSK) calls this callback serially, so it is not always invoked as soon as data is received.

The WSK subsystem calls a WSK application's
*WskReceiveEvent* event callback function at IRQL <= DISPATCH_LEVEL.

A WSK application's *WskReceiveEvent* event callback function must not wait for completion of other WSK requests in the context of WSK completion or event callback functions. The callback can initiate other WSK requests (assuming that it doesn't spend too much time at DISPATCH_LEVEL), but it must not wait for their completion even when the callback is called at IRQL = PASSIVE_LEVEL.

## See also

[WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch)

[WSK_DATA_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_data_indication)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive)

[WskRelease](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff571144(v=vs.85))

[WskSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)