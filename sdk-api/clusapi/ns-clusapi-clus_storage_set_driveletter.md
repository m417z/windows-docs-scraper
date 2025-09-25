# CLUS_STORAGE_SET_DRIVELETTER structure

## Description

Supplies drive letter information for a disk partition associated with a storage class resource.

## Members

### `PartitionNumber`

A 32-bit integer that indicates a partition on the storage device.

### `DriveLetterMask`

A 32-bit integer bitmask that indicates either the new drive letter of the partition or that the partition's drive letter should be removed. Each bit represents a drive letter where bit 0 represents 'A', bit 1 represents 'B', and so forth through bit 25. Bits 26 through 31 are ignored. A value of zero indicates that the drive letter should be removed.