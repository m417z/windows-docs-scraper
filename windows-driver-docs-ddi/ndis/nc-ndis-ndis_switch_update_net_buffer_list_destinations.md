# NDIS_SWITCH_UPDATE_NET_BUFFER_LIST_DESTINATIONS callback function

## Description

The Hyper-V extensible switch extension calls the *UpdateNetBufferListDestinations* function to commit modifications that the extension made to a packet that contains multiple extensible switch destination ports. The function saves these modifications to the out-of-band (OOB) extensible switch forwarding context of the packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `NetBufferList` [in, out]

A pointer to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for a single packet.

**Note** This structure must contain an extensible switch forwarding context. If the extension created or cloned the packet, it must have previously allocated this structure by calling the [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) function.

### `NumberOfNewDestinations` [in]

A UINT32 value that specifies the number of new destination ports that were added to the packet.

### `Destinations` [in]

A pointer to an [NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array) structure. This structure specifies the extensible switch destination ports of the packet.

**Note** The extension received this structure through a previous call to the [GetNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_destinations) function.

## Return value

If the call succeeds, the function returns NDIS_STATUS_SUCCESS. Otherwise, it returns an NDIS_STATUS_*Xxx* error code that is defined in Ndis.h.

## Remarks

The extensible switch extension calls the [GetNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_destinations) function to obtain an array of the extensible switch destination ports for a packet. If the function returns successfully, the array is obtained through the *Destinations* parameter, which contains a pointer to a [NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array) structure. Each element in this array is formatted as an [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) structure that specifies a destination port for the packet.

After the extension obtains the [NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array) structure, the extension can do the following:

* Add additional [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) elements in the array.

  For more information, see [Adding Extensible Switch Destination Port Data to a Packet](https://learn.microsoft.com/windows-hardware/drivers/network/adding-extensible-switch-destination-port-data-to-a-packet).
* Modify existing [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) elements of the array to exclude a packet from being forwarded to a specified port.

  For more information, see [Excluding Packet Delivery to Extensible Switch Destination Ports](https://learn.microsoft.com/windows-hardware/drivers/network/excluding-packet-delivery-to-extensible-switch-destination-ports).

If the extension adds or modifies destination ports in the [NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array) structure, the extension must call the *UpdateNetBufferListDestinations* function to commit those changes to the packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

**Note** Only forwarding extensions can call *UpdateNetBufferListDestinations* to commit destination ports that were added or changed for packets with multiple destination ports. For more information on this type of extension, see [Forwarding Extensions](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-extensions).

If the call to *UpdateNetBufferListDestinations* returns NDIS_STATUS_SUCCESS, the extensible switch interface guarantees that the extensible switch port and network adapter connection that are referenced in the destination ports will not be deleted until the packet's send or receive operation is completed.

Also, after the changes for destination ports have been committed, destination ports cannot be removed, and only the **IsExcluded** member of a destination port's [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) structure can be changed. For more information, see [Excluding Packet Delivery to Extensible Switch Destination Ports](https://learn.microsoft.com/windows-hardware/drivers/network/excluding-packet-delivery-to-extensible-switch-destination-ports).

**Note** For performance reasons, the extension should not call the *UpdateNetBufferListDestinations* function to commit the changes to a packet with only one destination port.
Instead, the extension calls [AddNetBufferListDestination](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_add_net_buffer_list_destination) to commit the changes to the packet's destination port.

For more information about the extensible switch forwarding context, see [Hyper-V Extensible Switch Forwarding Context](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-forwarding-context).

## See also

[AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context)

[GetNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_destinations)

[NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[NdisFOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequest)

[OID_SWITCH_NIC_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-delete)