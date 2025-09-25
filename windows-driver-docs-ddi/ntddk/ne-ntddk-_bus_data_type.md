# _BUS_DATA_TYPE enumeration (ntddk.h)

## Description

The **BUS_DATA_TYPE** enumeration indicates the type of bus configuration space.

## Constants

### `ConfigurationSpaceUndefined`

Indicates that the type of bus configuration space is undefined.

### `Cmos`

Indicates CMOS data.

### `EisaConfiguration`

Indicates an EISA bus configuration space.

### `Pos`

For internal use only.

### `CbusConfiguration`

Indicates Cbus configuration space.

### `PCIConfiguration`

Indicates PCI configuration space.

### `VMEConfiguration`

Indicates VME configuration space.

### `NuBusConfiguration`

Indicates NuBus configuration space.

### `PCMCIAConfiguration`

Indicates PCMCIA configuration space.

### `MPIConfiguration`

Indicates MPI configuration space.

### `MPSAConfiguration`

Indicates MPSA configuration space.

### `PNPISAConfiguration`

Indicates PNPISA configuration space.

### `SgiInternalConfiguration`

Indicates SGI internal bus configuration space.

### `MaximumBusDataType`

Indicates the upper limit of the bus configuration space types.

## See also

[HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalSetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalSetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))