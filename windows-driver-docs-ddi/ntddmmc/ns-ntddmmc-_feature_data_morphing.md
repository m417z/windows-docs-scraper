# _FEATURE_DATA_MORPHING structure

## Description

The FEATURE_DATA_MORPHING structure contains information about the morphing feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Asynchronous`

Indicates, when set to 1, that the initiator can request device status asynchronously. If set to zero, the initiator must use polling to request status.

### `OCEvent`

### `Reserved01`

### `Reserved2`

Reserved.

## Remarks

This structure holds data for the feature named "Morphing" by the *MMC-3* specification. Devices that support this feature can notify the initiator of operational changes and allow the initiator to prevent operational changes.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)