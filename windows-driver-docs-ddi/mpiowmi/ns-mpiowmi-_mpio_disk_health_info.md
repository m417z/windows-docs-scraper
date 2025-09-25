# _MPIO_DISK_HEALTH_INFO structure

## Description

The MPIO_DISK_HEALTH_INFO structure is used to query the available health information for every multi-path disk in the system.

## Members

### `NumberDiskPackets`

An unsigned 32-bitfield that returns the number of available health packets that correspond to the number of multi-path disks under MPIO control.

### `Reserved`

Should be zero.

### `DiskHealthPackets`

An array of health information packets for all the available multi-path disks under MPIO control. The number of elements in the array is given by NumberDiskPackets, and each element of the array is an instance of an MPIO_DISK_HEALTH_CLASS structure.