# _NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRIES structure

## Description

The **NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRIES** structure represents a series of move operations for all entries in the receive side scaling (RSS) indirection table.

## Members

### `Entries`

An array of [**NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_indirection_entry) structures, each representing a move for an entry in the indirection table.

### `Length`

The number of elements in **Entries**.

## Remarks

NetAdapterCx passes a pointer to this structure as input to a NIC client driver's *[EvtNetAdapterReceiveScalingSetIndirectionEntries](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_set_indirection_entries)* event callback function.

## See also

*[EvtNetAdapterReceiveScalingSetIndirectionEntries](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/nc-netreceivescaling-evt_net_adapter_receive_scaling_set_indirection_entries)*

[**NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netreceivescaling/ns-netreceivescaling-_net_adapter_receive_scaling_indirection_entry)

[NetAdapterCx Receive Side Scaling](https://learn.microsoft.com/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-)