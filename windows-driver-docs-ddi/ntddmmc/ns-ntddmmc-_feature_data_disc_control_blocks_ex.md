# _FEATURE_DATA_DISC_CONTROL_BLOCKS_EX structure

## Description

The FEATURE_DATA_DISC_CONTROL_BLOCKS_EX structure holds the data reported for a Disc Control Block.

## Members

### `ContentDescriptor`

Contains the first of one or more control blocks. The bytes in this array are arranged in big-endian order. **ContentDescriptor**[0] contains the most significant byte, and **ContentDescriptor**[3] contains the least significant byte.

## Remarks

This structure holds data for the feature named "Disc Control Blocks" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can read or write Disc Control Blocks.

## See also

[FEATURE_DATA_DISC_CONTROL_BLOCKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_data_disc_control_blocks)