# _FEATURE_DATA_DVD_RW_RESTRICTED_OVERWRITE structure

## Description

The FEATURE_DATA_DVD_RW_RESTRICTED_OVERWRITE structure contains information for the Restricted Overwrite feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Blank`

Indicates, when set to 1, that the device supports the BLANK command defined by the *SCSI Multimedia - 4 (MMC-4)* specification, with Blanking Types of zero and one. When set to zero, this bit indicates that the device does not support this command.

### `Intermediate`

Indicates, when set to 1, that the device supports writing on an intermediate state-bordered area and quick formatting (Format Type of 15 - Quick Format, as defined by the *MMC-3* specification). When set to zero, this bit indicates that the device does not support writing on an intermediate state-bordered area nor does it support quick formatting.

### `DefectStatusDataRead`

Corresponds to the Defect Status Bitmap Read (DSBR) bit as defined by the *MMC-3* specification. When set to 1, this bit indicates that the device allows initiators to read the Defect Status Bitmap of a medium. When set to zero, this bit indicates that the device does not support the reading of Defect Status Bitmap.

### `DefectStatusDataGenerate`

Corresponds to the Defect Status Bitmap Generate (DSBG) bit as defined by the *MMC-3* specification. When set to 1, this bit indicates that the device can generate a Defect Status Bitmap during formatting. When set to zero, this bit indicates that the device cannot generate a Defect Status Bitmap during formatting.

### `Reserved0`

Reserved.

### `Reserved1`

Reserved.

## Remarks

This structure holds data for the feature named "DVD-RW Restricted Overwrite" by the *MMC-3* specification. In the [FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number) enumeration, this feature is named **FeatureRigidRestrictedOverwrite**.

Devices that support this feature can only write on block boundaries. These devices cannot perform read or write operations that transfer less than a block of data. See the *MMC-3* specification for more information.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)