# REFS_SMR_VOLUME_INFO_OUTPUT structure

## Description

The **REFS_SMR_VOLUME_INFO_OUTPUT** structure describes a Shingled Magnetic Recording (SMR) volume's current state on space and garbage collection activities.

## Members

### `Version`

Currently ignored. Will be set to zero for now.

### `Flags`

Currently ignored. Will be set to zero for now.

### `SizeOfRandomlyWritableTier`

Specifies the total size of the randomly writable tier.

### `FreeSpaceInRandomlyWritableTier`

Specifies the free space within the randomly writable tier.

### `SizeofSMRTier`

Specifies the total size of the Shingled Magnetic Recording (SMR) tier.

### `FreeSpaceInSMRTier`

Specifies the free space the Shingled Magnetic Recording (SMR) tier.

### `UsableFreeSpaceInSMRTier`

Specifies the usable space the Shingled Magnetic Recording (SMR) tier.

### `VolumeGcState`

Specifies the current state of the garbage collector.

### `VolumeGcLastStatus`

Specifies the status of the last garbage collection using the specified method in [**REFS_SMR_VOLUME_GC_METHOD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_refs_smr_volume_gc_method).

### `CurrentGcBandFillPercentage`

Specifies the current band fill percentage of the garbage collector.

### `Unused`

Reserved for future use.