# _FEATURE_DATA_DVD_RECORDABLE_WRITE structure

## Description

The FEATURE_DATA_DVD_RECORDABLE_WRITE structure holds information for the DVD-R/RW Write feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Reserved1`

Reserved.

### `DVD_RW`

Indicates, when set to 1, that the device supports writing and erasing on DVD-RW media. For more information about this feature see the *SCSI Multimedia - 4 (MMC-4)* specification.

### `TestWrite`

Indicates, when set to 1, that the device is capable of performing test writes. When set to zero, the device cannot perform test writes.

### `RDualLayer`

### `Reserved02`

### `BufferUnderrunFree`

Indicates, when set to 1, that the device can perform under-run-free recording.

### `Reserved3`

Reserved.

### `Reserved4`

Reserved.

## Remarks

This structure holds data for the feature named "DVD-R Write" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can write data to a write-once DVD media in "Disc-at-Once" mode.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)