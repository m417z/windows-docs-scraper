## Description

The **PKTMON_PROVIDER_DISPATCH** structure contains callback function pointers that the Packet Monitor provider implements to handle component registration, packet logging, and packet drop operations. This dispatch table defines the provider's interface for processing monitoring requests from clients.

## Members

### `Size`

The size of this structure in bytes, used for version validation and compatibility checking.

### `ComponentRegister`

A pointer to a **[PKTMON_PROVIDER_REGISTER_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_register_component)** callback function that registers a new monitoring component.

### `ComponentUnregister`

A pointer to a **[PKTMON_PROVIDER_UNREGISTER_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_unregister_component)** callback function that unregisters a monitoring component.

### `SetCompProperty`

A pointer to a **[PKTMON_PROVIDER_SET_COMP_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_set_comp_property)** callback function that sets properties on a registered component.

### `EdgeAdd`

A pointer to a **[PKTMON_PROVIDER_ADD_EDGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_add_edge)** callback function that adds a monitoring edge to a component.

### `PacketLog`

A pointer to a **[PKTMON_PROVIDER_PACKET_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_packet_log)** callback function that logs packet flow events.

### `PacketDrop`

A pointer to a **[PKTMON_PROVIDER_PACKET_DROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_packet_drop)** callback function that logs packet drop events.

## Remarks

Providers must initialize this structure with their callback implementations and register it with the Packet Monitor infrastructure to handle monitoring operations.

## See also

- [PKTMON_PROVIDER_REGISTER_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_register_component)
- [PKTMON_PROVIDER_PACKET_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_packet_log)
- [PKTMON_PROVIDER_PACKET_DROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_packet_drop)