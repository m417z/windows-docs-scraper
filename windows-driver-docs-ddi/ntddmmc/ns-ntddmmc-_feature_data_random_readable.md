# _FEATURE_DATA_RANDOM_READABLE structure

## Description

The FEATURE_DATA_RANDOM_READABLE structure contains data for the random readable feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `LogicalBlockSize`

Indicates the number of bytes per logical block. The bytes of this value are arranged in big-endian order. **LogicalBlockSize**[0] contains the most significant byte, and **LogicalBlockSize**[3] contains the least significant byte.

### `Blocking`

Indicates the number of logical blocks per device-readable unit. The bytes of this value are arranged in big-endian order. **Blocking**[0] contains the most significant byte, and **Blocking**[1] contains the least significant byte.

### `ErrorRecoveryPagePresent`

Indicates, when set to zero, that the read/write error recovery mode page might not be present. When set to 1, it indicates that the error recovery page is present.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.

## Remarks

This structure holds data for the feature named "Random Readable" by the *MMC-3* specification. Devices that support this feature allow the initiator to read blocks of data on the disk at random locations. These devices do not require that the initiator address disk locations in any particular order.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)