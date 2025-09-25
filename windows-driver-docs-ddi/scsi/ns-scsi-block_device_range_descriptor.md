## Description

The **BLOCK_DEVICE_RANGE_DESCRIPTOR** structure describes a range of logical blocks associated with various fragments of a file for an offload copy operation.

## Members

### `LogicalBlockAddress`

The starting logical block address of a block range.

### `TransferLength`

The length, in logical blocks, of the block range.

### `Reserved`

Reserved bytes.

## Remarks

If *TransferLength* is set to 0, the range descriptor is considered valid and does not cause an error when included in a token parameter list. No operation will be performed for this descriptor.

All multibyte values are in big endian format. Prior to setting, these values must be converted from the endian format of the current platform.

## See also

[**POPULATE_TOKEN_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-populate_token_header)

[**WRITE_USING_TOKEN_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-write_using_token_header)