# _MPIO_GET_DESCRIPTOR structure

## Description

The MPIO_GET_DESCRIPTOR structure is used to query for LUN instances that correspond to various paths. This structure retrieves device-path pairing information about a multi-path disk. The target of the request must be a pseudo-LUN that is addressed by using its WMI instance name.

## Members

### `NumberPdos`

An unsigned 32-bitfield that returns the number of real instances of the pseudo-LUN through its various paths.

### `DeviceName`

A string field of maximum-length 63 characters that returns the device name that is created by MPIO for the LUN.

### `PdoInformation`

A field that returns an array of PDO_INFORMATION structures, where the number of elements is given by *NumberPdos*, and each element represents an instance of the LUN that is exposed through a particular path.