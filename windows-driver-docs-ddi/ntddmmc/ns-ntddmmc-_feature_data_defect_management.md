# _FEATURE_DATA_DEFECT_MANAGEMENT structure

## Description

The FEATURE_DATA_DEFECT_MANAGEMENT structure contains information for the Defect Management feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Reserved1`

Reserved.

### `SupplimentalSpareArea`

Indicates, when set to 1, that the logical unit supports the READ DVD STRUCTURE command with a format code of 0Ah. See the *SCSI Multimedia - 4 (MMC-4)* specification for more information.

### `Reserved2`

Reserved.

## Remarks

This structure holds data for the feature named "Defect Management" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature are able to provide contiguous address space that is guaranteed to be defect free.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)