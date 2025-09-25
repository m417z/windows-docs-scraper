# FILE_STORAGE_TIER structure

## Description

Represents an identifier for the storage tier relative to the volume.

## Members

### `Id`

Tier ID.

### `Name`

Name for the tier.

### `Description`

Note for the tier.

### `Flags`

The file storage tier flags. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_STORAGE_TIER_FLAG_NO_SEEK_PENALTY**<br><br>0x00020000 | Tier does not suffer a seek penalty on IO operations, which indicates that is an SSD (solid state drive). |

### `ProvisionedCapacity`

Provisioned capacity of the tier.

### `MediaType`

Media type of the tier.

### `Class`

## Remarks

The storage tier ID for a particular volume has no relationship to the storage tier ID with the same value on a different volume.