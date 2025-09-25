# FEATURE_DATA_CORE structure

## Description

The **FEATURE_DATA_CORE** structure holds data for the feature named "Core" by the *Multimedia Commands - 3 (MMC-3)* specification.

## Members

### `Header`

Contains a [**FEATURE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `PhysicalInterface`

Must be set to the current communication path between initiator and device, as defined in the *Multimedia Commands - 4 (MMC-4)* specification. The bytes of this array are arranged in big-endian order. **PhysicalInterface**[0] contains the most significant byte, and **PhysicalInterface**[3] contains the least significant byte.

### `DeviceBusyEvent`

Value that specifies a *Device Busy Event* Descriptor, as defined in the *Multimedia Commands - 4 (MMC-4)* specification. Device busy events notify the initiator of commands that are executing but that require an abnormally long time to complete.

### `INQUIRY2`

Value that specifies the INQUIRY command operation code, as defined in the *Multimedia Commands - 4 (MMC-4)* specification.

### `Reserved1`

Reserved; do not use.

### `Reserved2`

Reserved; do not use.

## Remarks

The MMC-3 Core feature encompasses the basic functionality which is mandatory for all devices that support the *MMC-3* standard. See the *MMC-3* specification for a description of the capabilities included in the Core feature.

## See also

[**FEATURE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[**FEATURE_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)