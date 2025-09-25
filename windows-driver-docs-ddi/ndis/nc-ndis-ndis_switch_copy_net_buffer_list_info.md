# NDIS_SWITCH_COPY_NET_BUFFER_LIST_INFO callback function

## Description

The Hyper-V extensible switch extension calls the *CopyNetBufferListInfo* function to copy the out-of-band (OOB) forwarding context from a source packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure to a destination packet's **NET_BUFFER_LIST** structure. This context includes the extensible switch source port and network adapter information. The extensible switch destination port information can also be copied.

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `DestNetBufferList` [in, out]

A pointer to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for the destination packet to which the extensible switch forwarding context is copied.

### `SrcNetBufferList` [in]

A pointer to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for the source packet from which the extensible switch forwarding context is copied.

### `Flags` [in]

A UINT32 value. When the NDIS_SWITCH_COPY_NBL_INFO_FLAGS_PRESERVE_DESTINATIONS flag is specified, the function copies the extensible switch destination ports from the source packet to the destination packet.

The data that is contained within the source packet's [NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info) union is always copied to the extensible switch forwarding context in the destination packet. This data includes the source port identifiers and index of the network adapter connection from which the packet originated. Depending on the number of extensible switch destination ports that are copied to the destination packet, the NumAvailableDestinations member of the **NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO** union is updated in the destination packet.

For more information about the forwarding context, see [Hyper-V Extensible Switch Forwarding Context](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-forwarding-context).

## Return value

If the call succeeds, the function returns NDIS_STATUS_SUCCESS. Otherwise, it returns an NDIS_STATUS_*Xxx* error code that is defined in Ndis.h.

## Remarks

The extensible switch extension calls the *CopyNetBufferListInfo* function to copy the OOB data from a source packet to a destination packet. This data includes the following:

* The data from the **NetBufferListInfo** array of the source packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.
* The [NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info) data from the source packet's extensible switch forwarding context.
* The data for the extensible switch destination ports from the source packet's extensible switch forwarding context.

  **Note** This data is only copied if the NDIS_SWITCH_COPY_NBL_INFO_FLAGS_PRESERVE_DESTINATIONS flag is specified.

Before the extension calls *CopyNetBufferListInfo*, it must prepare the destination packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure by following these steps:

1. The extension must first initialize a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for the destination packet that is derived from the source packet's **NET_BUFFER_LIST** structure.

   For example, the extension can call [NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist) to create a complete copy of the source packet. The extension can also call [NdisAllocateFragmentNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefragmentnetbufferlist) to create a copy of only a fragment of the source packet. For more information, see [Derived NET_BUFFER_LIST Structures](https://learn.microsoft.com/windows-hardware/drivers/network/derived-net-buffer-list-structures).
2. The extension must call the [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) function to allocate the extensible switch forwarding context for the destination packet. This data is used to store the OOB extensible switch forwarding information, such as a packet's source and destination ports.

**Note** If the extension is creating or cloning the source packet, the extension must have previously called the [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) function for the packet. Source packets that the extension filters through the extensible switch driver stack already contain an allocated extensible switch forwarding context.

## See also

[AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context)

[NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist)

[NdisAllocateFragmentNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefragmentnetbufferlist)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)