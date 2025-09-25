# _FEATURE_DATA_SMART structure

## Description

The FEATURE_DATA_SMART structure holds data for the S.M.A.R.T. feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `FaultFailureReportingPagePresent`

Indicates, when set to 1, that the device supports the Fault / Failure Reporting Mode. If set to zero, the device does not support this mode.

### `Reserved1`

Reserved.

### `Reserved02`

Reserved.

## Remarks

This structure holds data for the feature named "S.M.A.R.T." by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature support Self-Monitoring Analysis and Reporting Technology (SMART).

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)