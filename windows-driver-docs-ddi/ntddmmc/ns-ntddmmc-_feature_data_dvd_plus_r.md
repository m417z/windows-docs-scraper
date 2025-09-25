# _FEATURE_DATA_DVD_PLUS_R structure

## Description

The FEATURE_DATA_DVD_PLUS_R structure contains information about the DVD+R feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Write`

Indicates, when set to 1, that the device has an ability that was not specified in the DVD-ROM profile, to write to DVD+R discs according to *DVD+R 4.7 Gbytes Basic Format Specifications.* When set to 0, the device has no extra ability beyond what is specified in the profile.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.

## Remarks

This structure holds data for the feature named "DVD+R" by the *MMC-3* specification. Devices that support this feature can specify whether they are able to perform writes to DVD+R discs, even though this ability was not indicated in the device's DVD-ROM profile.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)