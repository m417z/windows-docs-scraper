# NDIS_SWITCH_ALLOCATE_NET_BUFFER_LIST_FORWARDING_CONTEXT callback function

## Description

The *AllocateNetBufferListForwardingContext* function prepares a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for send or receive operations within the extensible switch.

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `NetBufferList` [in, out]

A pointer to a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures.

## Return value

If the call succeeds, the function returns NDIS_STATUS_SUCCESS. Otherwise, it returns an NDIS_STATUS_*Xxx* error code that is defined in Ndis.h.

## Remarks

The extensible switch extension can originate packet send operations within the extensible switch data path. For example, the extension can send packets to any port on the extensible switch. For more information about this data path, see [Hyper-V Extensible Switch Data Path](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-data-path).

After the extension calls [NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist) or [NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist) to create or clone a packet from its [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) pool, the extension must call the *AllocateNetBufferListForwardingContext* function. This function allocates and initializes the out-of-band (OOB) extensible switch forwarding context for the specified **NET_BUFFER_LIST** structure. For more information about this context, see [Hyper-V Extensible Switch Forwarding Context](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-forwarding-context).

The extension must follow these guidelines for allocating the forwarding context through the *AllocateNetBufferListForwardingContext* function:

* The extension calls [NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist) to allocate a packet from the extension's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) pool for a send or receive operation over the extensible switch. Before the extension initializes source and destination ports for the packet, it must call *AllocateNetBufferListForwardingContext*.

  For more information on how to specify source and destination extensible switch ports, see [Managing Hyper-V Extensible Switch Source and Destination Port Data](https://learn.microsoft.com/windows-hardware/drivers/network/managing-hyper-v-extensible-switch-source-and-destination-port-data).
* Before the extension calls *AllocateNetBufferListForwardingContext*, it must set the **SourceHandle** member of each allocated [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure to the handle value that identifies the extension. The extension receives this handle through the *NdisFilterHandle* parameter when NDIS calls the extension's [FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.
* When the send operation is complete, the extension must call the [FreeNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_free_net_buffer_list_forwarding_context) function to deallocate the resources for the forwarding context. The extension must call this function before it calls [NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist) to return the packet to its [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) pool.
* If the extension is cloning a packet, it must call [CopyNetBufferListInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_copy_net_buffer_list_info) to copy the forwarding context from the original packet to the cloned packet. The extension must do this after it calls *AllocateNetBufferListForwardingContext*.

For more information on how to originate send operations, see [Filter Module Send and Receive Operations](https://learn.microsoft.com/windows-hardware/drivers/network/filter-module-send-and-receive-operations).

**Note** If the *NetBufferList* parameter contains a pointer to a linked-list of multiple [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures, only the first **NET_BUFFER_LIST** structure in the list has a forwarding context allocated for it.

## See also

[CopyNetBufferListInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_copy_net_buffer_list_info)

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FreeNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_free_net_buffer_list_forwarding_context)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist)