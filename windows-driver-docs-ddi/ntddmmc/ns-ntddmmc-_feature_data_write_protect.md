# _FEATURE_DATA_WRITE_PROTECT structure

## Description

The FEATURE_DATA_WRITE_PROTECT structure contains information about the Write Protect feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `SupportsSWPPBit`

Indicates, when set to 1, that the device supports set/release PWP status. If additionally **SupportsPersistentWriteProtect** is set to 1, the device supports the SEND DVD STRUCTURE command with Format = 0xC0. For more details on the write protect feature see the *SCSI Multimedia - 4 (MMC-4)* specification.

### `SupportsPersistentWriteProtect`

Indicates, when set to 1, that the device supports the persistent write protect bit of the time-out & protect mode page. For more details on the write protect feature see the *SCSI Multimedia - 4 (MMC-4)* specification.

### `WriteInhibitDCB`

### `DiscWriteProtectPAC`

### `Reserved01`

### `Reserved2`

Reserved.

## Remarks

This structure holds data for the feature named "Write Protect" by the *MMC-3* specification. Devices that support this feature allow the initiator to change the write-protection state of the media programmatically.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)