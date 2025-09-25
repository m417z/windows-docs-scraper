# _FEATURE_DATA_REAL_TIME_STREAMING structure

## Description

The FEATURE_DATA_REAL_TIME_STREAMING structure holds information about the Real Time Streaming feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `StreamRecording`

Indicates, when set to 1, that the device supports the stream recording operation. When set to zero, this bit indicates that the device might not support the stream recording operation.

### `WriteSpeedInGetPerf`

Indicates, when set to 1, that the device supports the write speed data of the GET PERFORMANCE command and the WRC field of the SETSTREAMING command.

### `WriteSpeedInMP2A`

Indicates, when set to 1, that the device supports CD/DVD capabilities & mechanical status mode page.

### `SetCDSpeed`

Indicates, when set to 1, that the device supports the SET CD SPEED command. When set to zero, it indicates that the device does not support the SET CD SPEED command.

### `ReadBufferCapacityBlock`

Indicates, when set to 1, that the device supports the READ BUFFERCAPACITY command.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.

## Remarks

This structure holds data for the feature named "Real Time Streaming" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature allow the initiator to specify the performance level of the device within certain limits allowed by the device. These devices must also indicate to the initiator whether they support stream playback operations.

When queried, devices supporting this feature must return the information indicated in [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header). No other feature-specific information is required.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)