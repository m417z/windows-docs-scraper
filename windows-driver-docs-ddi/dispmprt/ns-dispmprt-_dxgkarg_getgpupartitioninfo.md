# _DXGKARG_GETGPUPARTITIONINFO structure

## Description

Arguments used to get physical GPU partition info.

## Members

### `NumGpuPartitionOptions`

On the input this is the size of the pGpuPartitionOptions output array.
On the output this is the number of different ways the GPU could be partitioned.
If the driver supports more options, it needs to return STATUS_BUFFER_TOO_SMALL and set NumGpuPartitionOptions to the number of supported options.

### `pGpuPartitionOptions`

Each element in the array, defines the number partitions the GPU can be divided into.
For example, GPIU could support 4 partitioning options: it could be divided to 2, 4, 8, 32 partitions.

### `CurrentGpuPartitionCount`

The number of partitions, the GPU is currently is configured to support.

## Remarks

## See also