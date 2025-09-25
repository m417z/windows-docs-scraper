# _FEATURE_DATA_EMBEDDED_CHANGER structure

## Description

The FEATURE_DATA_EMBEDDED_CHANGER structure holds data for the Embedded Changer feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Reserved1`

Reserved.

### `SupportsDiscPresent`

Indicates, when set to 1, that the device can report the contents of the slots after a reset or magazine change. When set to zero, this bit indicates that the device can report the contents of the slots after reset or magazine change.

### `Reserved2`

Reserved.

### `SideChangeCapable`

Indicates, when set to 1, that the device is capable of selecting both sides of the media. When set to zero, this bit indicates that the device is not capable of selecting both sides of the media.

### `Reserved3`

Reserved.

### `Reserved4`

Reserved.

### `HighestSlotNumber`

Indicates the number of slots minus 1.

### `Reserved`

Reserved.

## Remarks

This structure holds data for the feature named "Embedded Changer" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can move media back and forth between a media storage area and the mechanism that actually accesses the media.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)