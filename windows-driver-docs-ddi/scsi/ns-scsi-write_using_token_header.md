## Description

The **WRITE_USING_TOKEN_HEADER** structure describes the destination data locations for an offload write data operation. The offload write data operation described by this structure is associated with a token representation of data (ROD).

## Members

### `WriteUsingTokenDataLength`

The length of this structure beginning with the *Immediate* parameter and include all of the elements of the **BlockDeviceRangeDescriptor** array.

### `Immediate`

If set, the status of the WRITE USING TOKEN command is returned immediately after receipt and validation of the token ROD and range descriptors. Otherwise, status is returned after all command processing is complete.

### `Reserved1`

Reserved bits.

### `Reserved2`

Reserved.

### `BlockOffsetIntoToken`

The offset, in logical blocks, in the ROD for **Token** indicating the start of the source data for the offload write data operation.

### `Token`

A token created by a previous the POPULATE TOKEN command operation.

### `Reserved3`

Reserved.

### `BlockDeviceRangeDescriptorListLength`

The length, in bytes, for all of the [**BLOCK_DEVICE_RANGE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-block_device_range_descriptor) structures in the **BlockDeviceRangeDescriptor** array.

### `BlockDeviceRangeDescriptor`

An array of [**BLOCK_DEVICE_RANGE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-block_device_range_descriptor) structures which describe the destination data blocks for the offload write data transfer.

## Remarks

All multibyte values are in big endian format. Prior to setting, these values must be converted from the endian format of the current platform.

## See also

[**BLOCK_DEVICE_RANGE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-block_device_range_descriptor)

[**POPULATE_TOKEN_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-populate_token_header)