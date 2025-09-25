# NET_PHYSICAL_LOCATION_LH structure

## Description

The NET_PHYSICAL_LOCATION structure provides NDIS with information about the physical location of a
registered network interface.

## Members

### `BusNumber`

The bus number of the physical location for hardware. If the physical location is unknown, set
this member to NIIF_BUS_NUMBER_UNKNOWN. Other values are reserved for NDIS.

### `SlotNumber`

The slot number of the physical location for hardware. If the physical location is unknown, set
this member to NIIF_SLOT_NUMBER_UNKNOWN. Other values are reserved for NDIS.

### `FunctionNumber`

The function number of the physical location for hardware. If the physical location is unknown,
set this member to NIIF_FUNCTION_NUMBER_UNKNOWN. Other values are reserved for NDIS.

## Remarks

A network interface provider initializes a
[NET_IF_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_net_if_information) structure to provide
NDIS with information about each registered interface. The NET_PHYSICAL_LOCATION structure is included in
the
**PhysicalLocation** member of the NET_IF_INFORMATION structure.

NET_PHYSICAL_LOCATION contains information that remains constant during the lifetime of the interface.
To register an interface, a provider passes a pointer to a provider-initialized NET_IF_INFORMATION
structure to the
[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/nf-ndis-ndisifregisterinterface) function.

## See also

[NET_IF_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_net_if_information)

[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/nf-ndis-ndisifregisterinterface)