## Description

The **WskSendMessages** function sends multiple datagrams to a remote transport address.

## Parameters

### `Socket` [in]

A pointer to a [**WSK_SOCKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object to send the datagrams from.

### `BufferList` [in]

A pointer to an initialized [**WSK_BUF_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-wsk_buf_list) structure that contains the list of datagrams to send.

### `Flags`

[Reserved] This parameter is reserved for system use. A WSK application must set this parameter to **zero**.

### `RemoteAddress` [in, optional]

A pointer to a structure that specifies the remote transport address to send the datagrams to.

### `ControlInfoLength` [in]

The number of bytes of data in the buffer that is pointed to by the **ControlInfo** parameter. If there is no control information associated with the datagram, the **ControlInfoLength** parameter must be **zero**.

### `ControlInfo` [In_reads_bytes_opt]

A pointer to a buffer that contains control information that is associated with the datagrams that
are being sent. The control information data consists of one or more control data objects, each of which begins with a [**CMSGHDR**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr) structure. If there is no control information that is associated with the datagrams, this parameter should be **NULL**.

**ControlInfo** may not be supported by all transports.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the send operation asynchronously. For more information about using IRPs with WSK functions, see [Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

|Return code|Description|
|--- |--- |
|**STATUS_SUCCESS**|The datagrams were successfully sent over the socket. The IRP will be completed with success status. The **IoStatus.Information** field of the IRP contains the number of bytes that were sent.|
|**STATUS_PENDING**|The WSK subsystem could not send the datagrams over the socket immediately. The WSK subsystem will complete the IRP after it has sent the datagrams over the socket. The status of the send operation will be returned in the **IoStatus.Status** field of the IRP. If the operation succeeds, the **IoStatus.Information** field of the IRP will contain the number of bytes that were sent.|
|**Other status codes**|An error occurred. The IRP will be completed with failure status.|

## Remarks

## See also

[**WSK_SOCKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[**WSK_BUF_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-wsk_buf_list)

[**CMSGHDR**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr)

[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions)