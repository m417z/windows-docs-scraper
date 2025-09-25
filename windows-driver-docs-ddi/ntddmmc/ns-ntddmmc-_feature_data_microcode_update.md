# _FEATURE_DATA_MICROCODE_UPDATE structure

## Description

The FEATURE_DATA_MICROCODE_UPDATE structure holds information about the Microcode Upgrade feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `M5`

### `Reserved1`

### `Reserved2`

## Remarks

This structure holds data for the feature named "Microcode Upgrade" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can upgrade their internal microcode by means of a published interface.

When queried, devices supporting this feature must return the information indicated in [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header). No other feature-specific information is required.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)