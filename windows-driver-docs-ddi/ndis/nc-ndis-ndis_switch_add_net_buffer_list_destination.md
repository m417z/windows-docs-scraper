# NDIS_SWITCH_ADD_NET_BUFFER_LIST_DESTINATION callback function

## Description

The *AddNetBufferListDestination* function adds a single destination port for a packet that is specified by a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `NetBufferList` [in, out]

A pointer to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for a packet.

**Note** This structure must contain an extensible switch forwarding context. If the extension created or cloned the packet, it must have previously allocated this structure by calling the [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) function.

### `Destination` [in]

A pointer to an [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) structure. This structure specifies the destination extensible switch port that the packet will be forwarded to.

## Return value

If the call succeeds, the function returns NDIS_STATUS_SUCCESS. Otherwise, it returns an NDIS_STATUS_*Xxx* error code that is defined in Ndis.h.

## Remarks

The forwarding extensible switch extension calls *AddNetBufferListDestination* to define a single extensible switch destination port for a packet. The extension specifies this port by initializing an [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) structure. The extension sets the *Destination* parameter to a pointer to this structure. For more information on how to specify an extensible switch destination port, see [Managing Hyper-V Extensible Switch Destination Port Data](https://learn.microsoft.com/windows-hardware/drivers/network/managing-hyper-v-extensible-switch-destination-port-data).

**Note** For performance reasons, the extension should not call *AddNetBufferListDestination* packets with multiple destination ports.

The extension must follow these guidelines before it calls *AddNetBufferListDestination*:

* Only forwarding extensions can call *AddNetBufferListDestination* to add a destination port for a packet. For more information on this type of extension, see [Forwarding Extensions](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-extensions).
* If the forwarding extension is originating a packet with one destination port, the extension must first call the [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) function. This function allocates the extensible switch forwarding context for the packet. This data contains the extensible switch source and destination ports within the out-of-band (OOB) information for the packet.

  For more information about this context, see [Hyper-V Extensible Switch Forwarding Context](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-forwarding-context).
* After the extension modifies the destination port information in the [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) structure, it calls *AddNetBufferListDestination* to commit the changes to the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for the packet.

  **Note** For performance reasons, the extension should not call the [UpdateNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_update_net_buffer_list_destinations) function to commit the changes for the packet.

**Note** After the forwarding extension commits the changes for destination ports to the forwarding context, destination ports cannot be removed and only the **IsExcluded** member of a destination port's [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) structure can be changed. For more information, see [Excluding Packet Delivery to Extensible Switch Destination Ports](https://learn.microsoft.com/windows-hardware/drivers/network/excluding-packet-delivery-to-extensible-switch-destination-ports).

## See also

[GetNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_destinations)

[NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[UpdateNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_update_net_buffer_list_destinations)