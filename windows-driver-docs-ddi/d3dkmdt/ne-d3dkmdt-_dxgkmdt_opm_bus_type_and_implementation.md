# DXGKMDT_OPM_BUS_TYPE_AND_IMPLEMENTATION enumeration

## Description

The DXGKMDT_OPM_BUS_TYPE_AND_IMPLEMENTATION enumeration contains values that indicate the type and implementation of the bus that connects a graphics adapter to a motherboard chip set's north bridge. These values let an OPM application determine if it must encrypt data when the data is transferred from a computer's main memory to the graphics adapter.

## Constants

### `DXGKMDT_OPM_BUS_TYPE_OTHER`

Indicates that the graphics adapter does not communicate with the north bridge by using the PCI, PCI-X, PCI Express, or AGP expansion bus.

### `DXGKMDT_OPM_BUS_TYPE_PCI`

Indicates that the PCI bus is used to transfer data from a computer's main memory to the graphics adapter. For information about the PCI bus, see the [PCI Local Bus Specification](https://pcisig.com/specifications/pciexpress).

### `DXGKMDT_OPM_BUS_TYPE_PCIX`

Indicates that the PCI-X bus is used to transfer data from a computer's main memory to the graphics adapter. For information about PCI-X, see the [PCI-X Specification](https://pcisig.com/specifications/pciexpress).

### `DXGKMDT_OPM_BUS_TYPE_PCIEXPRESS`

Indicates that the PCI Express bus is used to transfer data from a computer's main memory to the graphics adapter. For information about PCI Express, see the [PCI Express Specification](https://pcisig.com/specifications/pciexpress).

### `DXGKMDT_OPM_BUS_TYPE_AGP`

Indicates that the Accelerated Graphics Port (AGP) is used to transfer data from a computer's main memory to the graphics adapter.

### `DXGKMDT_OPM_BUS_IMPLEMENTATION_MODIFIER_INSIDE_OF_CHIPSET`

Indicates that the implementation for the graphics adapter is in a motherboard chipset's north bridge. A graphics adapter reports this implementation modifier to imply that data never goes over an expansion bus when data is transferred from main memory to the graphics adapter. PCI, PCI-X, PCI Express, and AGP are examples of expansion buses. This value cannot be combined with DXGKMDT_OPM_BUS_TYPE_PCI, DXGKMDT_OPM_BUS_TYPE_PCIX, DXGKMDT_OPM_BUS_TYPE_PCIEXPRESS, or DXGKMDT_OPM_BUS_TYPE_AGP. This value should only be set if an OPM protected output has OPM semantics.

### `DXGKMDT_OPM_BUS_IMPLEMENTATION_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_CHIP`

Indicates that the graphics adapter is connected to a motherboard chipset's north bridge by tracks on the motherboard and all of the graphics adapter's chips (integrated circuits (ICs)) are soldered to the motherboard. This value can be combined with any bus-type value (DXGKMDT_OPM_BUS_TYPE_PCI, DXGKMDT_OPM_BUS_TYPE_PCIX, DXGKMDT_OPM_BUS_TYPE_PCIEXPRESS, or DXGKMDT_OPM_BUS_TYPE_AGP) and should only be set if an OPM-protected output has OPM semantics. For more information about this bus-implementation modifier, see the Remarks section.

### `DXGKMDT_OPM_BUS_IMPLEMENTATION_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_SOCKET`

Indicates that the graphics adapter is connected to a motherboard chipset's north bridge by tracks on the motherboard and all of the graphics adapter's chips are connected through sockets to the motherboard. This value can be combined with any bus-type value (DXGKMDT_OPM_BUS_TYPE_PCI, DXGKMDT_OPM_BUS_TYPE_PCIX, DXGKMDT_OPM_BUS_TYPE_PCIEXPRESS, or DXGKMDT_OPM_BUS_TYPE_AGP) and should only be set if an OPM-protected output has OPM semantics. For more information about this bus-implementation modifier, see the Remarks section.

### `DXGKMDT_OPM_BUS_IMPLEMENTATION_MODIFIER_DAUGHTER_BOARD_CONNECTOR`

Indicates that the graphics adapter is connected to the motherboard through a daughterboard connector. Mobile PCI Express Module (MXM) and Advanced eXpress I/O Module (Axiom) are examples of daughterboard connectors. This value should be set only if an OPM-protected output has OPM semantics.

### `DXGKMDT_OPM_BUS_IMPLEMENTATION_MODIFIER_DAUGHTER_BOARD_CONNECTOR_INSIDE_OF_NUAE`

Indicates that the graphics adapter is connected to the motherboard through a daughterboard connector and that the graphics adapter is inside a non-user accessible enclosure (NUAE). This value should be set only if an OPM-protected output has OPM semantics.

### `DXGKMDT_OPM_BUS_IMPLEMENTATION_MODIFIER_NON_STANDARD`

(Optional.) Indicates that any of the optional implementation modifier values (DXGKMDT_OPM_BUS_IMPLEMENTATION_MODIFIER_Xxx) are set in the 32-bit bus characteristics ULONG value. For more information about this ULONG, see the Remarks section. This value should be set only if an OPM-protected output has OPM semantics.

### `DXGKMDT_OPM_COPP_COMPATIBLE_BUS_TYPE_INTEGRATED`

This value can only be set if an OPM-protected output has COPP semantics and should not be set if an OPM-protected output has OPM semantics. This value is equivalent to the [COPP](https://learn.microsoft.com/windows-hardware/drivers/display/copp-processing) **COPP_BusType_Integrated** flag that is used in the **dwData** member of the [**DXVA_COPPStatusData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatusdata) structure in the [Windows 2000 Display Driver Model](https://learn.microsoft.com/windows-hardware/drivers/display/windows-2000-display-driver-model-design-guide).

## Remarks

A graphics adapter's display miniport driver should use one bus type (DXGKMDT_OPM_BUS_TYPE_Xxx) and can also use one optional implementation modifier (DXGKMDT_OPM_BUS_IMPLEMENTATION_MODIFIER_Xxx). A graphics adapter must report the DXGKMDT_OPM_BUS_TYPE_OTHER value if its bus cannot be described by any other bus-type value or a combination of a bus-type value and an implementation-modifier value.

OPM stores a bus's characteristics in a 32-bit ULONG value. A graphics adapter's display miniport driver uses the bitwise OR operator (|) to combine a bus-type value, an optional implementation-modifier value, and, possibly, the DXGKMDT_OPM_BUS_IMPLEMENTATION_NON_STANDARD flag. The DXGKMDT_OPM_BUS_IMPLEMENTATION_NON_STANDARD value is optional and is set only if an implementation-modifier value is set. This 32-bit ULONG is used when the Microsoft DirectX graphics kernel subsystem (*Dxgkrnl.sys*) passes the DXGKMDT_OPM_GET_ADAPTER_BUS_TYPE GUID in a call to the [**DxgkDdiOPMGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) or [**DxgkDdiOPMGetCOPPCompatibleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information) function. The driver sets this 32-bit ULONG in the **ulInformation** member of the [**DXGKMDT_OPM_STANDARD_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_standard_information) structure that is retrieved in the **DxgkDdiOPMGetInformation** or **DxgkDdiOPMGetCOPPCompatibleInformation** call. For more information about retrieving the graphics adapter's bus type, see the [Retrieving Information about a Protected Output](https://learn.microsoft.com/windows-hardware/drivers/display/retrieving-information-about-a-protected-output) or [Retrieving COPP-Compatible Information about a Protected Output](https://learn.microsoft.com/windows-hardware/drivers/display/retrieving-copp-compatible-information-about-a-protected-output) section.

When a bus-type value (for example, DXGKMDT_OPM_BUS_TYPE_PCI) is combined with a bus-implementation modifier value (for example, DXGKMDT_OPM_BUS_IMPLEMENTATION_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_CHIP), the graphics adapter uses most of the PCI specification to communicate with the computer. However, the graphics adapter does not use a physical PCI connector. Basically, the only difference between a regular PCI graphics adapter and an adapter with the DXGKMDT_OPM_BUS_IMPLEMENTATION_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_CHIP modifier is that the former is on a card that can be plugged into a PCI slot and the later is directly connected to the motherboard and cannot be removed or upgraded by the user.

## See also

[**DXGKMDT_OPM_STANDARD_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_standard_information)

[**DxgkDdiOPMGetCOPPCompatibleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information)

[**DxgkDdiOPMGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)