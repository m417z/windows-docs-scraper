# _FEATURE_DATA_SECTOR_ERASABLE structure

## Description

The FEATURE_DATA_SECTOR_ERASABLE structure contains information for the Sector Erasable feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

## Remarks

This structure holds data for the feature named "Sector Erasable" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can erase media. These devices also require an erase pass before overwriting existing data.

When queried, devices supporting this feature must return the information indicated in [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header). No other feature-specific information is required.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)