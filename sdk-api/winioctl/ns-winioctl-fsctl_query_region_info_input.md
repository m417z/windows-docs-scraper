# FSCTL_QUERY_REGION_INFO_INPUT structure

## Description

Contains the storage tier regions from the storage stack for a particular volume.

## Members

### `Version`

The size of this structure serves as the version. Set it to **sizeof**(**FSCTL_QUERY_REGION_INFO_INPUT**).

### `Size`

The size of this structure in bytes.

### `Flags`

Reserved for future use.

### `NumberOfTierIds`

Number of entries in **TierIds**, 0 to request IDs for the entire volume.

### `TierIds`

Array of storage tiers (represented by GUID values) for which to return information.