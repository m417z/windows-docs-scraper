# NdisMInitiateOffloadComplete function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

An offload target calls the
**NdisMInitiateOffloadComplete** function to complete an offload operation that was initiated by a
previous call to the
[MiniportInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_initiate_offload_handler) function.

## Parameters

### `NdisMiniportHandle` [in]

The handle that the offload target obtained in a previous call to
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver).

### `OffloadBlockList` [in]

A pointer to an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure. The offload target obtained this pointer as an input
parameter to its
[MiniportInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_initiate_offload_handler) function.

## Remarks

Before calling
**NdisMInitiateOffloadComplete**, the offload target must write one of the following NDIS_STATUS
values to the
**Status** member of each
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure in the state tree passed to the offload target's
*MiniportInitiateOffload* function:

* NDIS_STATUS_SUCCESS
* NDIS_STATUS_PARTIAL_SUCCESS
* NDIS_STATUS_RESOURCES
* NDIS_STATUS_OFFLOAD_TCP_ENTRIES
* NDIS_STATUS_OFFLOAD_PATH_ENTRIES
* NDIS_STATUS_OFFLOAD_NEIGHBOR_ENTRIES
* NDIS_STATUS_OFFLOAD_HW_ADDRESS_ENTRIES
* NDIS_STATUS_OFFLOAD_IP_ADDRESS_ENTRIES
* NDIS_STATUS_OFFLOAD_TCP_XMIT_BUFFER
* NDIS_STATUS_OFFLOAD_TCP_RCV_BUFFER
* NDIS_STATUS_OFFLOAD_TCP_RCV_WINDOW
* NDIS_STATUS_OFFLOAD_VLAN_ENTRIES
* NDIS_STATUS_OFFLOAD_PATH_MTU
* NDIS_STATUS_FAILURE

For more information, see
[Returning Completion Status of an Initiate Offload Operation](https://learn.microsoft.com/windows-hardware/drivers/network/returning-completion-status-of-an-initiate-offload-operation).

## See also

[MiniportInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_initiate_offload_handler)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate)

[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate)

[OID_TCP_TASK_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-offload)