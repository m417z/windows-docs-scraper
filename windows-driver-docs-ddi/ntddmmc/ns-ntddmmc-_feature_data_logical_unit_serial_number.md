# _FEATURE_DATA_LOGICAL_UNIT_SERIAL_NUMBER structure

## Description

The FEATURE_DATA_LOGICAL_UNIT_SERIAL_NUMBER structure holds information about the Device Serial Number feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `SerialNumber`

Contains an array that indicates the serial number of the device in ASCII graphic codes (0x020 through 0x07e).

## Remarks

This structure holds data for the feature named "Device Serial Number" by the *SCSI Multimedia - 4 (MMC-4)* specification. Devices that support this feature can furnish the initiator with a serial number that uniquely identifies the device.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)