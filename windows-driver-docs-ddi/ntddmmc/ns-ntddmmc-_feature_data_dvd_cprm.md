# _FEATURE_DATA_DVD_CPRM structure

## Description

The FEATURE_DATA_DVD_CPRM structure holds information about the DVD Content Protection for Recorded Media (CPRM) feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Reserved0`

Reserved.

### `CPRMVersion`

Contains the CPRM version number. Must be set to 1.

## Remarks

This structure holds data for the feature named "DVD CPRM" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can perform DVD Content Protection for Recordable Media (CPRM) authentication and key management.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)