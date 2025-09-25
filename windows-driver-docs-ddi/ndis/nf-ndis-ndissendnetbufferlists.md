# NdisSendNetBufferLists function

## Description

Protocol drivers call the
**NdisSendNetBufferLists** function to send network data that is contained in a list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures.

## Parameters

### `NdisBindingHandle` [in]

A handle that identifies the target adapter. A previous call to
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) returned this
handle.

### `NetBufferLists` [in]

A pointer to a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. Each
NET_BUFFER_LIST structure describes a list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures.

### `PortNumber` [in]

A port number that identifies a miniport adapter port. The default port number of a miniport
adapter is zero. Protocol drivers that do not use miniport adapter ports should specify the default
port.

### `SendFlags` [in]

Flags that define attributes for the send operation. The flags can be combined with an OR
operation. To clear all the flags, set this member to zero. This function supports the following flags:

#### NDIS_SEND_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_SEND_FLAGS_CHECK_FOR_LOOPBACK

Specifies that NDIS should check for loopback. By default, NDIS does not loop back data to the
driver that submitted the send request. An overlying driver can override this behavior by setting this
flag. When this flag is set, NDIS identifies all the NET_BUFFER structures that contain data that
matches the receive criteria for the binding. NDIS indicates NET_BUFFER structures that match the
criteria to the overlying driver. This flag has no effect on checking for loopback, or looping back,
on other bindings.

## Remarks

After a protocol driver calls
**NdisSendNetBufferLists**, NDIS submits the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures to an underlying
driver's
[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists) function.

The protocol driver must allocate each NET_BUFFER_LIST structure from a pool by calling one of the
following functions:

* [NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist)
* [NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)
* [NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist)

The protocol driver can preallocate NET_BUFFER_LIST structures--for example, in its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. Alternatively, the driver,
can allocate the structures just prior to calling
**NdisSendNetBufferLists** and then free them when the send operation is complete. When NDIS returns a
NET_BUFFER_LIST structure to
[ProtocolSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_send_net_buffer_lists_complete), the miniport driver can prepare the NET_BUFFER_LIST structure
and any associated resources for reuse. Reusing the NET_BUFFER_LIST structures can yield better
performance than returning the structures to a pool and then reallocating them for another send
operation.

A protocol driver must set the
**SourceHandle** member of each NET_BUFFER_LIST structure to the same value that it passes to the
*NdisBindingHandle* parameter. The binding handle provides the information that
NDIS requires to return the NET_BUFFER_LIST structure to the protocol driver after the underlying
miniport driver calls
[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete).

Before calling
**NdisSendNetBufferLists**, a protocol driver can set information that accompanies the send request
with the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro . The
underlying driver can retrieve this information with the NET_BUFFER_LIST_INFO macro.

Before a protocol driver calls
**NdisSendNetBufferLists** with a list of NET_BUFFER_LIST structures, the protocol driver must ensure
that the NET_BUFFER_LIST structures are set up in the order that the network data should be sent over the
wire.

As soon as a protocol driver calls
**NdisSendNetBufferLists**, it relinquishes ownership of the NET_BUFFER_LIST structures and all
associated resources. NDIS calls the
*ProtocolSendNetBufferListsComplete* function to return the structures and data
to the protocol driver. NDIS can collect the structures and data from multiple send requests into a
single linked list of NET_BUFFER_LIST structures before it passes the list to
*ProtocolSendNetBufferListsComplete.*

Until NDIS calls
*ProtocolSendNetBufferListsComplete*, the current status of a
protocol-driver-initiated send is not available to the protocol driver. A protocol driver temporarily
releases ownership of all resources that it allocated for a send request when it calls
**NdisSendNetBufferLists**. A protocol driver should
*never* attempt to examine the NET_BUFFER_LIST structures or any associated data
after calling
**NdisSendNetBufferLists**.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist)

[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)

[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist)

[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport)

[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_send_net_buffer_lists_complete)