# FSCTL_QUERY_STORAGE_CLASSES_OUTPUT structure

## Description

Contains information for all tiers of a specific volume.

## Members

### `Version`

The size of this structure serves as the version. Set it to **sizeof**(**FSCTL_QUERY_STORAGE_CLASSES_OUTPUT**).

### `Size`

Size of this structure plus all the variable sized fields.

### `Flags`

The element status. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_STORAGE_TIER_FLAG_NO_SEEK_PENALTY**<br><br>0x00020000 | Tier does not suffer a seek penalty on IO operations, which indicates that is an SSD (solid state drive). |

### `TotalNumberOfTiers`

Total number of available tiers for this disk.

### `NumberOfTiersReturned`

Number of tiers that fit in the output.

### `Tiers`

[FILE_STORAGE_TIER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-file_storage_tier) structure that contains detailed info on the storage tiers.