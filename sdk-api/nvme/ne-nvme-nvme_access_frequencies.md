# NVME_ACCESS_FREQUENCIES enumeration

## Description

Defines values that indicate the frequency of read and write access to a Logical Block Addressing (LBA) range.

## Constants

### `NVME_ACCESS_FREQUENCY_NONE`

No frequency information provided.

### `NVME_ACCESS_FREQUENCY_TYPICAL`

The typical number of reads and writes expected for this LBA range.

### `NVME_ACCESS_FREQUENCY_INFR_WRITE_INFR_READ`

Indicates infrequent writes and infrequent reads to the LBA range.

### `NVME_ACCESS_FREQUENCY_INFR_WRITE_FR_READ`

Indicates infrequent writes and frequent reads to the LBA range.

### `NVME_ACCESS_FREQUENCY_FR_WRITE_INFR_READ`

Indicates frequent writes and infrequent reads to the LBA range.

### `NVME_ACCESS_FREQUENCY_FR_WRITE_FR_READ`

Indicates frequent writes and frequent reads to the LBA range.

### `NVME_ACCESS_FREQUENCY_ONE_TIME_READ`

A one time read. For example, the command is due to a virus scan, backup, file copy, or archive.

### `NVME_ACCESS_FREQUENCY_SPECULATIVE_READ`

A speculative read. The command is part of a prefetch operation.

### `NVME_ACCESS_FREQUENCY_WILL_BE_OVERWRITTEN`

The LBA range is going to be overwritten in the near future.

## Remarks

This enumeration is used to specify values in the **AccessFrequency** field of the [NVME_CDW13_READ_WRITE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_read_write) structure and in the **AccessFrequency** field of the [NVME_CONTEXT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_context_attributes) structure.

## See also

[NVME_CDW13_READ_WRITE struct](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_read_write)