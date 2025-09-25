# NDIS_SWITCH_GET_NET_BUFFER_LIST_SWITCH_CONTEXT callback function

## Description

The Hyper-V extensible switch extension calls the GetNetBufferListSwitchContext function to retrieve the switch context previously set on the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list).

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `NetBufferList` [in]

A pointer to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for a single packet that contains the context to be retrieved.

**Note** This structure must contain an extensible switch forwarding context. If the extension created or cloned the packet, it must have previously allocated this structure by calling the AllocateNetBufferListForwardingContext function.

### `ContextType` [in]

Context

Context type declared using the *NDIS_DECLARE_SWITCH_NET_BUFFER_LIST_CONTEXT_TYPE* that was used when setting the context.

## Return value

NULL if no context was found in the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) that matches the specified context type. Otherwise, a non-NULL pointer to the buffer is returned.

## Remarks

The [SetNetBufferListSwitchContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_set_net_buffer_list_switch_context) APIs allow extensions to attach context to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) on ingress and retrieve it on egress. Even so, extensions should be resilient to the ingress context not being present on egress. The switch context is not preserved when an NET_BUFFER_LIST is cloned, so in scenarios where the NET_BUFFER_LIST is cloned between ingress and egress, the NET_BUFFER_LIST will not have the original's switch context.

The extension must manage the lifetime of the context. One approach is to allocate NDIS NET_BUFFER_LIST context (using [NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext), or preconfigured if the extension owns the NET_BUFFER_LIST pool), and use the [SetNetBufferListSwitchContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_set_net_buffer_list_switch_context) to associate a context type identifier with the NDIS NET_BUFFER_LIST context. When the NBL is completed, the extension can free the NDIS NET_BUFFER_LIST context (using [NdisFreeNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlistcontext), or freeing the NET_BUFFER_LIST itself if it was originated by the extension).

For more information about the extensible switch forwarding context, see [Hyper-V Extensible Switch Forwarding Context](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-forwarding-context).

## See also

[AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context)

[GetNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_destinations)

[NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest)

[SetNetBufferListSwitchContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_set_net_buffer_list_switch_context)