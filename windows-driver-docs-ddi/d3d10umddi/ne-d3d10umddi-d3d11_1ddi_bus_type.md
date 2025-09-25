# D3D11_1DDI_BUS_TYPE enumeration

## Description

Specifies the type of I/O bus that is used by the graphics adapter.

## Constants

### `D3D11_1DDI_BUS_TYPE_OTHER`

Indicates a type of bus other than the types listed here.

### `D3D11_1DDI_BUS_TYPE_PCI`

PCI bus.

### `D3D11_1DDI_BUS_TYPE_PCIX`

PCI-X bus.

### `D3D11_1DDI_BUS_TYPE_PCIEXPRESS`

PCI Express bus.

### `D3D11_1DDI_BUS_TYPE_AGP`

Accelerated Graphics Port (AGP) bus.

### `D3D11_1DDI_BUS_IMPL_MODIFIER_INSIDE_OF_CHIPSET`

The implementation for the graphics adapter is in a motherboard chipset's north bridge. This flag implies that data never goes over an expansion bus (such as PCI or AGP) when it is transferred from main memory to the graphics adapter.

### `D3D11_1DDI_BUS_IMPL_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_CHIP`

Indicates that the graphics adapter is connected to a motherboard chipset's north bridge by tracks on the motherboard, and all of the graphics adapter's chips are soldered to the motherboard. This flag implies that data never goes over an expansion bus (such as PCI or AGP) when it is transferred from main memory to the graphics adapter.

### `D3D11_1DDI_BUS_IMPL_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_SOCKET`

The graphics adapter is connected to a motherboard chipset's north bridge by tracks on the motherboard, and all of the graphics adapter's chips are connected through sockets to the motherboard.

### `D3D11_1DDI_BUS_IMPL_MODIFIER_DAUGHTER_BOARD_CONNECTOR`

The graphics adapter is connected to the motherboard through a daughterboard connector.

### `D3D11_1DDI_BUS_IMPL_MODIFIER_DAUGHTER_BOARD_CONNECTOR_INSIDE_OF_NUAE`

The graphics adapter is connected to the motherboard through a daughterboard connector, and the graphics adapter is inside an enclosure that is not user accessible.

### `D3D11_1DDI_BUS_IMPL_MODIFIER_NON_STANDARD`

One of the D3D11_1DDI_BUS_IMPL_MODIFIER_Xxx flags is set.