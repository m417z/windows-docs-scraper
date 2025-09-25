# _FEATURE_DATA_CD_MASTERING structure

## Description

The FEATURE_DATA_CD_MASTERING structure holds information for the CD Mastering feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `RWSubchannelsRecordable`

Indicates, when set to 1, that the device can record the R-W subchannels with user-supplied information.

### `CdRewritable`

Indicates, when set to 1, that the device can do mastering and TAO recording on rewritable media.

### `TestWriteOk`

Indicates, when set to 1, that the device can perform test writes.

### `RawRecordingOk`

Indicates, when set to 1, that the device can record using the raw write type.

### `RawMultiSessionOk`

Indicates, when set to 1, that the device can record multisession in raw mode.

### `SessionAtOnceOk`

Indicates, when set to 1, that the device can record using the Session-at-Once recording mode.

### `BufferUnderrunFree`

Indicates, when set to 1, that the device is capable of zero-loss linking.

### `Reserved1`

Reserved.

### `MaximumCueSheetLength`

Indicates the maximum length of a Cue Sheet that can be accepted by the device for Session at Once recording. **MaximumCueSheetLength**[0] holds the most significant byte of the 3-byte value for the length. **MaximumCueSheetLength**[2] holds the least significant byte.

## Remarks

This structure holds data for the feature named "CD Mastering" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can write to a CD in either "Session-at-Once" mode or Raw mode.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)