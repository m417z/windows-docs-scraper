# IoSetSystemPartition function

## Description

The **IoSetSystemPartition** routine sets the boot partition for the system.

## Parameters

### `VolumeNameString` [in]

Pointer to a Unicode string that specifies the MS-DOS name of the system partition.

## Return value

STATUS_SUCCESS if the boot partition can be set, or an error code on failure.

## Remarks

The specified partition must contain the boot loader.