# NVME_CONTEXT_ATTRIBUTES structure

## Description

Specifies optional context attributes for a logical block range (LBA range).

The context attributes specified for each LBA range provides information about how the range is intended to be used by host software. The use of this information is optional and the controller is not required to perform any specific action.

> [!NOTE]
> The controller is required to maintain the integrity of data on the NVM media regardless of whether the attributes provided by host software are accurate.

This structure is used in the **Attributes** field of the [NVME_LBA_RANGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_lba_range) structure, which is used by the Dataset Management command.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.AccessFrequency`

An [NVME_ACCESS_FREQUENCIES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_access_frequencies) value that indicates the access frequency of the LBA range.

### `DUMMYSTRUCTNAME.AccessLatency`

An [NVME_ACCESS_LATENCIES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_access_latencies) value that indicates the access latency of the LBA range.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.SequentialReadRange`

Indicates whether the dataset should be optimized for sequential read access.

When this value is set to `1`, the dataset should be optimized for sequential read access. The host expects to perform operations on the dataset as a single object for reads.

### `DUMMYSTRUCTNAME.SequentialWriteRange`

Indicates whether the dataset should be optimized for sequential write access.

When this value is set to `1`, the dataset should be optimized for sequential write access. The host expects to perform operations on the dataset as a single object for writes.

### `DUMMYSTRUCTNAME.WritePrepare`

Indicates whether the specified LBA range is expected to be written in the near future.

When this value is set to `1`, the provided range is expected to be written in the near future.

### `DUMMYSTRUCTNAME.Reserved1`

### `DUMMYSTRUCTNAME.CommandAccessSize`

Specifies the number of logical blocks that are expected to be transferred in a single Read or Write command from this dataset.

A value of `0h` indicates that no Command Access Size is provided.

### `AsUlong`

## Remarks

## See also