# SD_TRANSFER_TYPE enumeration

## Description

The SD_TRANSFER_TYPE enumeration specifies the type of a Secure Digital (SD) data transfer.

## Constants

### `SDTT_UNSPECIFIED`

Unspecified.

### `SDTT_CMD_ONLY`

Indicates that the request involves a transfer of command information or small amounts of data over the CMD line only. It does not involve a data transfer over the DAT lines. This transfer type includes operations such as card selection, the transfer of descriptors during initialization of a card, or the retrieval of a byte of information from a card register.

### `SDTT_SINGLE_BLOCK`

Indicates that the request reads or writes a single block. The I/O block size register specifies the size, in bytes, of a block.

### `SDTT_MULTI_BLOCK`

Indicates that the request reads or writes multiple blocks of data. The I/O block size register specifies the size, in bytes, of a block.

### `SDTT_MULTI_BLOCK_NO_CMD12`

Indicates that the request reads or writes multiple blocks of data. The transfer terminates automatically and does not require termination by a CMD12 command. For a description of the CMD12 command, see the *MultiMedia Card* specification.

## See also

[**SDCMD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ns-sddef-_sdcmd_descriptor)