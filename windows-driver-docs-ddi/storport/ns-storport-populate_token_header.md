## Description

A populate token parameter list starts with a **POPULATE_TOKEN_HEADER** structure. This is the header for the parameters in a command data block (CDB) of the POPULATE TOKEN command.

## Members

### `PopulateTokenDataLength`

The length of this structure beginning with the *Immediate* parameter and include all of the elements of the **BlockDeviceRangeDescriptor** array.

### `Immediate`

If set, the status of the POPULATE TOKEN command is returned immediately after receipt and validation of the range descriptors. Otherwise, status is returned after all command processing is complete.

### `Reserved1`

Reserved bits.

### `Reserved2`

Reserved.

### `InactivityTimeout`

The timeout duration for which the copy provider waits for the next command using the token created for this representation of data (ROD). The validity of the token created for the ROD described by this structure expires at this timeout value.

### `Reserved3`

Reserved.

### `BlockDeviceRangeDescriptorListLength`

The length, in bytes, for all of the [**BLOCK_DEVICE_RANGE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-block_device_range_descriptor) structures in the **BlockDeviceRangeDescriptor** array.

### `BlockDeviceRangeDescriptor`

An array of [**BLOCK_DEVICE_RANGE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-block_device_range_descriptor) structures which describe the logical blocks representing the file being read from the LUN.

## Remarks

The **POPULATE_TOKEN_HEADER** structure contains a series of [**BLOCK_DEVICE_RANGE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-block_device_range_descriptor) structures which describe the token ROD.

All multibyte values are in big endian format. Prior to setting, these values must be converted from the endian format of the current platform.

## See also

[**BLOCK_DEVICE_RANGE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-block_device_range_descriptor)