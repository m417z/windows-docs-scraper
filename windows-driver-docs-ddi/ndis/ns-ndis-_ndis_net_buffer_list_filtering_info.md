# _NDIS_NET_BUFFER_LIST_FILTERING_INFO structure

## Description

The **NDIS_NET_BUFFER_LIST_FILTERING_INFO** structure defines filtering information that is associated
with a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `FilteringInfo`

A structure that contains the following members:

### `FilteringInfo.FilterId`

A USHORT value that contains a receive filter identifier. The receive filter identifier is an
integer from one to the number of receive filters that the network adapter supports.

**Note** Starting with NDIS 6.20, this member must be set to zero.

### `FilteringInfo.QueueVPortInfo`

A union that contains the following members:

### `FilteringInfo.QueueVPortInfo.QueueId`

A USHORT value that contains an identifier for a virtual machine queue (VMQ) receive queue. The queue identifier is an integer between zero
and the number of queues that the network adapter supports. A value of NDIS_DEFAULT_RECEIVE_QUEUE_ID specifies
the default receive queue.

**Note** Starting with Windows Server 2012, the value of this member must always be set to NDIS_DEFAULT_RECEIVE_QUEUE_ID by miniport drivers that support the SR-IOV interface.

### `FilteringInfo.QueueVPortInfo.VPortId`

A USHORT value that contains the identifier for a virtual port (VPort). A value of NDIS_DEFAULT_VPORT_ID specifies the default VPort on the NIC switch.

The VPort with the specified VPortId value must have previously been created through a set request of [OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport).

**Note** For the VMQ interface, this member must be set to NDIS_DEFAULT_VPORT_ID.

### `Value`

A PVOID type value that is in a union with the
**FilteringInfo** member. This member lets a driver access all the information in the
**NDIS_NET_BUFFER_LIST_FILTERING_INFO** structure as one PVOID value.

## Remarks

Starting with NDIS 6.20, miniport drivers use the **NDIS_NET_BUFFER_LIST_FILTERING_INFO** structure to specify receive
filter information that accompanies the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures that are associated with a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

To access the **NDIS_NET_BUFFER_LIST_FILTERING_INFO** structure from the NET_BUFFER_LIST OOB data, an NDIS
driver calls the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro and specifies
the
**NetBufferListFilteringInfo** information type.

To access the identifier values directly, use the
[NET_BUFFER_LIST_RECEIVE_FILTER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-receive-filter-id), [NET_BUFFER_LIST_RECEIVE_FILTER_VPORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-receive-filter-vport-id), or
[NET_BUFFER_LIST_RECEIVE_QUEUE_ID](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-receive-queue-id) macros.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_RECEIVE_FILTER_ID](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-receive-filter-id)

[NET_BUFFER_LIST_RECEIVE_FILTER_VPORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-receive-filter-vport-id)

[NET_BUFFER_LIST_RECEIVE_QUEUE_ID](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-receive-queue-id)