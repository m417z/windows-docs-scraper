# FEATURE_DATA_REMOVABLE_MEDIUM structure

## Description

The **FEATURE_DATA_REMOVABLE_MEDIUM** structure contains data for the removable medium feature.

## Members

### `Header`

Contains a [**FEATURE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Lockable`

Indicates, when set to 1, that the initiator can lock the medium into the device. When set to zero, this bit indicates that the medium cannot be locked into the device.

### `DBML`

### `DefaultToPrevent`

Indicates, when set to zero, that the prevent jumper is present. This overrides the lock command, so that locking the device shall not prevent the insertion of media.

### `Eject`

Indicates, when set to 1, that the device can eject the medium or magazine. When set to zero, this bit indicates that the device cannot eject the medium or magazine by means of the normal start/stop command sequence.

### `Load`

### `LoadingMechanism`

Indicates the type of loading mechanism. See the *SCSI Multimedia - 4 (MMC-4)* specification for the list of values that this member can take.

### `Reserved3[3]`

Reserved.

## Remarks

This structure holds data for the feature named "Removable Medium" by the *MMC-3* specification. Devices that support this feature allow the medium to be removed from the device. They also can communicate to the initiator that the user wants to eject the medium or has inserted a new medium.

## See also

[**FEATURE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[**FEATURE_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)