# NDIS_SWITCH_SET_NET_BUFFER_LIST_SOURCE callback function

## Description

The *SetNetBufferListSource* function sets the Hyper-V extensible switch source port identifier and network adapter index for a packet that is specified by a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `NetBufferList`

A pointer to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for a single packet.

**Note** This structure must contain an extensible switch forwarding context that was previously allocated by calling the [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) function. For more information about the extensible switch forwarding context, see [Hyper-V Extensible Switch Forwarding Context](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-forwarding-context).

### `PortId` [in]

An NDIS_SWITCH_PORT_ID value that specifies the unique identifier of the source port on the extensible switch.

### `NicIndex` [in]

An NDIS_SWITCH_NIC_INDEX value that specifies the index of the network adapter that is connected to the extensible switch port specified by the *PortId* parameter.

For more information on NDIS_SWITCH_NIC_INDEX values, see [Network Adapter Index Values](https://learn.microsoft.com/windows-hardware/drivers/network/network-adapter-index-values).

**Note** This parameter must specify the index value of a network adapter that is in a connected state. Index values for network adapters that are in a created or disconnected state cannot be specified. For more information about network connection states, see [Hyper-V Extensible Switch Port and Network Adapter States](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-port-and-network-adapter-states).

## Return value

If the call succeeds, the function returns NDIS_STATUS_SUCCESS. Otherwise, it returns an NDIS_STATUS_*Xxx* error code that is defined in Ndis.h.

## Remarks

The extensible switch extension calls the *SetNetBufferListSource* function to set the source port identifier and network adapter index in a packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. The extension does this for the following types of packets:

* A new packet that the extension has allocated for send or receive operations.

  **Note** Before the extension calls *SetNetBufferListSource* for an allocated packet, it must call [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context).
* A duplicated packet that the extension had cloned from an original packet that it was filtering. The extension duplicates a packet by calling [NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist).

In both cases, a new or duplicated packet will have its source port identifier set to **NDIS_SWITCH_DEFAULT_PORT_ID** and its source network adapter index set to **NDIS_SWITCH_DEFAULT_NIC_INDEX**. The extension calls the *SetNetBufferListSource* function to change the source port identifier and network adapter index in a packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

For example, a packet that has a source port identifier of **NDIS_SWITCH_DEFAULT_PORT_ID** is trusted and bypasses many extensible switch port policies. These policies include access control lists (ACLs) and quality of service (QoS). If the extension specifies a non-default source port for the packet, this allows the policies for that port to be applied to the packet.

**Note** Because packets with a source port identifier of **NDIS_SWITCH_DEFAULT_PORT_ID** are trusted, the extension must use this source port identifier very carefully when it originates packet traffic. For more information on the recommended use of the **NDIS_SWITCH_DEFAULT_PORT_ID** for source ports, see [Managing Hyper-V Extensible Switch Source Port Data](https://learn.microsoft.com/windows-hardware/drivers/network/managing-hyper-v-extensible-switch-source-port-data).

For more information on packet send and receive operations, see [Filter Module Send and Receive Operations](https://learn.microsoft.com/windows-hardware/drivers/network/filter-module-send-and-receive-operations).

## See also

[AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)