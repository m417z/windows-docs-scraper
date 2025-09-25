# NVME_CDW12_READ_WRITE structure

## Description

Contains parameters for the NVME Read and NVME Write commands that read or write data and metadata, if applicable, to and from the NVM controller for the specified Logical Block Addresses (LBA).

This structure is used in the **CDW12** parameter of the **READWRITE** field in the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.NLB`

Indicates the number of logical blocks to be read or written. This is a 0’s based value.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.DTYPE`

A [NVME_DIRECTIVE_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_directive_types) value that indicates the directive type.

### `DUMMYSTRUCTNAME.Reserved1`

### `DUMMYSTRUCTNAME.PRINFO`

A [NVME_PROTECTION_INFORMATION_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_protection_information_types) value that specifies the protection information action and check field.

The NVME Read command may specify protection information to be checked as part of the read operation, and the NVME Write command may specify protection information to include as part of a write operation.

### `DUMMYSTRUCTNAME.FUA`

Indicates whether non-volatile media will be read from or written to.

For a Read operation, this value indicates that the data will be returned from non-volatile media.
For a Write operation, this value indicates that the data will be written to non-volatile media before indicating command completion for a write operation.
There is no implied ordering with other commands.

### `DUMMYSTRUCTNAME.LR`

Indicates whether limited retry will be applied.

For a Read operation, if this value is set to `1`, the controller will apply limited retry efforts. If the value is cleared to `0`, the controller will apply all available error recovery means to return the data to the host.

For a Write operation, if this value is set to `1`, the controller will apply limited retry efforts. If the value is cleared to `0`, the controller will apply all available error recovery means to write the data to the Non-Volatile Memory (NVM).

### `AsUlong`

## Remarks

## See also

- [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command)
- [NVME_CDW13_READ_WRITE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_read_write)
- [NVME_CDW15_READ_WRITE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw15_read_write)