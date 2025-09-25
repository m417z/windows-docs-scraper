# _FEATURE_DATA_DVD_READ structure

## Description

The FEATURE_DATA_DVD_READ structure contains information about the DVD Read feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Multi110`

### `Reserved1`

### `Reserved2`

### `DualDashR`

### `Reserved3`

### `Reserved4`

## Remarks

This structure holds data for the feature named "DVD Read" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can read DVD-specific information from the media.

When queried, devices supporting this feature must return the information indicated in [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header). No other feature-specific information is required.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)