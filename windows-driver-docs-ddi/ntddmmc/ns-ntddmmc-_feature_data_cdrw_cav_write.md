# _FEATURE_DATA_CDRW_CAV_WRITE structure

## Description

The FEATURE_DATA_CDRW_CAV_WRITE structure contains information about the CD-RW CAV Write feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Reserved1`

Reserved.

## Remarks

This structure holds data for the feature named "CD-RW CAV Write" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can perform writes on CD-RW media in CAV mode.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)