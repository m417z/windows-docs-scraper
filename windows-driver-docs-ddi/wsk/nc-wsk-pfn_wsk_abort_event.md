# PFN_WSK_ABORT_EVENT callback function

## Description

The
*WskAbortEvent* event callback function notifies a WSK application that an incoming connection request
on a listening socket that has conditional accept mode enabled has been dropped.

## Parameters

### `SocketContext` [in, optional]

A pointer to the socket context for the listening socket on which the incoming connection request
was received. The WSK application provided this pointer to the WSK subsystem when it called the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create the listening
socket.

### `InspectID` [in]

A pointer to a
[WSK_INSPECT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_inspect_id) structure. The contents of
the structure identify the incoming connection request that has been dropped.

## Return value

A WSK application's
*WskAbortEvent* event callback function must always return STATUS_SUCCESS.

## Remarks

The WSK subsystem calls a WSK application's
*WskAbortEvent* event callback function only when the following conditions are true:

* The WSK application created a listening socket that has conditional accept mode enabled.
* An incoming connection request has been received on the listening socket, and the WSK subsystem has
  called the WSK application's
  [WskInspectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_event) event callback
  function.
* The WSK application returned
  **WskInspectPend** or **WskInspectAccept** from its
  *WskAbortEvent* event callback function for the incoming connection request.
* The incoming connection request has been dropped either locally or remotely before being fully established.

When the WSK subsystem calls a WSK application's
*WskAbortEvent* event callback function, the application should terminate the inspection for the
incoming connection request. The connection request is identified by the contents of the
[WSK_INSPECT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_inspect_id) structure that is pointed to
by the
*InspectID* parameter.

If the WSK application calls the
[WskInspectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_complete) function on an incoming connection request that has been aborted, the connection
will not be established even if
**WskInspectAccept** is specified in the
*Action* parameter.

A WSK application can enable conditional accept mode on a listening socket by enabling the
[SO_CONDITIONAL_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/network/so-conditional-accept) socket option.
For more information about conditionally accepting incoming connections, see
[Listening for and
Accepting Incoming Connections](https://learn.microsoft.com/windows-hardware/drivers/network/listening-for-and-accepting-incoming-connections).

The WSK subsystem calls a WSK application's
*WskAbortEvent* event callback function at IRQL <= DISPATCH_LEVEL.

A WSK application's *WskAbortEvent* event callback function must not wait for completion of other WSK requests in the context of WSK completion or event callback functions. The callback can initiate other WSK requests (assuming that it doesn't spend too much time at DISPATCH_LEVEL), but it must not wait for their completion even when the callback is called at IRQL = PASSIVE_LEVEL.

## See also

[WSK_CLIENT_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_listen_dispatch)

[WSK_INSPECT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_inspect_id)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskInspectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_complete)

[WskInspectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_event)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)