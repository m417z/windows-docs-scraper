# _FEATURE_DATA_TIMEOUT structure

## Description

The FEATURE_DATA_TIMEOUT structure holds information about the Time-Out feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Group3`

### `Reserved1`

### `Reserved2`

### `UnitLength`

## Remarks

This structure holds data for the feature named "Time-Out" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that have this feature must respond to commands within a set time period. When these devices cannot complete commands in the allotted time, they complete the commands with an error.

When queried, devices supporting this feature must return the information indicated in [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header). No other feature-specific information is required.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)