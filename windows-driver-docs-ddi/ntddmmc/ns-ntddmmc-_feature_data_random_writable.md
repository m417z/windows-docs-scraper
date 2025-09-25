# _FEATURE_DATA_RANDOM_WRITABLE structure

## Description

The FEATURE_DATA_RANDOM_WRITABLE structure holds information about the Random Writable feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `LastLBA`

Contains the logical block address of the last addressable block on the medium. The bytes of this array are arranged in big-endian order. **LastLBA**[0] contains the most significant byte, and **LastLBA**[3] contains the least significant byte.

### `LogicalBlockSize`

Specifies the number of bytes per logical block. The bytes of this array are arranged in big-endian order. **LogicalBlockSize**[0] contains the most significant byte, and **LogicalBlockSize**[3] contains the least significant byte.

### `Blocking`

Indicates the number of logical blocks per device. The bytes of this array are arranged in big-endian order. **Blocking**[0] contains the most significant byte, and **Blocking**[1] contains the least significant byte.

### `ErrorRecoveryPagePresent`

Indicates, when set to zero, that the Read/Write Error Recovery Mode Page might not be present. See the *SCSI Multimedia -3* (*MMC-3*) specification for an explanation of this page.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.

## Remarks

This structure holds data for the feature named "Random Writable" by the *MMC-3* specification. Devices that support this feature can write blocks of data to random locations on the disk. These devices do not require that the initiator address disk locations in any particular order.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)