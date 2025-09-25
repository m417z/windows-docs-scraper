# _MPIO_CONTROLLER_CONFIGURATION structure

## Description

The MPIO_CONTROLLER_CONFIGURATION structure provides a top-level view of the storage controllers and the targets that are connected to them in the system.

## Members

### `NumberControllers`

An unsigned 32-bitfield that represents the total number of controllers on the system that are known to MPIO.

### `ControllerInfo`

An array with information about all the controllers and all targets in the system. The number of elements of the array is given by *NumberControllers* and each element of the array is an instance of an MPIO_CONTROLLER_INFO structure.