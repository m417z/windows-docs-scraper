# _FEATURE_DATA_FORMATTABLE structure

## Description

The FEATURE_DATA_FORMATTABLE structure contains information for the Formattable feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `FullCertification`

### `QuickCertification`

### `SpareAreaExpansion`

### `RENoSpareAllocated`

### `Reserved1`

### `Reserved2`

### `RRandomWritable`

### `Reserved3`

### `Reserved4`

## Remarks

This structure holds data for the feature named "Formattable" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can format media into logical blocks.

When queried, devices supporting this feature must return the information indicated in [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header). No other feature-specific information is required.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)