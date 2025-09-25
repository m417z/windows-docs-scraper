# _GetPathConfiguration_OUT structure

## Description

The GetPathConfiguration_OUT structure is used to report the output parameters that are associated with the GetPathConfiguration method.

## Members

### `EntryCount`

A 32-bitfield that indicates the number of entries contained in the array of SCSI addresses.

### `Address`

An array that returns information about the SCSI addresses. The number of elements in the array is given by EntryCount and each element of the array represents an instance of an SCSI_ADDR structure.