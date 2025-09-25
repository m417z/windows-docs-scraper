# CLUS_STORAGE_REMAP_DRIVELETTER structure

## Description

Identifies the existing and target drive letter for a disk drive on a node.

## Members

### `CurrentDriveLetterMask`

A 32-bit bitmask indicating the drive letter to be changed. The least significant bit represents the drive letter 'A' through bit 25, which represents the drive letter 'Z'.

### `TargetDriveLetterMask`

A 32-bit bitmask indicating the new drive letter for the disk drive that corresponds to the drive letter specified in CurrentDriveLetterMask.