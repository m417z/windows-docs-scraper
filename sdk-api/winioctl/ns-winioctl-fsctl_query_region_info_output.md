# FSCTL_QUERY_REGION_INFO_OUTPUT structure

## Description

Contains information for one or more regions.

## Members

### `Version`

The size of this structure serves as the version. Set it to **sizeof**(**FSCTL_QUERY_REGION_INFO_OUTPUT**).

### `Size`

The size of this structure in bytes.

### `Flags`

Reserved for future use.

### `Reserved`

Reserved for future use.

### `Alignment`

Offset from the beginning of the volume to the first slab of the tiered volume. If the logical disk is made up of multiple tiers and each tier maps to a set of regions then the first tier for the volume contained on the logical disk has a certain offset within the tier that represents the offset of the volume on the logical disk. The **Alignment** member contains this value.

### `TotalNumberOfRegions`

Total number of available regions.

### `NumberOfRegionsReturned`

Number of regions that fit in the output.

### `Regions`

[FILE_STORAGE_TIER_REGION](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-file_storage_tier_region) struct that contains detailed information for each region.