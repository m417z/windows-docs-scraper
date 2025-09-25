# NDIS_TCP_OFFLOAD_DISCONNECT_COMPLETE callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

An offload target calls the
**NdisTcpOffloadDisconnectComplete** function to complete a disconnect request that was initiated by a
previous call to the
[MiniportTcpOffloadDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_disconnect_handler) function of the offload target.

## Parameters

### `NdisMiniportHandle` [in]

The handle that the offload target obtained in a previous call to the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

### `NetBufferList` [in]

A pointer to a single
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. The offload
target obtained this pointer as an input parameter to its
[MiniportTcpOffloadDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_disconnect_handler) function.

## Remarks

**Completing an Abortive Disconnect**

If the offload target issued an abortive disconnect, it must do the following before calling the
**NdisTcpOffloadDisconnectComplete** function:

* Complete all outstanding send requests on the connection with a status value of
  NDIS_STATUS_REQUEST_ABORTED. The offload target writes this status value to the
  **Status** member of each NET_BUFFER_LIST structure in the linked list that it passes to the
  [NdisTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_send_complete) function.
* Write a status value to the
  **Status** member of the NET_BUFFER_LIST structure pointed to by the
  *NetBufferList* pointer. A status value of NDIS_STATUS_SUCCESS indicates that the offload target
  successfully sent the RST segment. For a description of the allowable status values, see
  [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list).

**Completing a Graceful Disconnect**

Before completing a graceful disconnect request, the offload target must:

* Write a status value to the
  **Status** member of the NET_BUFFER_LIST structure that it passes to the
  **NdisTcpOffloadDisconnectComplete** function:

  + A value of NDIS_STATUS_SUCCESS indicates that the FIN segment, as well as any user data, was
    successfully sent by the offload target
    and was also acknowledged by the remote host.
  + A value of NDIS_STATUS_UPLOAD_IN_PROGRESS indicates that the TCP connection referenced by
    *NdisMiniportHandle* is being uploaded.
  + A value of NDIS_STATUS_REQUEST_ABORTED indicates that the FIN segment and/or any user data were
    not successfully transmitted by the offload target and acknowledged by the remote host. The host stack
    will eventually terminate the offload of the TCP connection.
* Specify the number of user data bytes that were sent and successfully acknowledged. The offload
  target does this by calling the
  [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro with an
  *id* of
  **TcpOffloadBytesTransferred**.
* Call the
  [NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart) function. The
  *NetBufferList* parameter should point to the NET_BUFFER structure associated with the
  NET_BUFFER_LIST structure that the offload target passes to the
  **NdisTcpOffloadDisconnectComplete** function. The
  *DataOffsetDelta* parameter should specify the number of data bytes from the NET_BUFFER structure
  that were both transmitted by the offload target and also successfully acknowledged by the remote host.
  The
  *FreeMdl* parameter should be **NULL**.

Note that the
**NdisTcpOffloadDisconnectComplete** function returns only the NET_BUFFER_LIST structure and associated
structures that NDIS passed to the offload target's
[MiniportTcpOffloadDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_disconnect_handler) function. The
**NdisTcpOffloadDisconnectComplete** function cannot return NET_BUFFER_LIST structures that NDIS passed
in previous calls to the offload target's
[MiniportTcpOffloadSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_send_handler) function.

## See also

[MiniportTcpOffloadDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_disconnect_handler)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisTcpOffloadSendComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_send_complete)