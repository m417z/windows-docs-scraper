# NDIS_SWITCH_SET_NET_BUFFER_LIST_SWITCH_CONTEXT callback function

## Description

The Hyper-V extensible switch extension calls the *SetNetBufferListSwitchContext* function to attach an extension-allocated context buffer to the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list). The context is then accessible for the lifetime of that NET_BUFFER_LIST, including if the context is set on ingress and the NBL is seen again on egress, regardless of whether other extensions set their own context. This type of access is not possible using the existing NDIS NET_BUFFER_LIST context APIs ([NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext)/ [NET_BUFFER_LIST_CONTEXT_DATA_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_start)) because another extension can allocate NDIS context when it gets ownership of the NET_BUFFER_LIST, at which point the pointer to the original NDIS context is lost.

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `NetBufferList` [in, out]

A pointer to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for a single packet that receives the context association.

**Note** This structure must contain an extensible switch forwarding context. If the extension created or cloned the packet, it must have previously allocated this structure by calling the [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) function.

### `ContextType` [in]

The context type declared using *NDIS_DECLARE_SWITCH_NET_BUFFER_LIST_CONTEXT_TYPE* that will be used as the key when retrieving the context.

### `Context` [in]

The pointer to the context that will be retrievable using the specified *ContextType*.

## Return value

If the call succeeds, the function returns NDIS_STATUS_SUCCESS. Otherwise, it returns an NDIS_STATUS_*Xxx* error code that is defined in Ndis.h.

## Remarks

The *SetNetBufferListSwitchContext* APIs allow extensions to attach context to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) on ingress and retrieve it on egress. Even so, extensions should be resilient to the ingress context not being present on egress. The switch context is not preserved when an NET_BUFFER_LIST is cloned, so in scenarios where the NET_BUFFER_LIST is cloned between ingress and egress, the NET_BUFFER_LIST will not have the original's switch context.

The extension must manage the lifetime of the context. One approach is to allocate NDIS NET_BUFFER_LIST context (using [NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext), or preconfigured if the extension owns the NET_BUFFER_LIST pool), and use the *SetNetBufferListSwitchContext* to associate a context type identifier with the NDIS NET_BUFFER_LIST context. When the NBL is completed, the extension can free the NDIS NET_BUFFER_LIST context (using [NdisFreeNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlistcontext), or freeing the NET_BUFFER_LIST itself if it was originated by the extension).

For more information about the extensible switch forwarding context, see [Hyper-V Extensible Switch Forwarding Context](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-forwarding-context).

## See also

[AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context)

[GetNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_destinations)

[GetNetBufferListSwitchContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_switch_context)

[NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest)