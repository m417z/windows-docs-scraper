# _FEATURE_DATA_DVD_PLUS_RW structure

## Description

The FEATURE_DATA_DVD_PLUS_RW structure contains information about the DVD+RW feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Write`

Indicates, when set to 1, that the device can do background formatting of DVD+RW discs according to *DVD+RW 4.7 Gbytes Basic Format Specifications*, and can write to discs that have been formatted in this manner.

### `Reserved1`

Reserved.

### `CloseOnly`

Indicates, when set to 1, then the device supports only read compatibility stops. When set to 0, the device supports both forms of background format stop. For more information about background format stops, see the *SCSI Multimedia Commands - 4 (MMC-4)* specification published by the American National Standards Institute (ANSI).

### `QuickStart`

### `Reserved02`

### `Reserved03`

## Remarks

This structure holds data for the feature named "DVD+RW" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can read a recorded DVD+RW disc that is formatted according to the *DVD+RW 4.7 Gbytes Basic Format Specification.*

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)