# _MPIO_DISK_INFO structure

## Description

The MPIO_DISK_INFO structure allows applications to query the system for the top level view of its disk topology. The request must be directed to the MPIO control object by using its WMI instance name.

## Members

### `NumberDrives`

An unsigned 32-bitfield that represents the number of multi-path disks in the system.

### `DriveInfo`

An array that returns the information representing each multi-path LUN (pseudo-LUN) in the system. The number of elements in the array is given by *NumberDrives* and each element represents an instance of an MPIO_DRIVE_INFO structure.