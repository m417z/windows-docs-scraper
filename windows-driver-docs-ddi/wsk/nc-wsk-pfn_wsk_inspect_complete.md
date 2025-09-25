# PFN_WSK_INSPECT_COMPLETE callback function

## Description

The
**WskInspectComplete** function completes the inspection of a previously pended incoming connection
request that was received on a listening socket that has conditional accept mode enabled.

## Parameters

### `ListenSocket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure. This pointer specifies the
listening socket on which the WSK application received the incoming connection request that it is
inspecting.

### `InspectID` [in]

A pointer to a
[WSK_INSPECT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_inspect_id) structure. The contents of
the structure identify the specific connection request that the WSK application is inspecting.

### `Action` [in]

A value that specifies whether the WSK application accepts or rejects the incoming connection
request. A WSK application must specify either
**WskInspectAccept** or
**WskInspectReject** for this parameter.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the resume operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskInspectComplete** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The previously pended inspect operation was successfully resumed. The IRP will be completed with success status. |
| **STATUS_PENDING** | The WSK subsystem could not resume the inspect operation immediately. The WSK subsystem will complete the IRP after it has resumed the inspect operation of the incoming connection request. The status of resuming the inspect operation will be returned in the **IoStatus.Status** field of the IRP. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

A WSK application calls the
**WskInspectComplete** function to complete the inspection of an incoming connection request for which
the application's
[WskInspectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_event) event callback function
previously returned
**WskInspectPend**.

A WSK application can call the
**WskInspectComplete** function only on a listening socket that has conditional accept mode enabled. A
WSK application can enable conditional accept mode on a listening socket by enabling the
[SO_CONDITIONAL_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/network/so-conditional-accept) socket option.
For more information about conditionally accepting incoming connections, see
[Listening for and
Accepting Incoming Connections](https://learn.microsoft.com/windows-hardware/drivers/network/listening-for-and-accepting-incoming-connections).

The WSK subsystem passed a pointer to a
[WSK_INSPECT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_inspect_id) structure to the WSK
application when it called the application's
*WskInspectEvent* event callback function. The WSK application copied the contents of that structure
to its own WSK_INSPECT_ID structure before returning
**WskInspectPend** from the
*WskInspectEvent* event callback function. The WSK application passes a pointer to its own
WSK_INSPECT_ID structure in the
*InspectID* parameter when it calls the
**WskInspectComplete** function.

If a WSK application specifies
**WskInspectAccept** in the
*Action* parameter, the WSK subsystem will continue to establish the socket connection. The WSK
subsystem will return the socket to the WSK application by either completing a call by the WSK
application to the
[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept) function or calling the WSK
application's
[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event) event callback function if
it is enabled. If the incoming connection request is dropped before the socket connection is fully
established, the WSK subsystem will call the WSK application's
[WskAbortEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_abort_event) event callback function.

If a WSK application specifies
**WskInspectReject** in the
*Action* parameter, the incoming connection request is dropped, and the socket connection is not
established.

If the incoming connection request is dropped by the remote system before the WSK application calls
the
**WskInspectComplete** function, the WSK subsystem calls the WSK application's
*WskAbortEvent* event callback function.

If the WSK application calls the
**WskInspectComplete** function on an incoming connection request that has been aborted, the connection
will not be established even if the WSK application specified
**WskInspectAccept** in the
*Action* parameter.

## See also

[SO_CONDITIONAL_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/network/so-conditional-accept)

[WSK_INSPECT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_inspect_id)

[WSK_PROVIDER_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_listen_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskAbortEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_abort_event)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event)

[WskInspectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_event)