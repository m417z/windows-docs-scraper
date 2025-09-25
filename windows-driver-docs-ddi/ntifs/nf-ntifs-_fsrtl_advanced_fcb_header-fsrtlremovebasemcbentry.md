# FsRtlRemoveBaseMcbEntry function

## Description

The **FsRtlRemoveBaseMcbEntry** function is the work routine for removing a large map control block (MCB) entry. It does so without taking out the mcb GuardedMutex.

## Parameters

### `Mcb`

Supplies the Mcb from which to remove the mapping.

### `Vbn`

Supplies the starting virtual block number (VBN) of the mappings to remove.

### `SectorCount`

Supplies the size of the mappings to remove, in sectors.

## Return value

This function returns TRUE if the MCB is removed.

## Remarks

## See also