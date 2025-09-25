# REFS_SMR_VOLUME_GC_METHOD enumeration

## Description

The **REFS_SMR_VOLUME_GC_METHOD** enum specifies the garbage collection method or strategy for [**FSCTL_SET_REFS_SMR_VOLUME_GC_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-refs-smr-volume-gc-parameters).

## Constants

### `SmrGcMethodCompaction:1`

Specifies the use of the compaction method for garbage collection.

### `SmrGcMethodCompression:2`

Specifies the use of the compression method for garbage collection.

### `SmrGcMethodRotation:3`

Specifies the use of the rotation method for garbage collection. Moves data from one tier to another.

## Remarks

Currently the only supported value is **SmrGcMethodCompaction**.

## See also

[**FSCTL_SET_REFS_SMR_VOLUME_GC_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-refs-smr-volume-gc-parameters)