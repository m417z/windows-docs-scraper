# NdisCoSendNetBufferLists function

## Description

The
**NdisCoSendNetBufferLists** function sends network data that is contained in a specified list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures.

## Parameters

### `NdisVcHandle` [in]

A handle to a virtual connection (VC) that identifies the target of the send request.

### `NetBufferLists` [in]

A pointer to a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. Each
NET_BUFFER_LIST structure describes a list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures.

### `SendFlags` [in]

Flags that define attributes for the send operation. The flags can be combined with a bitwise OR
operation. To clear all of the flags, set this parameter to zero.
**NdisCoSendNetBufferLists** supports the following flags:

#### NDIS_SEND_FLAGS_DISPATCH_LEVEL

The current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_SEND_FLAGS_CHECK_FOR_LOOPBACK

NDIS should check for loopback. By default, NDIS does not loop back data to the driver that
submitted the send request. An overlying driver can override this behavior by setting
NDIS_SEND_FLAGS_CHECK_FOR_LOOPBACK. When this flag is set, NDIS identifies all of the NET_BUFFER
structures that contain data that matches the receive criteria for the binding. NDIS indicates
NET_BUFFER structures that match the criteria to the overlying driver. This flag does not affect
checking for loopback, or looping back, on other bindings.

## Remarks

After a CoNDIS protocol driver calls
**NdisCoSendNetBufferLists**, NDIS submits the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that the
*NetBufferLists* parameter specifies to an underlying driver's
[MiniportCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_send_net_buffer_lists) function.

The protocol driver must allocate each NET_BUFFER_LIST structure from a pool by calling one of the
following functions:

* [NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist)
* [NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)
* [NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist)

The protocol driver can preallocate NET_BUFFER_LIST structures--for example, in its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. Alternatively, the protocol
driver can allocate the structures immediately prior to calling
**NdisCoSendNetBufferLists** and then can free them when the send operation is complete. When NDIS
returns a NET_BUFFER_LIST structure to the
[ProtocolCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_send_net_buffer_lists_complete) function, the protocol driver can prepare the NET_BUFFER_LIST
structure and any associated resources for reuse. If you reuse the NET_BUFFER_LIST structures, you can
get better performance than returning the structures to a pool and then reallocating them for another
send operation.

A protocol driver must set the
**SourceHandle** member of each
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure to the same value
that it passes at the
*NdisVcHandle* parameter. The source handle provides the information that NDIS requires to return the
NET_BUFFER_LIST structure to the protocol driver after the underlying miniport driver calls the
[NdisMCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcosendnetbufferlistscomplete) function.

Before a protocol driver calls
**NdisCoSendNetBufferLists**, the driver can set information that accompanies the send request with
the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro. The
underlying driver can retrieve this information with the NET_BUFFER_LIST_INFO macro.

Before a protocol driver calls
**NdisCoSendNetBufferLists** with a list of NET_BUFFER_LIST structures, the protocol driver must ensure
that the NET_BUFFER_LIST structures are set up in the order that the network data should be sent.

As soon as a protocol driver calls
**NdisCoSendNetBufferLists**, it no longer owns the NET_BUFFER_LIST structures and all of the
associated resources. NDIS calls the
*ProtocolCoSendNetBufferListsComplete* function to return the structures and data to the protocol
driver. NDIS can collect the structures and data from multiple send requests into a single linked list of
NET_BUFFER_LIST structures before it passes the list to
*ProtocolCoSendNetBufferListsComplete*.

Until NDIS calls
*ProtocolCoSendNetBufferListsComplete*, the current status of a protocol driver-initiated send is
not available to the protocol driver. A protocol driver temporarily releases ownership of all of the
resources that it allocated for a send request when it calls
**NdisCoSendNetBufferLists**. A protocol driver should never attempt to examine the NET_BUFFER_LIST
structures or any associated data after the driver calls
**NdisCoSendNetBufferLists**.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[MiniportCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_send_net_buffer_lists)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist)

[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)

[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist)

[NdisMCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcosendnetbufferlistscomplete)

[ProtocolCoSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_send_net_buffer_lists_complete)