# _NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY structure

## Description

The **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure specifies an array of Hyper-V extensible switch destination ports for a packet. Each element in the array is formatted as an [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) structure.

This information is contained in the out-of-band (OOB) data of the packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY_REVISION_1.

### `ElementSize`

A ULONG value that specifies the size, in bytes, of each [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) element that follows the **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure.

### `NumElements`

A ULONG value that specifies the total number of [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) elements in the **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure.

The value of the **NumElements** member specifies the number of currently used [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) elements (as specified by the **NumDestinations** member) plus the number of elements that are available for new destination ports. The number of unused **NDIS_SWITCH_PORT_DESTINATION** elements in the **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure is calculated by (**NumElements** - **NumDestinations**).

### `NumDestinations`

A ULONG value that specifies the number of [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) elements in the **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure that specify port destinations.

**Note** If **NumElements** is set to zero, this member is ignored.

### `FirstElement`

A pointer to the first [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) element in the buffer that contains the **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure and all its elements.

## Remarks

The extensible switch extension can do the following with the destination ports in a packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure:

* Query the current destination ports on the extensible switch that the packet will be forwarded to.

  The extensible switch extension calls the [GetNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_destinations) function to obtain the array of port destinations for a packet. *GetNetBufferListDestinations* returns a pointer to the **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure in the *Destinations* parameter.

  For more information, see [Querying a Packet's Extensible Switch Destination Port Data](https://learn.microsoft.com/windows-hardware/drivers/network/querying-a-packet-s-extensible-switch-destination-port-data).
* Add or modify the destination ports for the packet.

  After it queries the current destination ports for the packet, the extensible switch extension can do the following:

  + A forwarding extension can add new destination ports to the **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure.
  + A filtering or forwarding extension can modify the data within an [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) structure for a destination port.

    **Note** A filtering extension can only change the **IsExcluded** member of this structure. A forwarding extension can also change the **PreserveVLAN** and **PreservePriority** members.If the extension adds or modifies port destinations, it must call [UpdateNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_update_net_buffer_list_destinations) to commit the changes to the destination ports to the packet's OOB data in the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

  For more information, see [Managing Hyper-V Extensible Switch Destination Port Data](https://learn.microsoft.com/windows-hardware/drivers/network/managing-hyper-v-extensible-switch-destination-port-data).

Extensible switch extensions can use the [NDIS_SWITCH_PORT_DESTINATION_AT_ARRAY_INDEX](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-destination-at-array-index) macro to access [NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) elements in an **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** array.

## See also

[Adding Extensible Switch Destination Port Data to a Packet](https://learn.microsoft.com/windows-hardware/drivers/network/adding-extensible-switch-destination-port-data-to-a-packet)

[Excluding Packet Delivery to Extensible Switch Destination Ports](https://learn.microsoft.com/windows-hardware/drivers/network/excluding-packet-delivery-to-extensible-switch-destination-ports)

[Forwarding Extensions](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-extensions)

[GetNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_destinations)

[Hybrid Forwarding](https://learn.microsoft.com/windows-hardware/drivers/network/hybrid-forwarding)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_SWITCH_PORT_DESTINATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination)

[NDIS_SWITCH_PORT_DESTINATION_AT_ARRAY_INDEX](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-destination-at-array-index)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[Overview of the Hyper-V Extensible Switch](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-the-hyper-v-extensible-switch)

[UpdateNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_update_net_buffer_list_destinations)