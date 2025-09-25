# _NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRY structure

## Description

The **NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRY** structure represents a move operation for a single entry in the receive side scaling (RSS) indirection table.

## Members

### `PacketQueue`

The new receive queue for the entry.

### `Status`

An NTSTATUS value that indicates the status of the move operation for this entry.

### `Index`

The hash index in the indirection table for this entry.

## Remarks

Each **NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRY** structure is contained within a [NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_indirection_entries) structure.

## See also

*[EvtNetAdapterReceiveScalingSetIndirectionEntries](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_set_indirection_entries)*

[NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_indirection_entries)

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)