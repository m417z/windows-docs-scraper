# _FEATURE_DATA_CD_AUDIO_ANALOG_PLAY structure

## Description

The FEATURE_DATA_CD_AUDIO_ANALOG_PLAY structure holds information about the CD Audio External Play feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `SeperateVolume`

Indicates, when set to zero, that all audio channels have the same volume level. When set to 1, it indicates that the volume of each audio channel can be set separately.

### `SeperateChannelMute`

Indicates, when set to zero, that all audio channels are muted simultaneously. When set to 1, it indicates that each audio channel can be muted independently.

### `ScanSupported`

Indicates, when set to 1, that the SCAN command is supported. See the *SCSI Multimedia 3* (*MMC-3*) specification for a description of the SCAN command.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.

### `NumerOfVolumeLevels`

## Remarks

This structure holds data for the feature named "CD Audio External Play" by the *MMC-3* specification. Devices that support this feature can play CD audio data and channel it directly to an external output.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)