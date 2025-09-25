# _MPIO_PATH_INFORMATION structure

## Description

The MPIO_PATH_INFORMATION structure represents a top-level view of all the paths that are under MPIO control. To query the path information, the request must be sent to the MPIO control object by using its WMI instance name.

## Members

### `NumberPaths`

An unsigned 32-bitfield that represents the total number of paths that MPIO is aware of.

### `Pad`

Should be zero.

### `PathList`

An array that returns information about each of the paths. The number of elements in the array is given by *NumberPaths* and each element of the array represents an instance of an MPIO_ADAPTER_INFORMATION structure.