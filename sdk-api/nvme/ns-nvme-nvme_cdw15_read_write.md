# NVME_CDW15_READ_WRITE structure

## Description

Contains parameters for the NVME Read and NVME Write commands that read or write data and metadata, if applicable, to and from the NVM controller for the specified Logical Block Addresses (LBA).

This structure is used in the **CDW15** parameter of the **READWRITE** field in the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.ELBAT`

Specifies the value of the Logical Block Application Tag.

For a Read operation, this field specifies the expected value of the Logical Block Application Tag.
For a Write operation, This field specifies the Logical Block Application Tag value.

This field is only used if the namespace is formatted to use end-to-end protection information.

### `DUMMYSTRUCTNAME.ELBATM`

Specifies the value of the Logical Block Application Tag Mask.

For a Read operation, this field specifies the expected value of the Logical Block Application Tag Mask.
For a Write operation, This field specifies the Logical Block Application Tag Mask value.

This field is only used if the namespace is formatted to use end-to-end protection information.

### `AsUlong`

## Remarks

## See also

- [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command)
- [NVME_CDW12_READ_WRITE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_read_write)
- [NVME_CDW13_READ_WRITE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_read_write)