# _MPIO_DEVINSTANCE_HEALTH_INFO structure

## Description

The MPIO_DEVINSTANCE_HEALTH_INFO structure is used to query the available health information for every instance of a multi-path disk on each of the paths through which it is exposed.

## Members

### `NumberDevInstancePackets`

An unsigned 32-bitfield that returns the number of health packets that are available and that correspond to the number of available path instances associated with all multi-path disks.

### `Reserved`

Should be zero.

### `DevInstanceHealthPackets`

A field that returns an array with health information about all the available instances of multi-path disks. The number of elements of the array is given by *NbrDevInfoPkts* and each element of the array is an instance of the MPIO_DEVINSTANCE_HEALTH_CLASS structure.