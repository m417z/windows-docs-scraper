# PFN_WSK_CONTROL_SOCKET callback function

## Description

The
**WskControlSocket** function performs control operations on a socket.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the socket on which the control operation is being performed.

### `RequestType` [in]

A value that specifies the type of control operation that is being performed. A WSK application
sets this parameter to one of the following values:

#### WskSetOption

Set the state or value for a socket option.

#### WskGetOption

Get the state or value of a socket option.

#### WskIoctl

Perform an I/O control operation.

### `ControlCode` [in]

If the
*RequestType* parameter is set to
**WskSetOption** or
**WskGetOption**, the
*ControlCode* parameter specifies the particular socket option whose value is being set or
retrieved. For more information about socket options that are supported by the WSK subsystem, see
[WSK Socket Options](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback). The underlying
network protocol might support additional socket options.

If the
*RequestType* parameter is set to
**WskIoctl**, the
*ControlCode* parameter specifies the particular I/O control operation that is being performed. For
more information about I/O control operations that are supported by the WSK subsystem, see
[WSK Socket IOCTL Operations](https://learn.microsoft.com/windows-hardware/drivers/network/sio-wsk-query-ideal-send-backlog). The
underlying network protocol might support additional socket I/O control operations.

### `Level` [in]

The level in the network stack at which the value for a socket option is being either set or
retrieved. For WSK subsystem level socket options, the WSK application should set this parameter to
SOL_SOCKET. For transport protocol or network protocol level socket options, the WSK application should
set this parameter to the appropriate level for the underlying transport.

If the
*RequestType* parameter is set to
**WskIoctl**, the
*Level* parameter is ignored.

### `InputSize` [in]

The number of bytes of data in the buffer that is pointed to by the
*InputBuffer* parameter.

### `InputBuffer` [in, optional]

A caller-allocated buffer that supplies any input data that is required to perform the specified
control operation. If no input data is required for the specified control operation, the WSK application
should set this parameter to **NULL** and set the
*InputSize* parameter to zero.

### `OutputSize` [in]

The size of the buffer that is pointed to by the
*OutputBuffer* parameter.

### `OutputBuffer` [out, optional]

A caller-allocated buffer that receives any output data that is returned by the specified control
operation. If no output data is returned by the specified control operation, the WSK application should
set this parameter to **NULL** and set the
*OutputSize* parameter to zero.

### `OutputSizeReturned` [out, optional]

A pointer to a ULONG-typed variable that receives the number of bytes of data that is returned in
the buffer that is pointed to by the
*OutputBuffer* parameter. A WSK application should set the
*OutputSizeReturned* parameter to **NULL** except when all of the following are true:

* The
  *Irp* parameter is set to **NULL**.
* The operation that is being performed returns output data in the buffer that is pointed to by the
  *OutputBuffer* parameter.
* The number of bytes of output data that is returned by the operation that is being performed is
  unknown.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the control operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

If the
*RequestType* parameter is set to either
**WskSetOption** or
**WskGetOption**, the
*Irp* parameter is required, is optional, or must be **NULL** depending on the particular socket option
that is being set or retrieved. For more information about the requirements for the
*Irp* parameter for each of the supported socket options, see
[WSK Socket Options](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback).

If the
*RequestType* parameter is set to
**WskIoctl**, the
*Irp* parameter is required, is optional, or must be **NULL** depending on the particular I/O control
operation that is being performed. For more information about the requirements for the
*Irp* parameter for each of the supported I/O control operations, see
[WSK Socket IOCTL
Operations](https://learn.microsoft.com/windows-hardware/drivers/network/sio-wsk-query-ideal-send-backlog).

## Return value

**WskControlSocket** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The control operation completed successfully. If the WSK application specified a pointer to an IRP in the *Irp* parameter, the IRP will be completed with success status, and the number of bytes that is returned in the buffer that is pointed to by the *OutputBuffer* parameter will be returned in the **IoStatus.Information** field of the IRP. |
| **STATUS_PENDING** | The WSK subsystem could not complete the control operation immediately. The WSK subsystem will complete the IRP after it has completed the control operation. The status of the control operation will be returned in the **IoStatus.Status** field of the IRP. If the operation succeeds, the number of bytes that is returned in the buffer that is pointed to by the *OutputBuffer* parameter will be returned in the **IoStatus.Information** field of the IRP. |
| **STATUS_EVENT_PENDING** | The WSK subsystem could not complete the control operation immediately. This value is returned only when a WSK application is disabling an event callback function on a socket when there are currently in-progress calls to that event callback function and when the *Irp* parameter is **NULL**. For more information about disabling event callback functions, see [SO_WSK_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback). |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

If a WSK application specifies
**WskSetOption** or
**WskGetOption** in the
*RequestType* parameter, see
[WSK Socket Options](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback) for more information
about how the input and output buffers are used for each socket option.

If a WSK application specifies
**WskIoctl** in the
*RequestType* parameter, see
[WSK Socket IOCTL Operations](https://learn.microsoft.com/windows-hardware/drivers/network/sio-wsk-query-ideal-send-backlog) for
more information about how the input and output buffers are used for each I/O control operation.

If the
**WskControlSocket** function returns STATUS_PENDING, any buffers that are pointed to by the
*InputBuffer* parameter or the
*OutputBuffer* parameter must remain valid until the IRP is completed. If the WSK application
allocated the buffers with one of the
**ExAllocate*Xxx*** functions, it cannot free the memory with the corresponding
**ExFree*Xxx*** function until after the IRP is completed. If the WSK application allocated the buffers on the
stack, it cannot return from the function that calls the
**WskControlSocket** function until after the IRP is completed.

Callers of the
**WskControlSocket** function must be running at IRQL <= DISPATCH_LEVEL except when the
*RequestType* parameter is set to
**WskIoctl** and the
*ControlCode* parameter is set to [SIO_ADDRESS_LIST_QUERY](https://learn.microsoft.com/windows-hardware/drivers/network/sio-address-list-query),
[SIO_ADDRESS_LIST_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/sio-address-list-change), or [SIO_ADDRESS_LIST_SORT](https://learn.microsoft.com/windows/desktop/WinSock/using-sio-address-list-sort). In this
situation, callers must be running at IRQL = PASSIVE_LEVEL.

## See also

[WSK Socket IOCTL Operations](https://learn.microsoft.com/windows-hardware/drivers/network/sio-wsk-query-ideal-send-backlog)

[WSK Socket Options](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback)

[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch)

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WSK_PROVIDER_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_datagram_dispatch)

[WSK_PROVIDER_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_listen_dispatch)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)