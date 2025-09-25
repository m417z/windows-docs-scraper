# _FEATURE_DATA_MRW structure

## Description

The FEATURE_DATA_MRW structure contains information about the MRW feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Write`

Indicates, if set to 1, that the device can format discs using the MRW format and write to discs that have been formatted in this manner. See the *SCSI Multimedia - 4 (MMC-4)* specification for more information.

### `DvdPlusRead`

### `DvdPlusWrite`

### `Reserved01`

### `Reserved2`

Reserved.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)