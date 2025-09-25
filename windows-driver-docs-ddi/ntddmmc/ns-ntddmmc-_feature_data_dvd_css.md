# _FEATURE_DATA_DVD_CSS structure

## Description

The FEATURE_DATA_DVD_CSS structure holds information about the DVD Content Scrambling System (CSS) feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Reserved1`

Reserved.

### `CssVersion`

Must be set to 1.

## Remarks

This structure holds data for the feature named "DVD-CSS" by the *MMC-3* specification. Devices that support this feature can perform DVD Content Scrambling System (DVD-CSS) authentication and key management.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)