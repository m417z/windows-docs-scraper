# _NDIS_SWITCH_OPTIONAL_HANDLERS structure

## Description

The **NDIS_SWITCH_OPTIONAL_HANDLERS** structure specifies the pointers to the Hyper-V extensible switch handler functions. These functions can be called by an extensible switch extension.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_OPTIONAL_HANDLERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_OPTIONAL_HANDLERS** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_OPTIONAL_HANDLERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_NIC_ARRAY_REVISION_1.

### `AllocateNetBufferListForwardingContext`

A pointer to the [AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context) function.

### `FreeNetBufferListForwardingContext`

A pointer to the [FreeNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_free_net_buffer_list_forwarding_context) function.

### `SetNetBufferListSource`

A pointer to the [SetNetBufferListSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_set_net_buffer_list_source) function.

### `AddNetBufferListDestination`

A pointer to the [AddNetBufferListDestination](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_add_net_buffer_list_destination) function.

### `GrowNetBufferListDestinations`

A pointer to the [GrowNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_grow_net_buffer_list_destinations) function.

### `GetNetBufferListDestinations`

A pointer to the [GetNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_get_net_buffer_list_destinations) function.

### `UpdateNetBufferListDestinations`

A pointer to the [UpdateNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_update_net_buffer_list_destinations) function.

### `CopyNetBufferListInfo`

A pointer to the [CopyNetBufferListInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_copy_net_buffer_list_info) function.

### `ReferenceSwitchNic`

A pointer to the [ReferenceSwitchNic](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_reference_switch_nic) function.

### `DereferenceSwitchNic`

A pointer to the [DereferenceSwitchNic](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_dereference_switch_nic) function.

### `ReferenceSwitchPort`

A pointer to the [ReferenceSwitchPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_reference_switch_port) function.

### `DereferenceSwitchPort`

A pointer to the [DereferenceSwitchPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_dereference_switch_port) function.

### `ReportFilteredNetBufferLists`

A pointer to the [ReportFilteredNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_report_filtered_net_buffer_lists) function.

### `SetNetBufferListSwitchContext`

### `GetNetBufferListSwitchContext`

### `SwitchPDReserved`

## Remarks

The extensible switch handler functions provide support for filtering and forwarding actions that are performed by an extensible switch extension. These actions include the following:

* Allocate or free the forwarding context. This data is stored in the out-of-band (OOB) data of a packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. For more information about the forwarding context, see [Hyper-V Extensible Switch Forwarding Context](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-forwarding-context).
* Get or set the destination ports that are contained in a packet's forwarding context.
* Add destination ports to a packet's forwarding context.

When the extensible switch extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), the *NdisSwitchHandlers* parameter contains a pointer to an **NDIS_SWITCH_OPTIONAL_HANDLERS** structure. An extensible switch extension typically calls **NdisFGetOptionalSwitchHandlers** from its [FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

## See also

[AddNetBufferListDestination](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_add_net_buffer_list_destination)

[AllocateNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_allocate_net_buffer_list_forwarding_context)

[CopyNetBufferListInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_copy_net_buffer_list_info)

[DereferenceSwitchNic](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_dereference_switch_nic)

[DereferenceSwitchPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_dereference_switch_port)

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FreeNetBufferListForwardingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_free_net_buffer_list_forwarding_context)

[GrowNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_grow_net_buffer_list_destinations)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[ReferenceSwitchNic](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_reference_switch_nic)

[ReferenceSwitchPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_reference_switch_port)

[ReportFilteredNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_report_filtered_net_buffer_lists)

[SetNetBufferListSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_set_net_buffer_list_source)

[UpdateNetBufferListDestinations](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_update_net_buffer_list_destinations)