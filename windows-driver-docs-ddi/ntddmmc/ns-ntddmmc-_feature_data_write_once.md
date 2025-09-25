# _FEATURE_DATA_WRITE_ONCE structure

## Description

The FEATURE_DATA_WRITE_ONCE structure holds information for the Write Once feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `LogicalBlockSize`

Indicates the number of bytes per logical block. The bytes in this array are arranged in big-endian order. **LogicalBlockSize**[0] holds the most significant byte. **LogicalBlockSize**[3] holds the least significant byte.

### `Blocking`

Indicates the number of logical blocks per device. The bytes in this array are arranged in big-endian order. **Blocking**[0] holds the most significant byte. **Blocking**[1] holds the least significant byte.

### `ErrorRecoveryPagePresent`

Indicates, when set to 1, that the Read/Write Error Recovery Mode Page is present. When set to zero, indicates that it might not be present. See the *SCSI Multimedia 3* (*MMC-3*) specification for a description of this page.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.

## Remarks

This structure holds data for the feature named "Write Once" by the *MMC-3* specification. Devices that support this feature can write to any previously unused logical block.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)