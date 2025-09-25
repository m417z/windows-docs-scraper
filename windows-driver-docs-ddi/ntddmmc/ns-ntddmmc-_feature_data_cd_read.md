# _FEATURE_DATA_CD_READ structure

## Description

The FEATURE_DATA_CD_READ structure contains information about the CD Read feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `CDText`

Indicates, when set to 1, that the device supports format code 0x05 of the READ/TOC/PMA/ATIP command, as defined in the *SCSI Multimedia - 4 (MMC-4)* specification. When set to zero, CD-Text is not supported.

### `C2ErrorData`

Indicates, when set to 1, that the device supports the C2 error pointers as described in the *MMC-3* specification. When set to zero, it indicates that the device does not support C2 error pointers.

### `Reserved01`

### `DigitalAudioPlay`

### `Reserved2`

Reserved.

## Remarks

This structure holds data for the feature named "CD Read" by the *MMC-3* specification. Devices that support this feature can read CD-specific information from the media and can read user data from all types of CD blocks.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)