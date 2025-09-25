# NDIS_SWITCH_FREE_NET_BUFFER_LIST_FORWARDING_CONTEXT callback function

## Description

The *FreeNetBufferListForwardingContext* function releases resources in the out-of-band (OOB) extensible switch forwarding context of a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This data was used for send or receive operations in a Hyper-V extensible switch, and was previously allocated by calling the [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) function.

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `NetBufferList` [in, out]

A pointer to a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures.

**Note** This structure must contain an extensible switch forwarding context that was previously allocated by calling the [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) function.

## Return value

If the call succeeds, the function returns NDIS_STATUS_SUCCESS. Otherwise, it returns an NDIS_STATUS_*Xxx* error code that is defined in Ndis.h.

## Remarks

The extensible switch extension can originate packet send operations within the extensible switch data path. For example, the extension can send packets to any port on the extensible switch. For more information about this data path, see [Hyper-V Extensible Switch Data Path](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-data-path).

If the extensible switch extension originates a packet send operation, the extension must call the [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) function. This function allocates and initializes the forwarding context for the specified [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. For more information about this context, see [Hyper-V Extensible Switch Forwarding Context](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-forwarding-context).

When the send operation is complete, the extension must call the *FreeNetBufferListForwardingContext* function to deallocate the forwarding context.

**Note** The extension must call the *FreeNetBufferListForwardingContext* function when the send operation is completed. The extension must do this regardless of whether it adds the packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure to a lookaside list or calls [NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist) to return the structure to a pool.

For more information on how to originate send operations, see [Filter Module Send and Receive Operations](https://learn.microsoft.com/windows-hardware/drivers/network/filter-module-send-and-receive-operations).

**Note** If the *NetBufferList* parameter contains a pointer to a linked-list of multiple [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures, only the first **NET_BUFFER_LIST** structure in the list has its forwarding context deallocated.

## See also

[AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist)