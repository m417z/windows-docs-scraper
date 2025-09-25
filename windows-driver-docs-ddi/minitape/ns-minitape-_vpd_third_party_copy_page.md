# _VPD_THIRD_PARTY_COPY_PAGE structure (minitape.h)

## Description

The **VPD_THIRD_PARTY_COPY_PAGE** structure defines the vital product data (VPD) page for offload data transfer operations.

## Members

### `DeviceType`

The device type. This is the same device type defined for use in the inquiry data for the storage device.

### `DeviceTypeQualifier`

A qualifier code for the device. Currently, **DEVICE_CONNECTED**, is the only valid value.

### `PageCode`

The page code for the VPD third party copy page. This page code is defined as 0x8f.

### `PageLength`

The length, in bytes, of the VPD page. For offload data transfer on Windows, **PageLength** must be >= 0x24.

### `ThirdPartyCopyDescriptors`

Support descriptors for copy operations. On Windows systems, **ThirdPartyCopyDescriptors** will contain one descriptor formatted as a [WINDOWS_BLOCK_DEVICE_TOKEN_LIMITS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_windows_block_device_token_limits_descriptor) structure.

## Remarks

All multibyte values are in big endian format. Prior to evaluation, these values must be converted to match the endian format of the current platform.

## See also

[WINDOWS_BLOCK_DEVICE_TOKEN_LIMITS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_windows_block_device_token_limits_descriptor)