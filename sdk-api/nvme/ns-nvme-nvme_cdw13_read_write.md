# NVME_CDW13_READ_WRITE structure

## Description

Contains parameters for the NVME Read and NVME Write commands that read or write data and metadata, if applicable, to and from the NVM controller for the specified Logical Block Addresses (LBA).

This structure is used in the **CDW13** parameter of the **READWRITE** field in the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.DSM`

Indicates attributes for the dataset that the LBAs being read from or written to are associated with.

### `DUMMYSTRUCTNAME.DSM.AccessFrequency`

An [NVME_ACCESS_FREQUENCIES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_access_frequencies) value that specifies the access frequency.

### `DUMMYSTRUCTNAME.DSM.AccessLatency`

An [NVME_ACCESS_LATENCIES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_access_latencies) value that specifies the access latency.

### `DUMMYSTRUCTNAME.DSM.SequentialRequest`

Indicates whether the command is part of a sequential read or write.

For a Read operation, if this value is set to `1`, this command is part of a sequential read that includes multiple Read commands. If the value is cleared to `0`, then no information on sequential access is provided.

For a Write operation, if this value is set to `1`, this command is part of a sequential write that includes multiple Write commands. If the value is cleared to `0`, then no information on sequential access is provided.

### `DUMMYSTRUCTNAME.DSM.Incompressible`

Indicates whether the data is not compressible for the specified logical blocks.

if this value is set to `1`, then data is not compressible for the logical blocks indicated. If the value is cleared to `0`, then no information on compression is provided.

### `DUMMYSTRUCTNAME.Reserved`

### `DUMMYSTRUCTNAME.DSPEC`

A directive specific value.

### `AsUlong`

## Remarks

## See also

- [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command)
- [NVME_CDW12_READ_WRITE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_read_write)
- [NVME_CDW15_READ_WRITE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw15_read_write)