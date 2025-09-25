# NdisMTerminateOffloadComplete function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

An offload target calls the
**NdisMTerminateOffloadComplete** function to complete a terminate offload operation that was initiated
by a previous call to the
[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler) function of the offload target.

## Parameters

### `NdisMiniportHandle` [in]

The handle that the offload target obtained in a previous call to
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver).

### `OffloadBlockList` [in]

A pointer to an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure. The offload target obtained this pointer as an input
parameter to its
[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler) function.

## Remarks

Before calling the
**NdisMTerminateOffloadComplete** function, the offload target must write either of the following
NDIS_STATUS values to the
**Status** member of each NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure in the state tree:

* NDIS_STATUS_SUCCESS

  The offload target successfully terminated the offload of the state object referenced by the
  NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure. If the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure is
  followed by a delegated state structure (*XXX*_OFFLOAD_STATE_DELEGATED), the offload target successfully wrote the delegated variable
  values for that state object to the delegated state structure.
* NDIS_STATUS_FAILURE

  The terminate operation did not succeed. Such a failure is caused by a catastrophic failure that
  resulted in the loss of the state object that was to be terminated. In this case, the offload target
  hardware might not be responding. The host stack might have to abort the connection.

Before calling the
**NdisMTerminateOffloadComplete** function, the offload target must also:

* Complete any outstanding calls to the
  [MiniportInvalidateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_invalidate_offload_handler),
  [MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler),
  [MiniportTcpOffloadReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_receive_handler),
  [MiniportTcpOffloadDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_disconnect_handler),
  [MiniportTcpOffloadForward](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_forward_handler),
  [MiniportTcpOffloadSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_tcp_offload_send_handler), and
  [MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler) functions.
* Ensure that any outstanding calls to the
  [NdisMIndicateStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatestatusex),
  [NdisMOffloadEventIndicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismoffloadeventindicate),
  [NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate),
  and
  [NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate) functions have returned.

If there is outstanding send data on a TCP connection that is being terminated, the offload target
packages such data in net buffers and passes the packaged data to the host stack in a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. In this case,
the offload target specifies a non-**NULL** value for the
**NetBufferListChain** member of the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure for that connection.
(The NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure is in the linked list pointed to by the
*OffloadBlockList* pointer.) The
**NetBufferListChain** member points to the linked list of
**NET_BUFFER_LIST** structures with which the
send data is associated.

When passing outstanding send data to the host stack, the offload target must also specify non-**NULL**
values for the following delegated TCP variables for the connection that is being terminated:

* SndUna
* SndNxt
* SndMax

For more information about passing outstanding send data, see
[Handling Outstanding Send Data During and After an Offload Operation](https://learn.microsoft.com/windows-hardware/drivers/network/handling-outstanding-send-data-during-and-after-an-offload-operation).

If there is no outstanding send data on a TCP connection that is being terminated, the offload target
must specify a **NULL** value for the
**NetBufferListChain** member.

There might be outstanding receive data on a TCP connection that is being uploaded. This is data that
the offload target has received off the wire, processed, and acknowledged. For more information about
processing such data, see
[Handling Buffered Receive Data During a Terminate Offload Operation](https://learn.microsoft.com/windows-hardware/drivers/network/push-timer).

The offload target frees all resources, such as memory, that are associated with the terminated state
objects.

## See also

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[TCP_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated)