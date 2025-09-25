# _MPIO_DRIVE_INFO structure

## Description

The MPIO_DRIVE_INFO structure represents a multi-path disk in the system.

## Members

### `NumberPaths`

An unsigned 32-bitfield that represents the number of paths to the LUN.

### `Name`

A string field (of maximum length 63 characters) that returns the device name that was created by MPIO for the LUN.

### `SerialNumber`

A string field (of maximum length 63 characters) that returns the serial number that was created for the LUN by either the DSM or by MPIO itself.

### `DsmName`

A string field (of maximum length 63 characters) that returns the friendly name of the controlling DSM for the device.