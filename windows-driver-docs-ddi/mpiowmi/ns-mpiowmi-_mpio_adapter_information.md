# _MPIO_ADAPTER_INFORMATION structure

## Description

The MPIO_ADAPTER_INFORMATION structure contains information that pertains to MPIO's view of a path.

## Members

### `PathId`

An unsigned 64-bitfield that represents an identifier that is assigned to a particular path. This field will match the PathIdentifier field in the instance(s) of the PDO_INFORMATION class that represent device(s) exposed via this path.

### `BusNumber`

An unsigned 8-bitfield that corresponds to the bus number that is assigned by PCI to the host bus adapter through which this path is exposed.

### `DeviceNumber`

An unsigned 8-bitfield that corresponds to the device number that is assigned by PCI to the host bus adapter through which this path is exposed.

### `FunctionNumber`

An unsigned 8-bitfield that corresponds to the function number that is assigned by PCI to the host bus adapter through which this path is exposed.

### `Pad`

Should be zero.

### `AdapterName`

A string field that returns the friendly name of the host bus adapter through which this path is exposed.