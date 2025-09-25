# _FEATURE_DATA_CD_TRACK_AT_ONCE structure

## Description

The FEATURE_DATA_CD_TRACK_AT_ONCE structure holds information about the CD Track at Once feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `RWSubchannelsRecordable`

Indicates, when set to 1, that the device can record the read/write subchannels with user-supplied data.

### `CdRewritable`

Indicates, when set to 1, that the device supports overwriting a Track-at-Once track with another track's information.

### `TestWriteOk`

Indicates, when set to 1, that the device can perform test writes.

### `RWSubchannelPackedOk`

Indicates, when set to 1, that the device supports writing R-W sub code in the packed mode.

### `RWSubchannelRawOk`

Indicates, when set to 1, that the device supports writing R-W sub code in the raw mode.

### `Reserved1`

Reserved.

### `BufferUnderrunFree`

Indicates, when set to 1, that the device is capable of zero-loss linking.

### `Reserved3`

Reserved.

### `Reserved2`

Reserved.

### `DataTypeSupported`

Indicates the data types that the device supports. See the *SCSI Multimedia 3* (*MMC-3*) specification for a description of the values that this member can take. **DataTypeSupported**[0] holds the most significant byte of value that indicates the data types. **DataTypeSupported**[1] holds the least significant byte of that value.

## Remarks

This structure holds data for the feature named "CD Track at Once" by the *MMC-3* specification. Devices that support this feature can write data to a CD track.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)