# _FEATURE_DATA_DISC_CONTROL_BLOCKS structure

## Description

The FEATURE_DATA_DISC_CONTROL_BLOCKS structure holds an array of the data reported for the Disc Control Block feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Data`

Contains zero, one, or more disk control blocks. Each disk control block is contained in a [FEATURE_DATA_DISC_CONTROL_BLOCKS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_data_disc_control_blocks_ex) structure.

## Remarks

This structure holds data for the feature named "Disc Control Blocks" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can do reads and writes of disc control blocks.

## See also

[FEATURE_DATA_DISC_CONTROL_BLOCKS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_data_disc_control_blocks_ex)

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)