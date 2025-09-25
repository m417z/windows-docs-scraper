# _MPIO_PATH_HEALTH_INFO structure

## Description

The MPIO_PATH_HEALTH_INFO structure is used to query the available health information for every path that is exposed to the system.

## Members

### `NumberPathPackets`

An unsigned 32-bitfield that returns the number of health packets available that correspond to the number of available paths under MPIO control.

### `Reserved`

Should be zero.

### `PathHealthPackets`

A field that contains an array with health information about all the available paths under MPIO control. The number of elements of the array is given by NumberPathPackets and each element of the array is an instance of the MPIO_PATH_HEALTH_CLASS structure.